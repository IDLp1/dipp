#include "user.h"

cUser::cUser()
{
    nickname.clear();
    ip = 0;
    is_exist = false;
    check = false;
}

void cUser::AddUser(const QString *_nickname, const QHostAddress *_ip)
{
    nickname = *_nickname;
    ip = _ip->toIPv4Address();
    is_exist = true;
}

void cUser::DeleteUser()
{
    is_exist = false;
}

bool cUser::IsExist()
{
    return is_exist;
}

quint32 cUser::GetIp()
{
    return ip;
}
