/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[330];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "IsQueryMessage"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 13), // "ButtonEnabled"
QT_MOC_LITERAL(4, 41, 16), // "ClearMessageText"
QT_MOC_LITERAL(5, 58, 15), // "CopyMessageText"
QT_MOC_LITERAL(6, 74, 15), // "SendMessageText"
QT_MOC_LITERAL(7, 90, 26), // "on_action_Alt_F4_triggered"
QT_MOC_LITERAL(8, 117, 19), // "on_action_triggered"
QT_MOC_LITERAL(9, 137, 12), // "UDPReadyRead"
QT_MOC_LITERAL(10, 150, 12), // "TCPReadyRead"
QT_MOC_LITERAL(11, 163, 21), // "SendMessageWhoIsThere"
QT_MOC_LITERAL(12, 185, 16), // "SendMessageReply"
QT_MOC_LITERAL(13, 202, 15), // "RefreshUserList"
QT_MOC_LITERAL(14, 218, 14), // "AnnounceStatus"
QT_MOC_LITERAL(15, 233, 10), // "CheckUsers"
QT_MOC_LITERAL(16, 244, 16), // "ListUserSelected"
QT_MOC_LITERAL(17, 261, 9), // "PlaySound"
QT_MOC_LITERAL(18, 271, 18), // "OpenDialogSendFile"
QT_MOC_LITERAL(19, 290, 20), // "DisconnectFromServer"
QT_MOC_LITERAL(20, 311, 18) // "ReceiveFileTimeOut"

    },
    "MainWindow\0IsQueryMessage\0\0ButtonEnabled\0"
    "ClearMessageText\0CopyMessageText\0"
    "SendMessageText\0on_action_Alt_F4_triggered\0"
    "on_action_triggered\0UDPReadyRead\0"
    "TCPReadyRead\0SendMessageWhoIsThere\0"
    "SendMessageReply\0RefreshUserList\0"
    "AnnounceStatus\0CheckUsers\0ListUserSelected\0"
    "PlaySound\0OpenDialogSendFile\0"
    "DisconnectFromServer\0ReceiveFileTimeOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  110,    2, 0x08 /* Private */,
       4,    0,  111,    2, 0x08 /* Private */,
       5,    0,  112,    2, 0x08 /* Private */,
       6,    0,  113,    2, 0x08 /* Private */,
       7,    0,  114,    2, 0x08 /* Private */,
       8,    0,  115,    2, 0x08 /* Private */,
       9,    0,  116,    2, 0x08 /* Private */,
      10,    0,  117,    2, 0x08 /* Private */,
      11,    0,  118,    2, 0x08 /* Private */,
      12,    0,  119,    2, 0x08 /* Private */,
      13,    0,  120,    2, 0x08 /* Private */,
      14,    1,  121,    2, 0x08 /* Private */,
      15,    0,  124,    2, 0x08 /* Private */,
      16,    0,  125,    2, 0x08 /* Private */,
      17,    0,  126,    2, 0x08 /* Private */,
      18,    0,  127,    2, 0x08 /* Private */,
      19,    0,  128,    2, 0x08 /* Private */,
      20,    0,  129,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->IsQueryMessage(); break;
        case 1: _t->ButtonEnabled(); break;
        case 2: _t->ClearMessageText(); break;
        case 3: _t->CopyMessageText(); break;
        case 4: _t->SendMessageText(); break;
        case 5: _t->on_action_Alt_F4_triggered(); break;
        case 6: _t->on_action_triggered(); break;
        case 7: _t->UDPReadyRead(); break;
        case 8: _t->TCPReadyRead(); break;
        case 9: _t->SendMessageWhoIsThere(); break;
        case 10: _t->SendMessageReply(); break;
        case 11: _t->RefreshUserList(); break;
        case 12: _t->AnnounceStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->CheckUsers(); break;
        case 14: _t->ListUserSelected(); break;
        case 15: _t->PlaySound(); break;
        case 16: _t->OpenDialogSendFile(); break;
        case 17: _t->DisconnectFromServer(); break;
        case 18: _t->ReceiveFileTimeOut(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::IsQueryMessage)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::IsQueryMessage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
