#include "dialogsetup.h"
#include "ui_dialogsetup.h"

DialogSetup::DialogSetup(QWidget *parent) : QDialog(parent), ui(new Ui::DialogSetup)
{
    ui->setupUi(this);
}

DialogSetup::DialogSetup(QWidget *parent, QString* _nickname, QString* _ip, quint16* _port, quint16* _port_server, quint16* _port_client)
    : QDialog(parent), ui(new Ui::DialogSetup)
{
    ui->setupUi(this);

    nickname = _nickname;
    ip = _ip;
    port = _port;
    port_server = _port_server;
    port_client = _port_client;
    QString s_port;
    s_port.setNum(*port);

    QRegExp exp_ip("[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}"); //настройка валидности
    QRegExp exp_port("[0-9]{1,5}");

    ui->line_edit_ip->setText(*ip);
    ui->line_edit_ip->setValidator(new QRegExpValidator(exp_ip, this));
    ui->line_edit_nickname->setText(*nickname);
    ui->line_edit_port->setText(s_port);
    ui->line_edit_port->setValidator(new QRegExpValidator(exp_port, this));

    s_port.setNum(*port_server);
    ui->line_edit_port_server->setText(s_port);
    s_port.setNum(*port_client);
    ui->line_edit_port_client->setText(s_port);

    ui->group_box->setEnabled(false);

    connect(ui->button_ok, SIGNAL(clicked()), this, SLOT(OkClicked()));
    connect(ui->button_cancel, SIGNAL(clicked()), this, SLOT(CancelClicked()));
    connect(ui->check_box, SIGNAL(clicked(bool)), this, SLOT(CheckBoxClicked()));

}

DialogSetup::~DialogSetup()
{
    delete ui;
}

void DialogSetup::OkClicked() //нажатие ок
{
    QFile file_cfg("config.ini");
    if(!file_cfg.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::information(0, "Error", "Can't created config file");
    }
    else
    {
        QTextStream stream(&file_cfg);
        stream << "nickname " << ui->line_edit_nickname->text() << endl;
        stream << "ip " << ui->line_edit_ip->text() << endl;
        stream << "port " << ui->line_edit_port->text() << endl;
        stream << "port_server " << ui->line_edit_port_server->text() << endl;
        stream << "port_client " << ui->line_edit_port_client->text() << endl;

        *nickname = ui->line_edit_nickname->text();
        *ip = ui->line_edit_ip->text();
        *port = ui->line_edit_port->text().toInt();
    }
    file_cfg.close();
    close();
}

void DialogSetup::CancelClicked()//нажатие отмена
{
    close();
}

void DialogSetup::TextLineChanged()//изменение текста
{

}

void DialogSetup::CheckBoxClicked()
{
    bool _enable = ui->check_box->isChecked();
    ui->group_box->setEnabled(_enable);
}

