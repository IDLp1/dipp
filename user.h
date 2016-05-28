#ifndef USER_H
#define USER_H
#include "main.h"

class cUser
{
public:
    cUser();
    void AddUser(const QString* _nickname, const QHostAddress* _ip);
    void DeleteUser();

    bool IsExist();
    quint32 GetIp();
    QString nickname;
    bool check;

private:

    quint32 ip;
    bool is_exist;
};

#endif // USER_H
