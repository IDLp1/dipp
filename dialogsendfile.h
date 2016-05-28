#ifndef DIALOGSENDFILE_H
#define DIALOGSENDFILE_H

#include <QDialog>
#include "main.h"
#include "mainwindow.h"

#define SIZE_BLOCK_SEND_FILE 256

namespace Ui {
class DialogSendFile;
}

class DialogSendFile : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSendFile(QWidget *parent, QTcpServer* _server_tcp, QTcpSocket* _socket_tcp, QUdpSocket* _socket_udp, QHostAddress _address, int* _port);
    ~DialogSendFile();

private:
    Ui::DialogSendFile *ui;
    QHostAddress address;
    int* port;
    QTcpSocket* socket_tcp;
    QTcpServer* server_tcp;
    QUdpSocket* socket_udp;
    QFile*      file;

    qint64 file_size;
    qint64 file_flopover;
private slots:
    void SendSignal();
    void SendFile();
    void SendPartFile();
    void ButtonEnable();
signals:
    void EndSendFile();
};

#endif // DIALOGSENDFILE_H
