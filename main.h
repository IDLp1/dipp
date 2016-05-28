#ifndef MAIN
#define MAIN

#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QtNetwork>
#include <QTimer>
#include <QSound>
#include <QScrollBar>

#include <QDebug>



#define MAX_L_NICKNAME 16
#define MAX_USERS 64

const QString default_nickname = "User";
const QString default_ip = "127.0.0.1";

const QString cs_ask((char)3);
const QString cs_reply((char)5);
const QString cs_del((char)1);

const int default_port = 16925;

quint32 QStringAtIp(const QString* _string);

#endif // MAIN

bool AddUserInList(const QString* _nickname, const QHostAddress* _ip);
void CheckList();
