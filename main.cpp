#include "main.h"
#include "mainwindow.h"
#include "user.h"

QString* nickname = new QString;
QString* ip = new QString;
int* port = new int;

cUser* c_user = new cUser[MAX_USERS];


quint32 QStringAtIp(const QString *_string) //перевод строки в ип адрес
{
    QString string = *_string;
    QStringList list = string.split(".");
    QString si[4];
    int i[4];
    for(int j = 0; j < 4; j++)
    {
        si[j] = list.value(j);
        i[j] = si[j].toInt();
    }
    return i[3] + i[2] * 256 + i[1] * 256 * 256 + i[0] * 256 * 256 * 256;
}

bool AddUserInList(const QString *_nickname, const QHostAddress *_ip) //добавление в список пользователей
{
    for(int i = 0; i < MAX_USERS; i++)
    {
        //проверка совпадения ип-адреса
        if(_ip->toIPv4Address() == c_user[i].GetIp())
        {
            c_user[i].check = true;
            return false;
        }
    }
    for(int i = 0; i < MAX_USERS; i++)
    {
        if(!c_user[i].IsExist())
        {
            c_user[i].AddUser(_nickname, _ip);
            c_user[i].check = true;
            return true;
        }
    }
    return false;
}

void CheckList() //проверка состояния сети пользователей
{
    for(int i = 0; i < MAX_USERS; i++)
    {
        if(c_user[i].check)
            c_user[i].check = false;
        else
        {
            if(c_user[i].IsExist())
            {
                c_user[i].DeleteUser();
            }
        }
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile file_cfg("config.ini"); //считывание параметров с файла настройки
    if(!file_cfg.open(QFile::ReadOnly | QFile::Text))
    {
        //создание нового файла настройки с дефолтными настройками
    }
    else
    {
        //считывание параметров с файла настройки config.ini
        QTextStream stream(&file_cfg);
        while(!stream.atEnd())
        {
            QString cmd, param;
            stream.operator >>(cmd);
            stream.operator >>(param);
            if(cmd == "ip")
            {
                *ip = param;
                continue;
            }
            else if(cmd == "nickname")
            {
                *nickname = param;
                continue;
            }
            else if(cmd == "port")
            {
                *port = param.toInt();
            }
            else if(cmd == "") continue;
            else
            {
                //ошибка
                QMessageBox::information(0, "Error", "Config file is corrupt");
                if(nickname->isEmpty()) *nickname = default_nickname;
                if(ip->isEmpty()) *ip = default_ip;
                break;
            }

        }
    }
    *port = default_port;
    file_cfg.flush();
    file_cfg.close();

    //Создание главного окна


    MainWindow* window = new MainWindow(0, nickname, ip, port, c_user);
    //window->SetParam(nickname, ip, chat_arrow);
    window->show();



    return app.exec();
}
