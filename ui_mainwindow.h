/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mytextedit.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_Alt_F4;
    QAction *action_4;
    QAction *action_5;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_users;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_users;
    QPushButton *button_refresh_users;
    QListWidget *list_users;
    QPushButton *button_send_file;
    QSpacerItem *verticalSpacer;
    QWidget *widget_chat;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *text_chat;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    MyTextEdit *text_message;
    QPushButton *button_copy;
    QPushButton *button_clear;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_send;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *status_bar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(820, 550);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/sphere32.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_Alt_F4 = new QAction(MainWindow);
        action_Alt_F4->setObjectName(QStringLiteral("action_Alt_F4"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QStringLiteral("action_4"));
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QStringLiteral("action_5"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        widget_users = new QWidget(centralWidget);
        widget_users->setObjectName(QStringLiteral("widget_users"));
        widget_users->setMaximumSize(QSize(120, 16777215));
        verticalLayout_3 = new QVBoxLayout(widget_users);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_users = new QLabel(widget_users);
        label_users->setObjectName(QStringLiteral("label_users"));
        label_users->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_3->addWidget(label_users);

        button_refresh_users = new QPushButton(widget_users);
        button_refresh_users->setObjectName(QStringLiteral("button_refresh_users"));
        button_refresh_users->setMaximumSize(QSize(120, 23));

        verticalLayout_3->addWidget(button_refresh_users);

        list_users = new QListWidget(widget_users);
        list_users->setObjectName(QStringLiteral("list_users"));
        list_users->setMaximumSize(QSize(120, 300));

        verticalLayout_3->addWidget(list_users);

        button_send_file = new QPushButton(widget_users);
        button_send_file->setObjectName(QStringLiteral("button_send_file"));

        verticalLayout_3->addWidget(button_send_file);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(widget_users);

        widget_chat = new QWidget(centralWidget);
        widget_chat->setObjectName(QStringLiteral("widget_chat"));
        verticalLayout_2 = new QVBoxLayout(widget_chat);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        text_chat = new QTextEdit(widget_chat);
        text_chat->setObjectName(QStringLiteral("text_chat"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(text_chat->sizePolicy().hasHeightForWidth());
        text_chat->setSizePolicy(sizePolicy);
        text_chat->setMinimumSize(QSize(300, 150));
        text_chat->setContextMenuPolicy(Qt::DefaultContextMenu);
        text_chat->setReadOnly(true);

        verticalLayout_2->addWidget(text_chat);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        text_message = new MyTextEdit(widget_chat);
        text_message->setObjectName(QStringLiteral("text_message"));
        text_message->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(text_message, 0, 1, 2, 1);

        button_copy = new QPushButton(widget_chat);
        button_copy->setObjectName(QStringLiteral("button_copy"));

        gridLayout->addWidget(button_copy, 0, 0, 1, 1);

        button_clear = new QPushButton(widget_chat);
        button_clear->setObjectName(QStringLiteral("button_clear"));

        gridLayout->addWidget(button_clear, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        button_send = new QPushButton(widget_chat);
        button_send->setObjectName(QStringLiteral("button_send"));

        horizontalLayout->addWidget(button_send);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_2->addWidget(widget_chat);

        MainWindow->setCentralWidget(centralWidget);
        widget_chat->raise();
        widget_users->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 820, 18));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        status_bar = new QStatusBar(MainWindow);
        status_bar->setObjectName(QStringLiteral("status_bar"));
        MainWindow->setStatusBar(status_bar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action);
        menu->addSeparator();
        menu->addAction(action_Alt_F4);
        menu_2->addAction(action_4);
        menu_2->addAction(action_5);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MyChat", 0));
        action->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0));
        action_Alt_F4->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264 Alt+F4", 0));
        action_4->setText(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0));
        action_5->setText(QApplication::translate("MainWindow", "\320\236\320\261 \320\260\320\262\321\202\320\276\321\200\320\265", 0));
        label_users->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\270", 0));
        button_refresh_users->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", 0));
        button_send_file->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\264\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", 0));
        button_copy->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0));
        button_clear->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", 0));
        button_send->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\320\224\320\265\320\271\321\201\321\202\320\262\320\270\321\217", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
