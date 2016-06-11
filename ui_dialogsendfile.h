/********************************************************************************
** Form generated from reading UI file 'dialogsendfile.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSENDFILE_H
#define UI_DIALOGSENDFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogSendFile
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *line_edit_filename;
    QVBoxLayout *verticalLayout;
    QLabel *label_text;
    QProgressBar *progress_bar;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_send;
    QPushButton *button_cancel;

    void setupUi(QDialog *DialogSendFile)
    {
        if (DialogSendFile->objectName().isEmpty())
            DialogSendFile->setObjectName(QStringLiteral("DialogSendFile"));
        DialogSendFile->resize(400, 142);
        DialogSendFile->setMinimumSize(QSize(400, 142));
        DialogSendFile->setMaximumSize(QSize(400, 142));
        horizontalLayout_2 = new QHBoxLayout(DialogSendFile);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(DialogSendFile);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        line_edit_filename = new QLineEdit(DialogSendFile);
        line_edit_filename->setObjectName(QStringLiteral("line_edit_filename"));

        verticalLayout_2->addWidget(line_edit_filename);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_text = new QLabel(DialogSendFile);
        label_text->setObjectName(QStringLiteral("label_text"));

        verticalLayout->addWidget(label_text);

        progress_bar = new QProgressBar(DialogSendFile);
        progress_bar->setObjectName(QStringLiteral("progress_bar"));
        progress_bar->setValue(24);

        verticalLayout->addWidget(progress_bar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        button_send = new QPushButton(DialogSendFile);
        button_send->setObjectName(QStringLiteral("button_send"));

        horizontalLayout->addWidget(button_send);

        button_cancel = new QPushButton(DialogSendFile);
        button_cancel->setObjectName(QStringLiteral("button_cancel"));

        horizontalLayout->addWidget(button_cancel);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(verticalLayout_3);


        retranslateUi(DialogSendFile);

        QMetaObject::connectSlotsByName(DialogSendFile);
    } // setupUi

    void retranslateUi(QDialog *DialogSendFile)
    {
        DialogSendFile->setWindowTitle(QApplication::translate("DialogSendFile", "Dialog", 0));
        label->setText(QApplication::translate("DialogSendFile", "\320\237\321\203\321\202\321\214 \320\272 \321\204\320\260\320\271\320\273\321\203", 0));
        label_text->setText(QApplication::translate("DialogSendFile", "\320\237\321\200\320\276\320\263\321\200\320\265\321\201\321\201", 0));
        button_send->setText(QApplication::translate("DialogSendFile", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", 0));
        button_cancel->setText(QApplication::translate("DialogSendFile", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogSendFile: public Ui_DialogSendFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSENDFILE_H
