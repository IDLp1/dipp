/****************************************************************************
** Meta object code from reading C++ file 'dialogsendfile.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialogsendfile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogsendfile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DialogSendFile_t {
    QByteArrayData data[11];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogSendFile_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogSendFile_t qt_meta_stringdata_DialogSendFile = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DialogSendFile"
QT_MOC_LITERAL(1, 15, 11), // "EndSendFile"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 10), // "SendSignal"
QT_MOC_LITERAL(4, 39, 8), // "SendFile"
QT_MOC_LITERAL(5, 48, 12), // "SendPartFile"
QT_MOC_LITERAL(6, 61, 14), // "SendStopSignal"
QT_MOC_LITERAL(7, 76, 12), // "ButtonEnable"
QT_MOC_LITERAL(8, 89, 13), // "CancelClicked"
QT_MOC_LITERAL(9, 103, 12), // "StopSendFile"
QT_MOC_LITERAL(10, 116, 15) // "FileSendTimeout"

    },
    "DialogSendFile\0EndSendFile\0\0SendSignal\0"
    "SendFile\0SendPartFile\0SendStopSignal\0"
    "ButtonEnable\0CancelClicked\0StopSendFile\0"
    "FileSendTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogSendFile[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

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

       0        // eod
};

void DialogSendFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DialogSendFile *_t = static_cast<DialogSendFile *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->EndSendFile(); break;
        case 1: _t->SendSignal(); break;
        case 2: _t->SendFile(); break;
        case 3: _t->SendPartFile(); break;
        case 4: _t->SendStopSignal(); break;
        case 5: _t->ButtonEnable(); break;
        case 6: _t->CancelClicked(); break;
        case 7: _t->StopSendFile(); break;
        case 8: _t->FileSendTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DialogSendFile::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DialogSendFile::EndSendFile)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject DialogSendFile::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogSendFile.data,
      qt_meta_data_DialogSendFile,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DialogSendFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogSendFile::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DialogSendFile.stringdata0))
        return static_cast<void*>(const_cast< DialogSendFile*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogSendFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void DialogSendFile::EndSendFile()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
