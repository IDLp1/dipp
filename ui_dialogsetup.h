/********************************************************************************
** Form generated from reading UI file 'dialogsetup.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSETUP_H
#define UI_DIALOGSETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogSetup
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *main_setup_layout;
    QLabel *label_ip;
    QLineEdit *line_edit_ip;
    QLabel *label_2;
    QLineEdit *line_edit_port;
    QLabel *label_name;
    QLineEdit *line_edit_nickname;
    QCheckBox *check_box;
    QGroupBox *group_box;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *line_edit_port_server;
    QLabel *label_3;
    QLineEdit *line_edit_port_client;
    QHBoxLayout *box_layout;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_ok;
    QPushButton *button_cancel;

    void setupUi(QDialog *DialogSetup)
    {
        if (DialogSetup->objectName().isEmpty())
            DialogSetup->setObjectName(QStringLiteral("DialogSetup"));
        DialogSetup->resize(280, 240);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogSetup->sizePolicy().hasHeightForWidth());
        DialogSetup->setSizePolicy(sizePolicy);
        DialogSetup->setMinimumSize(QSize(280, 240));
        DialogSetup->setMaximumSize(QSize(280, 240));
        verticalLayout = new QVBoxLayout(DialogSetup);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        main_setup_layout = new QGridLayout();
        main_setup_layout->setObjectName(QStringLiteral("main_setup_layout"));
        label_ip = new QLabel(DialogSetup);
        label_ip->setObjectName(QStringLiteral("label_ip"));

        main_setup_layout->addWidget(label_ip, 0, 0, 1, 1);

        line_edit_ip = new QLineEdit(DialogSetup);
        line_edit_ip->setObjectName(QStringLiteral("line_edit_ip"));

        main_setup_layout->addWidget(line_edit_ip, 0, 1, 1, 1);

        label_2 = new QLabel(DialogSetup);
        label_2->setObjectName(QStringLiteral("label_2"));

        main_setup_layout->addWidget(label_2, 1, 0, 1, 1);

        line_edit_port = new QLineEdit(DialogSetup);
        line_edit_port->setObjectName(QStringLiteral("line_edit_port"));

        main_setup_layout->addWidget(line_edit_port, 1, 1, 1, 1);

        label_name = new QLabel(DialogSetup);
        label_name->setObjectName(QStringLiteral("label_name"));

        main_setup_layout->addWidget(label_name, 2, 0, 1, 1);

        line_edit_nickname = new QLineEdit(DialogSetup);
        line_edit_nickname->setObjectName(QStringLiteral("line_edit_nickname"));

        main_setup_layout->addWidget(line_edit_nickname, 2, 1, 1, 1);


        verticalLayout->addLayout(main_setup_layout);

        check_box = new QCheckBox(DialogSetup);
        check_box->setObjectName(QStringLiteral("check_box"));

        verticalLayout->addWidget(check_box);

        group_box = new QGroupBox(DialogSetup);
        group_box->setObjectName(QStringLiteral("group_box"));
        gridLayout_2 = new QGridLayout(group_box);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(group_box);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        line_edit_port_server = new QLineEdit(group_box);
        line_edit_port_server->setObjectName(QStringLiteral("line_edit_port_server"));

        gridLayout_2->addWidget(line_edit_port_server, 0, 1, 1, 1);

        label_3 = new QLabel(group_box);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        line_edit_port_client = new QLineEdit(group_box);
        line_edit_port_client->setObjectName(QStringLiteral("line_edit_port_client"));

        gridLayout_2->addWidget(line_edit_port_client, 1, 1, 1, 1);


        verticalLayout->addWidget(group_box);

        box_layout = new QHBoxLayout();
        box_layout->setObjectName(QStringLiteral("box_layout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        box_layout->addItem(horizontalSpacer);

        button_ok = new QPushButton(DialogSetup);
        button_ok->setObjectName(QStringLiteral("button_ok"));

        box_layout->addWidget(button_ok);

        button_cancel = new QPushButton(DialogSetup);
        button_cancel->setObjectName(QStringLiteral("button_cancel"));

        box_layout->addWidget(button_cancel);


        verticalLayout->addLayout(box_layout);


        retranslateUi(DialogSetup);

        QMetaObject::connectSlotsByName(DialogSetup);
    } // setupUi

    void retranslateUi(QDialog *DialogSetup)
    {
        DialogSetup->setWindowTitle(QApplication::translate("DialogSetup", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0));
        label_ip->setText(QApplication::translate("DialogSetup", "IP-\320\260\320\264\321\200\320\265\321\201", 0));
        label_2->setText(QApplication::translate("DialogSetup", "\320\237\320\276\321\200\321\202", 0));
        label_name->setText(QApplication::translate("DialogSetup", "\320\230\320\274\321\217", 0));
        check_box->setText(QApplication::translate("DialogSetup", "\320\240\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\275\321\213\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 TCP", 0));
        group_box->setTitle(QApplication::translate("DialogSetup", "\320\240\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\275\321\213\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 TCP", 0));
        label->setText(QApplication::translate("DialogSetup", "\320\237\320\276\321\200\321\202 \321\201\320\265\321\200\320\262\320\265\321\200\320\260", 0));
        label_3->setText(QApplication::translate("DialogSetup", "\320\237\320\276\321\200\321\202 \320\277\320\276\320\273\321\203\321\207\320\260\321\202\320\265\320\273\321\217", 0));
        button_ok->setText(QApplication::translate("DialogSetup", "\320\236\320\232", 0));
        button_cancel->setText(QApplication::translate("DialogSetup", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogSetup: public Ui_DialogSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSETUP_H
