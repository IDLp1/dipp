#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent, QString* _nickname, QString* _ip, quint16 *_port, quint16* _port_server, quint16* _port_client,  cUser* _user) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    nickname = _nickname;
    ip = _ip;
    port = _port;
    port_server = _port_server;
    port_client = _port_client;
    user = _user;

    socket_udp = new QUdpSocket(this);
    if(!socket_udp->bind(QHostAddress(*_ip), *port))
    {
        QMessageBox::warning(this, "Ошибка", "Невозможно присоединить сокет UDP к порту");
        return;
    }

    socket_tcp = new QTcpSocket(this);
    if(!socket_tcp->bind(QHostAddress(*_ip), *port_client))
    {
        QMessageBox::warning(this, "Ошибка", "Невозможно присоединить сокет TCP к порту");
        return;
    }

    file_receive_size = 0;
    data_file_receive_size = 0;
    broadcast = false;
    file_receive = new QFile(this);



    selected_user = new QHostAddress;


    timer_check_users = new QTimer(this);
    timer_check_users->setInterval(3000); //интервал проверки пользователей
    timer_check_users->start();

    timer_file_receive_timeout = new QTimer(this);
    timer_file_receive_timeout->setInterval(5000); //тайм-аут при приеме файла

    ui->button_clear->setEnabled(false);
    ui->button_copy->setEnabled(false);
    ui->button_send->setEnabled(false);
    ui->button_send->setDefault(true);

    ui->button_send_private->setEnabled(false);
    ui->button_send_file->setEnabled(false);

    connect(ui->text_message, SIGNAL(textChanged()), this, SLOT(ButtonEnabled())); //включение кнопок
    connect(ui->text_message, SIGNAL(PressEnter()), this, SLOT(SendMessageText()));
    connect(ui->button_clear, SIGNAL(clicked()), this, SLOT(ClearMessageText())); //кнопка очистить
    connect(ui->button_copy, SIGNAL(clicked()), this, SLOT(CopyMessageText())); //кнопка копировать
    connect(ui->button_send, SIGNAL(clicked()), this, SLOT(SendMessageText())); //кнопка отправить
    connect(ui->button_refresh_users, SIGNAL(clicked()), this, SLOT(SendMessageWhoIsThere())); //кнопка обновить
    connect(ui->button_refresh_users, SIGNAL(clicked()), this, SLOT(RefreshUserList())); //кнопка обновить
    connect(ui->button_send_file, SIGNAL(clicked(bool)), this, SLOT(OpenDialogSendFile()));
    connect(socket_udp, SIGNAL(readyRead()), this, SLOT(UDPReadyRead())); //получение сообщения
    connect(socket_tcp, SIGNAL(readyRead()), this, SLOT(TCPReadyRead())); //получение файла
    connect(timer_check_users, SIGNAL(timeout()), this, SLOT(CheckUsers()));//проверка пользователей каждые n секунд
    connect(timer_file_receive_timeout, SIGNAL(timeout()), this, SLOT(ReceiveFileTimeOut()));//таймаут передачи файла
    connect(ui->list_users, SIGNAL(itemSelectionChanged()), this, SLOT(ListUserSelected()));//сигнал выделения пользователя
    connect(this, SIGNAL(IsQueryMessage()), SLOT(SendMessageReply()));//ответ на запрос "кто здесь?"


    //SendMessageWhoIsThere();
    AnnounceStatus(STATUS_CONNECT);

    ui->status_bar->showMessage("v0.2");
}

void MainWindow::ButtonEnabled()
{
    //QString str = ui->text_message->toPlainText();
    bool _enable = !ui->text_message->toPlainText().isEmpty();
    ui->button_clear->setEnabled(_enable);
    ui->button_copy->setEnabled(_enable);
    ui->button_send->setEnabled(_enable);
}

void MainWindow::ClearMessageText()
{
    ui->text_message->clear();
}

void MainWindow::CopyMessageText()
{
    ui->text_message->selectAll();
    ui->text_message->copy();
}

void MainWindow::SendMessageText() // Отправить текст.......................
{
    if(!ui->text_message->toHtml().isEmpty())
    {
        QByteArray buffer;
        QDataStream out(&buffer, QIODevice::WriteOnly);
        out << qint64(0);
        out << qint8(TYPE_MSG_CHAT);
        out << *nickname;
        out << ui->text_message->toHtml();
        out.device()->seek(qint64(0));
        out << qint64(buffer.size() - sizeof(qint64));
        socket_udp->writeDatagram(buffer, QHostAddress::Broadcast, *port);
        ui->text_message->clear();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
    QMessageBox box;
    box.setText("1");
    box.exec();
*/

void MainWindow::on_action_Alt_F4_triggered() //настройки-выход
{
    close();
}

void MainWindow::on_action_triggered() //действие-настройки
{
    DialogSetup* dialog_setup = new DialogSetup(this, nickname, ip, port, port_server, port_client);
    dialog_setup->show();
    dialog_setup->exec();
}

void MainWindow::UDPReadyRead() //Прочитать датаграмму UDP
{
    while(socket_udp->pendingDatagramSize() != -1)
    {
        QByteArray buffer;
        buffer.resize(socket_udp->pendingDatagramSize());
        QHostAddress sender_address;
        quint16 sender_port;
        socket_udp->readDatagram(buffer.data(), buffer.size(), &sender_address, &sender_port);

        QDataStream in(&buffer, QIODevice::ReadOnly);
        qint64 size = -1;
        if(in.device()->size() > sizeof(qint64)) //проверка размера
        {
            in >> size;
        }
        else
        {
            ui->status_bar->showMessage("UDP пакет с ошибкой");
            return;
        }
        if(in.device()->size() - sizeof(qint64) < size)
        {
            ui->status_bar->showMessage("UDP пакет с ошибкой");
            return;
        }
        qint8 type = 0;
        in >> type;//типы сообщения
        if(type == TYPE_MSG_CHAT) //обычное сообщение в чат
        {
            QString nick, msg;
            in >> nick;
            in >> msg;
            ui->text_chat->setText(ui->text_chat->toHtml() + "<b><font color = blue>" + nick + "</font></b>" + msg + "\n");
            ui->text_chat->verticalScrollBar()->setSliderPosition(16777215);
            PlaySound();
        }
        else if(type == TYPE_MSG_QUERY) //сообщение-вопрос "кто здесь?"
        {
            emit IsQueryMessage();
        }
        else if(type == TYPE_MSG_REPLY) //сообщение ответ на "кто здесь?"
        {
            QString nick;
            in >> nick;
            AddUserInList(&nick, &sender_address);
        }
        else if(type == TYPE_MSG_STATUS) //уведомление о статусе пользователя
        {
            quint8 status;
            QString nick;
            in >> status;
            in >> nick;
            if(status == STATUS_CONNECT)
                ui->text_chat->setText(ui->text_chat->toHtml() + "<font color = blue><b>" + nick  + " подключен " + "</b></font>");
            else if(status == STATUS_DISCONNECT)
                ui->text_chat->setText(ui->text_chat->toHtml() + "<font color = blue><b>" + nick  + " отключен "+ "</b></font>");
            else if(status == STATUS_SLEEP)
                ui->text_chat->setText(ui->text_chat->toHtml() + "<font color = blue><b>" + nick  + " простаивает"+ "</b></font>");
        }
        else if(type == TYPE_MSG_SIGNAL_SENDFILE) //сигнал о передаче файла
        {
            QHostAddress address;
            in >> address;
            if(address == QHostAddress(*ip)) //если ип совпадает
            {
                socket_tcp->disconnectFromHost();
                QString file_name;
                in >> file_name;
                in >> file_receive_size;
                socket_tcp->connectToHost(sender_address, *port_client);
                if(socket_tcp->waitForConnected(5000))
                {
                    ui->status_bar->showMessage("Получение файла: Подключен к серверу для получения файла");
                    broadcast = true;
                    timer_file_receive_timeout->start();
                    QString save_path = "Downloads/";
                    QDir dir;
                    dir.mkpath(save_path);
                    file_receive->setFileName(save_path + file_name);
                    if(!file_receive->open(QIODevice::WriteOnly))
                        ui->status_bar->showMessage("Ошибка получения файла: Невозможно создать файл для записи");
                }
                else
                {
                    ui->status_bar->showMessage("Ошибка получения файла: Не удалось подключится к серверу");
                    return;
                }
            }
        }
        else if(type == TYPE_MSG_SIGNAL_STOPSENDFILE) //стоп сигнал
        {
            QHostAddress address;
            in >> address;
            if(address == QHostAddress(*ip))
            {
                ui->status_bar->showMessage("Получение файла: Передача прервана");
                DisconnectFromServer();
            }
        }
    }
}

void MainWindow::TCPReadyRead()//прием файла
{
    if(broadcast)
    {
        char block[SIZE_BLOCK_SEND_FILE];
        QDataStream in(socket_tcp);
        while(!in.atEnd())
        {
            int size = in.readRawData(block, sizeof(block));
            data_file_receive_size += size;
            file_receive->write(block, size);
            float status = (float)data_file_receive_size / (float)file_receive_size * 100.0f;
            ui->status_bar->showMessage("Получение файла: " + QString::number(data_file_receive_size) + " | " + QString::number(file_receive_size));
            timer_file_receive_timeout->start();
        }
        if(data_file_receive_size == file_receive_size)
        {
            DisconnectFromServer();
            ui->status_bar->showMessage("Получение файла: Файл получен");
        }
        else if(data_file_receive_size > file_receive_size)
        {
            ui->status_bar->showMessage("Получение файла: Ошибка - получено больше ожидаемого байтов");
            DisconnectFromServer();
        }
    }
}

void MainWindow::SendMessageWhoIsThere() //Отправить сообщение "кто здесь?"
{
    QByteArray buffer;
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out << qint64(0);
    out << qint8(TYPE_MSG_QUERY);
    out.device()->seek(qint64(0));
    out << qint64(buffer.size() - sizeof(qint64));
    socket_udp->writeDatagram(buffer, QHostAddress::Broadcast, *port);
}

void MainWindow::SendMessageReply()//отправить ответ
{
    QByteArray buffer;
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out << qint64(0);
    out << qint8(TYPE_MSG_REPLY);
    out << *nickname;
    out.device()->seek(qint64(0));
    out << qint64(buffer.size() - sizeof(qint64));
    socket_udp->writeDatagram(buffer, QHostAddress::Broadcast, *port);
}

void MainWindow::RefreshUserList()
{
    ui->list_users->clear();
    for(int i = 0; i < MAX_USERS; i++)
    {
        if(user[i].IsExist())
        {
            QString s_ip;
            QHostAddress adr;
            adr.setAddress(user[i].GetIp());
            s_ip = adr.toString();
            ui->list_users->addItem(user[i].nickname + "-" + s_ip);
        }
    }
}

void MainWindow::AnnounceStatus(int _status)
{
    QByteArray buffer;
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out << qint64(0);
    out << qint8(TYPE_MSG_STATUS);
    out << qint8(_status);
    out << *nickname;
    out.device()->seek(qint64(0));
    out << qint64(buffer.size() - sizeof(qint64));
    socket_udp->writeDatagram(buffer, QHostAddress::Broadcast, *port);
}

void MainWindow::CheckUsers()
{
    static bool check;
    if(check)
        CheckList();
    else
        SendMessageWhoIsThere();
    check = !check;
}

void MainWindow::PlaySound()
{
    QSound::play(":/sound/msg.wav");
}

void MainWindow::ListUserSelected()
{
    QString s = ui->list_users->currentItem()->text();
    QStringList list = s.split("-");
    s.clear();
    s = list.value(1);
    QHostAddress address(s);
    *selected_user = address;
    ui->button_send_file->setEnabled(true);
}

void MainWindow::OpenDialogSendFile()
{
    DialogSendFile* dialog_send_file = new DialogSendFile(this, socket_tcp, socket_udp, *selected_user, port, port_server);
    dialog_send_file->show();
    dialog_send_file->exec();
}

void MainWindow::DisconnectFromServer()
{
    file_receive->close();
    data_file_receive_size = 0;
    socket_tcp->disconnectFromHost();
    broadcast = false;
}

void MainWindow::ReceiveFileTimeOut()
{
    if(broadcast)
    {
        DisconnectFromServer();
        ui->status_bar->showMessage("Передача файла: Таймаут приема файла");
    }
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    AnnounceStatus(STATUS_DISCONNECT);
}
