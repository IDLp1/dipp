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
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogSetup
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_ok;
    QPushButton *button_cancel;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_ip;
    QLineEdit *line_edit_ip;
    QLabel *label_2;
    QLineEdit *line_edit_port;
    QLabel *label_name;
    QLineEdit *line_edit_nickname;

    void setupUi(QDialog *DialogSetup)
    {
        if (DialogSetup->objectName().isEmpty())
            DialogSetup->setObjectName(QStringLiteral("DialogSetup"));
        DialogSetup->resize(280, 160);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogSetup->sizePolicy().hasHeightForWidth());
        DialogSetup->setSizePolicy(sizePolicy);
        DialogSetup->setMinimumSize(QSize(280, 160));
        DialogSetup->setMaximumSize(QSize(280, 160));
        layoutWidget = new QWidget(DialogSetup);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 130, 251, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        button_ok = new QPushButton(layoutWidget);
        button_ok->setObjectName(QStringLiteral("button_ok"));

        horizontalLayout->addWidget(button_ok);

        button_cancel = new QPushButton(layoutWidget);
        button_cancel->setObjectName(QStringLiteral("button_cancel"));

        horizontalLayout->addWidget(button_cancel);

        layoutWidget1 = new QWidget(DialogSetup);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(11, 13, 261, 100));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_ip = new QLabel(layoutWidget1);
        label_ip->setObjectName(QStringLiteral("label_ip"));

        gridLayout->addWidget(label_ip, 0, 0, 1, 1);

        line_edit_ip = new QLineEdit(layoutWidget1);
        line_edit_ip->setObjectName(QStringLiteral("line_edit_ip"));

        gridLayout->addWidget(line_edit_ip, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        line_edit_port = new QLineEdit(layoutWidget1);
        line_edit_port->setObjectName(QStringLiteral("line_edit_port"));

        gridLayout->addWidget(line_edit_port, 1, 1, 1, 1);

        label_name = new QLabel(layoutWidget1);
        label_name->setObjectName(QStringLiteral("label_name"));

        gridLayout->addWidget(label_name, 2, 0, 1, 1);

        line_edit_nickname = new QLineEdit(layoutWidget1);
        line_edit_nickname->setObjectName(QStringLiteral("line_edit_nickname"));

        gridLayout->addWidget(line_edit_nickname, 2, 1, 1, 1);


        retranslateUi(DialogSetup);

        QMetaObject::connectSlotsByName(DialogSetup);
    } // setupUi

    void retranslateUi(QDialog *DialogSetup)
    {
        DialogSetup->setWindowTitle(QApplication::translate("DialogSetup", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0));
        button_ok->setText(QApplication::translate("DialogSetup", "\320\236\320\232", 0));
        button_cancel->setText(QApplication::translate("DialogSetup", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
        label_ip->setText(QApplication::translate("DialogSetup", "IP-\320\260\320\264\321\200\320\265\321\201", 0));
        label_2->setText(QApplication::translate("DialogSetup", "\320\237\320\276\321\200\321\202", 0));
        label_name->setText(QApplication::translate("DialogSetup", "\320\230\320\274\321\217", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogSetup: public Ui_DialogSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSETUP_H
