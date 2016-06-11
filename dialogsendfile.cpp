#include "dialogsendfile.h"
#include "ui_dialogsendfile.h"

DialogSendFile::DialogSendFile(QWidget *parent, QTcpSocket* _socket_tcp,
                               QUdpSocket* _socket_udp, QHostAddress _address, quint16* _port, quint16* _port_server) :
    QDialog(parent),
    ui(new Ui::DialogSendFile)
{
    ui->setupUi(this);

    ui->progress_bar->setValue(0);
    ui->progress_bar->setEnabled(false);

    //ui->button_send->setEnabled(false);

    address = _address;
    port = _port;
    port_server = _port_server;
    socket_tcp = _socket_tcp;
    socket_udp = _socket_udp;

    server_tcp = new QTcpServer(this);
    if(!server_tcp->listen(QHostAddress::Any, *port_server))
    {
        QMessageBox::warning(this, "Ошибка", "Не удалось запустить сервер");
    }

    file = new QFile(this);

    file_size = 0; //размер файла
    file_data_send_size = 0; //кол-во передано

    timer_file_send_timeout = new QTimer(this);
    timer_file_send_timeout->setInterval(5000);


    connect(ui->button_cancel, SIGNAL(clicked(bool)), this, SLOT(CancelClicked()));
    connect(ui->button_send, SIGNAL(clicked(bool)), this, SLOT(SendSignal()));
    connect(ui->line_edit_filename, SIGNAL(textChanged(QString)), this, SLOT());
    connect(this, SIGNAL(EndSendFile()), this, SLOT(close()));
    connect(server_tcp, SIGNAL(newConnection()), this, SLOT(SendFile()));
    connect(timer_file_send_timeout, SIGNAL(timeout()), this, SLOT(FileSendTimeout()));
}

DialogSendFile::~DialogSendFile()
{
    delete ui;
}

void DialogSendFile::SendFile() //при newConnection
{
    ui->progress_bar->setEnabled(true);
    ui->progress_bar->setValue(0);

    server_socket_tcp = server_tcp->nextPendingConnection();
    connect(server_socket_tcp, SIGNAL(bytesWritten(qint64)), this, SLOT(SendPartFile()));
    ui->button_cancel->setText("Прервать");
    broadcast = true;
    timer_file_send_timeout->start();
    SendPartFile();
}

void DialogSendFile::SendPartFile()
{
    char block[SIZE_BLOCK_SEND_FILE];
    for(int i(0); i < SIZE_BLOCK_SEND_FILE; i++)
    {
        block[i] = 0;
    }
    if(!file->atEnd() && broadcast)
    {
        quint64 size = file->read(block, sizeof(block));
        file_data_send_size += size;
        timer_file_send_timeout->start();
        if(file_size != 0)
        {
            float r = (float)file_data_send_size / (float)file_size;
            ui->progress_bar->setValue((int)(r * 100.0f));
        }
        else
            ui->progress_bar->setValue(0);
        server_socket_tcp->write(block, size);
    }
    else
    {
        StopSendFile();
        emit EndSendFile();
    }
}

void DialogSendFile::ButtonEnable()
{
    bool _enable = !ui->line_edit_filename->text().isEmpty();
    ui->button_send->setEnabled(_enable);
}

void DialogSendFile::SendSignal()
{
    QString filename = ui->line_edit_filename->text();
    file->setFileName(filename);
    qDebug() << file;
    if(file->open(QFile::ReadOnly))
    {
        file_size = file->size();
        QByteArray buffer;
        QString file_name;
        QFileInfo fi(filename);
        file_name = fi.fileName();
        QDataStream out(&buffer, QIODevice::WriteOnly);
        out << qint64(0);
        out << qint8(TYPE_MSG_SIGNAL_SENDFILE);
        out << address;
        out << file_name;
        out << file->size();
        out.device()->seek(qint64(0));
        out << qint64(buffer.size() - sizeof(qint64));
        socket_udp->writeDatagram(buffer, QHostAddress::Broadcast, *port);
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Указаный файл не найден");
        return;
    }
}

void DialogSendFile::CancelClicked()
{
    if(broadcast)
    {
        broadcast = false;
        ui->button_cancel->setText("Закрыть");
        StopSendFile();
        SendStopSignal();
    }
    else
    {
        close();
    }

}

void DialogSendFile::SendStopSignal()
{
    QByteArray buffer;
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out << qint64(0);
    out << qint8(TYPE_MSG_SIGNAL_STOPSENDFILE);
    out << address;
    out.device()->seek(qint64(0));
    out << qint64(buffer.size() - sizeof(qint64));
    socket_udp->writeDatagram(buffer, QHostAddress::Broadcast, *port);
}

void DialogSendFile::StopSendFile()
{
    if(broadcast)
    {
        broadcast = false;
        ui->button_cancel->setText("Закрыть");
    }
    file->close();
    file_size = 0;
    file_data_send_size = 0;
    disconnect(server_socket_tcp, SIGNAL(bytesWritten(qint64)), this, SLOT(SendPartFile()));
    server_socket_tcp->disconnectFromHost();
    server_tcp->deleteLater();
}

void DialogSendFile::FileSendTimeout()
{
    timer_file_send_timeout->stop();
    if(broadcast)
    {
        QMessageBox::warning(this, "Ошибка", "Таймаут передачи файла");
        broadcast = false;
        StopSendFile();
    }
}
