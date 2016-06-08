#ifndef DIALOGSETUP_H
#define DIALOGSETUP_H

#include <QDialog>
#include "main.h"

namespace Ui {
class DialogSetup;
}

class DialogSetup : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSetup(QWidget *parent = 0);
    explicit DialogSetup(QWidget *parent, QString* _nickname, QString* _ip, quint16* _port, quint16* _port_server, quint16* _port_client);
    ~DialogSetup();

    void SetParam(QString* nickname, QString* _ip, QString* _arrow);

private:
    Ui::DialogSetup *ui;

    QString* nickname;
    QString* ip;
    quint16* port;
    quint16* port_server;
    quint16* port_client;
    bool* is_dialog_setup;
private slots:
    void OkClicked();
    void CancelClicked();
    void TextLineChanged();
    void CheckBoxClicked();
};

#endif // DIALOGSETUP_H
