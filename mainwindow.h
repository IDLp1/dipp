#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "main.h"
#include "dialogsetup.h"
#include "dialogsendfile.h"
#include "user.h"

#define TYPE_MSG_CHAT       0
#define TYPE_MSG_QUERY      1
#define TYPE_MSG_REPLY      2
#define TYPE_MSG_STATUS     3
#define TYPE_MSG_SIGNAL_SENDFILE 4
#define STATUS_CONNECT      0
#define STATUS_DISCONNECT   1
#define STATUS_SLEEP        2

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent, QString* _nickname, QString* _ip, int* _port, cUser* _user);
    ~MainWindow();

    //void SetParam(QString* _nickname, QString* _ip, QString* _arrow);

private:
    Ui::MainWindow *ui;
    QString* nickname;
    QString* ip;
    int* port;
    cUser* user;
    QUdpSocket* socket_udp;
    QTcpSocket* socket_tcp;
    QTcpServer* server_tcp;
    QTimer* timer_check_users;
    QHostAddress* selected_user;
    QFile* file_receive;
    qint64 file_receive_size;
    qint64 data_receive_size;

private slots:
    void ButtonEnabled();
    void ClearMessageText();
    void CopyMessageText();
    void SendMessageText();
    void on_action_Alt_F4_triggered();
    void on_action_triggered();
    void UDPReadyRead();
    void TCPReadyRead();
    void SendMessageWhoIsThere();
    void SendMessageReply();
    void RefreshUserList();
    void AnnounceStatus(int);
    void CheckUsers();
    void ListUserSelected();
    void PlaySound();
    void OpenDialogSendFile();
signals:
    void IsQueryMessage();
};

#endif // MAINWINDOW_H
