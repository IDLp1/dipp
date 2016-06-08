#include "main.h"
#include "mainwindow.h"
#include "user.h"

QString* nickname = new QString;
QString* ip = new QString;
quint16* port = new quint16;
quint16* port_server = new quint16;
quint16* port_client = new quint16;

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
            c_user[i].AddUser(_nickname, _ip);
            return true;
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
    qDebug() << 123;
    *port = default_port; //установка портов по дефолту
    *port_server = default_port;
    *port_client = default_port;
    *ip = default_ip;
    *nickname = default_nickname;

    QFile file_cfg("config.ini"); //считывание параметров с файла настройки
    if(!file_cfg.open(QFile::ReadOnly | QFile::Text))
    {
        //создание нового файла настройки с дефолтными настройками
        if(!file_cfg.open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::warning(0, "Ошибка", "Невозможно создать файл настройки");
        }
        else
        {
            QTextStream stream(&file_cfg);
            stream.operator << ("name ");
            stream.operator << (default_nickname);
            stream.operator << ("\nip ");
            stream.operator << (default_ip);
            stream.operator << ("\nport ");
            stream.operator << (default_port);
            stream.operator << ("\nport_server ");
            stream.operator << (default_port);
            stream.operator << ("\nport_client ");
            stream.operator << (default_port);
            file_cfg.close();
        }
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
            else if(cmd == "port_server")
            {
                *port_server = param.toInt();
            }
            else if(cmd == "port_client")
            {
                *port_client = param.toInt();
            }
            else if(cmd == "") continue;
            else
            {
                //ошибка
                QMessageBox::information(0, "Error", "Config file is corrupt");
                if(nickname->isEmpty()) *nickname = default_nickname; 
                break;
            }

        }
    }
    file_cfg.flush();
    file_cfg.close();

    //Создание главного окна


    MainWindow* window = new MainWindow(0, nickname, ip, port, port_server, port_client, c_user);
    //window->SetParam(nickname, ip, chat_arrow);
    window->show();



    return app.exec();
}
