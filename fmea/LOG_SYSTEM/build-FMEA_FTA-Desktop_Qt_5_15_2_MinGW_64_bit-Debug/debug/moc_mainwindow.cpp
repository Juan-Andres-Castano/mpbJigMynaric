/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../FMEA_FTA/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[308];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "triggerLogbuffer"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "index"
QT_MOC_LITERAL(4, 35, 16), // "showResponseData"
QT_MOC_LITERAL(5, 52, 13), // "const quint8*"
QT_MOC_LITERAL(6, 66, 6), // "buffer"
QT_MOC_LITERAL(7, 73, 22), // "showResponseDataBuffer"
QT_MOC_LITERAL(8, 96, 27), // "xLaserLogEventDescriptor_t*"
QT_MOC_LITERAL(9, 124, 25), // "pxLaserLogEventDescriptor"
QT_MOC_LITERAL(10, 150, 12), // "processError"
QT_MOC_LITERAL(11, 163, 14), // "processTimeout"
QT_MOC_LITERAL(12, 178, 14), // "transactionLog"
QT_MOC_LITERAL(13, 193, 5), // "Index"
QT_MOC_LITERAL(14, 199, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(15, 221, 15), // "Timer_triggered"
QT_MOC_LITERAL(16, 237, 16), // "Timer2_triggered"
QT_MOC_LITERAL(17, 254, 18), // "on_forward_clicked"
QT_MOC_LITERAL(18, 273, 15), // "on_back_clicked"
QT_MOC_LITERAL(19, 289, 18) // "on_adqData_clicked"

    },
    "MainWindow\0triggerLogbuffer\0\0index\0"
    "showResponseData\0const quint8*\0buffer\0"
    "showResponseDataBuffer\0"
    "xLaserLogEventDescriptor_t*\0"
    "pxLaserLogEventDescriptor\0processError\0"
    "processTimeout\0transactionLog\0Index\0"
    "on_pushButton_clicked\0Timer_triggered\0"
    "Timer2_triggered\0on_forward_clicked\0"
    "on_back_clicked\0on_adqData_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   77,    2, 0x0a /* Public */,
       7,    1,   80,    2, 0x0a /* Public */,
      10,    0,   83,    2, 0x0a /* Public */,
      11,    0,   84,    2, 0x0a /* Public */,
      12,    1,   85,    2, 0x0a /* Public */,
      14,    0,   88,    2, 0x08 /* Private */,
      15,    0,   89,    2, 0x08 /* Private */,
      16,    0,   90,    2, 0x08 /* Private */,
      17,    0,   91,    2, 0x08 /* Private */,
      18,    0,   92,    2, 0x08 /* Private */,
      19,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar,   13,
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
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->triggerLogbuffer((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 1: _t->showResponseData((*reinterpret_cast< const quint8*(*)>(_a[1]))); break;
        case 2: _t->showResponseDataBuffer((*reinterpret_cast< xLaserLogEventDescriptor_t*(*)>(_a[1]))); break;
        case 3: _t->processError(); break;
        case 4: _t->processTimeout(); break;
        case 5: _t->transactionLog((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->Timer_triggered(); break;
        case 8: _t->Timer2_triggered(); break;
        case 9: _t->on_forward_clicked(); break;
        case 10: _t->on_back_clicked(); break;
        case 11: _t->on_adqData_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::triggerLogbuffer)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::triggerLogbuffer(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
