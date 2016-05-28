#include "dialogsetup.h"
#include "ui_dialogsetup.h"

DialogSetup::DialogSetup(QWidget *parent) : QDialog(parent), ui(new Ui::DialogSetup)
{
    ui->setupUi(this);
}

DialogSetup::DialogSetup(QWidget *parent, QString* _nickname, QString* _ip, int* _port)
    : QDialog(parent), ui(new Ui::DialogSetup)
{
    ui->setupUi(this);

    nickname = _nickname;
    ip = _ip;
    port = _port;
    QString s_port;
    s_port.setNum(*port);
    ui->line_edit_port->setText(s_port);
    ui->line_edit_ip->setText(*ip);
    ui->line_edit_nickname->setText(*nickname);

    connect(ui->button_ok, SIGNAL(clicked()), this, SLOT(OkClicked()));
    connect(ui->button_cancel, SIGNAL(clicked()), this, SLOT(CancelClicked()));

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
        stream << "ip " << ui->line_edit_ip->text() << endl;
        stream << "port " << ui->line_edit_port->text() << endl;
        stream << "nickname " << ui->line_edit_nickname->text() << endl;


        *nickname = ui->line_edit_nickname->text();
        *ip = ui->line_edit_ip->text();
        *port = ui->line_edit_port->text().toInt();
    }
    close();
}

void DialogSetup::CancelClicked()//нажатие отмена
{
    close();
}

void DialogSetup::TextLineChanged()//изменение текста
{

}

