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
#define TYPE_MSG_SIGNAL_STOPSENDFILE 5
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
    explicit MainWindow(QWidget *parent, QString* _nickname, QString* _ip, quint16* _port, quint16* _port_server, quint16* port_client, cUser* _user);
    ~MainWindow();

    //void SetParam(QString* _nickname, QString* _ip, QString* _arrow);
private:
    Ui::MainWindow *ui;
    QString*        nickname;
    QString*        ip;
    quint16*        port;
    quint16*        port_server;
    quint16*        port_client;
    cUser*          user;
    QUdpSocket*     socket_udp;
    QTcpSocket*     socket_tcp;
    //QTcpServer*     server_tcp;

    QTimer*         timer_check_users;
    QTimer*         timer_file_receive_timeout;

    QHostAddress*   selected_user;

    QFile*          file_receive;
    qint64          file_receive_size;
    qint64          data_file_receive_size;
    bool            broadcast;
protected:
    void closeEvent(QCloseEvent *);
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
    void DisconnectFromServer();
    void ReceiveFileTimeOut();
signals:
    void IsQueryMessage();
};



#endif // MAINWINDOW_H
