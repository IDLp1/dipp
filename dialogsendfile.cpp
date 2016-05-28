#include "dialogsendfile.h"
#include "ui_dialogsendfile.h"

DialogSendFile::DialogSendFile(QWidget *parent, QTcpServer* _server_tcp, QTcpSocket* _socket_tcp, QUdpSocket *_socket_udp, QHostAddress _address, int* _port) :
    QDialog(parent),
    ui(new Ui::DialogSendFile)
{
    ui->setupUi(this);

    ui->progress_bar->setValue(0);
    ui->progress_bar->setEnabled(false);

    //ui->button_send->setEnabled(false);

    address = _address;
    port = _port;
    socket_tcp = _socket_tcp;
    socket_udp = _socket_udp;
    server_tcp = _server_tcp;

    file_size = 0;
    file_flopover = 0;

    connect(ui->button_cancel, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(ui->button_send, SIGNAL(clicked(bool)), this, SLOT(SendSignal()));
    connect(ui->line_edit_filename, SIGNAL(textChanged(QString)), this, SLOT());
    connect(this, SIGNAL(EndSendFile()), this, SLOT(close()));
    connect(server_tcp, SIGNAL(newConnection()), this, SLOT(SendFile()));

}

DialogSendFile::~DialogSendFile()
{
    delete ui;
}

void DialogSendFile::SendFile()
{
    socket_tcp = server_tcp->nextPendingConnection();
    ui->progress_bar->setEnabled(true);
   /* QByteArray buffer;
    QDataStream out(&buffer, QIODevice::WriteOnly);
    //
    socket_tcp->write(buffer);
    socket_tcp->waitForBytesWritten();*/
    connect(socket_tcp, SIGNAL(bytesWritten(qint64)), this, SLOT(SendPartFile()));
    SendPartFile();
}

void DialogSendFile::SendPartFile()
{
    char block[SIZE_BLOCK_SEND_FILE];
    if(!file->atEnd())
    {
        qint64 in = file->read(block, sizeof(block));
        qint64 send = socket_tcp->write(block, in);
        file_flopover += send;
        float ff = file_flopover / file_size;
        ui->progress_bar->setValue(qint64(ff));
    }
    else //конец файла
    {
        file->close();
        file = NULL;
        file_size = 0;
        file_flopover = 0;
        disconnect(socket_tcp, SIGNAL(bytesWritten(qint64)), this, SLOT(SendPartFile()));
        ui->progress_bar->setEnabled(false);
        QMessageBox::information(this, "Файл", "Передача файла завершена");
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
    file = new QFile(filename);
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
