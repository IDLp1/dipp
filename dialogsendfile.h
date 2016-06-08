#ifndef DIALOGSENDFILE_H
#define DIALOGSENDFILE_H

#include <QDialog>
#include "main.h"
#include "mainwindow.h"

#define SIZE_BLOCK_SEND_FILE 1024

namespace Ui {
class DialogSendFile;
}

class DialogSendFile : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSendFile(QWidget *parent, QTcpSocket* _socket_tcp,
                            QUdpSocket* _socket_udp, QHostAddress _address, quint16* _port, quint16* _port_server);
    ~DialogSendFile();

private:
    Ui::DialogSendFile *ui;
    QHostAddress address;
    quint16* port;
    quint16* port_server;
    quint16* port_client;
    QTcpSocket* socket_tcp;
    QTcpServer* server_tcp;
    QTcpSocket* server_socket_tcp;
    QUdpSocket* socket_udp;
    QFile*      file;

    qint64 file_size;
    qint64 file_data_send_size;

    QTimer*  timer_file_send_timeout;

    bool broadcast;

private slots:
    void SendSignal();
    void SendFile();
    void SendPartFile();
    void SendStopSignal();
    void ButtonEnable();
    void CancelClicked();
    void StopSendFile();
    void FileSendTimeout();
signals:
    void EndSendFile();
};

#endif // DIALOGSENDFILE_H
