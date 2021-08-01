/****************************************************************************
** Meta object code from reading C++ file 'UserInterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/UserInterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UserInterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UserInterface_t {
    QByteArrayData data[13];
    char stringdata0[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserInterface_t qt_meta_stringdata_UserInterface = {
    {
QT_MOC_LITERAL(0, 0, 13), // "UserInterface"
QT_MOC_LITERAL(1, 14, 13), // "ZhuxiaoOrExit"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 17), // "OnBtnCloseClicked"
QT_MOC_LITERAL(4, 47, 15), // "OnBtnMinClicked"
QT_MOC_LITERAL(5, 63, 19), // "OnBtnFreShenClicked"
QT_MOC_LITERAL(6, 83, 18), // "OnBtnSearchClicked"
QT_MOC_LITERAL(7, 102, 17), // "OnListBookClicked"
QT_MOC_LITERAL(8, 120, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(9, 137, 21), // "OnCurrentIndexChanged"
QT_MOC_LITERAL(10, 159, 8), // "BookDeal"
QT_MOC_LITERAL(11, 168, 22), // "OnCmbKuCunIndexChanged"
QT_MOC_LITERAL(12, 191, 21) // "OnCmbDateIndexChanged"

    },
    "UserInterface\0ZhuxiaoOrExit\0\0"
    "OnBtnCloseClicked\0OnBtnMinClicked\0"
    "OnBtnFreShenClicked\0OnBtnSearchClicked\0"
    "OnListBookClicked\0QListWidgetItem*\0"
    "OnCurrentIndexChanged\0BookDeal\0"
    "OnCmbKuCunIndexChanged\0OnCmbDateIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   67,    2, 0x08 /* Private */,
       4,    0,   68,    2, 0x08 /* Private */,
       5,    0,   69,    2, 0x08 /* Private */,
       6,    0,   70,    2, 0x08 /* Private */,
       7,    1,   71,    2, 0x08 /* Private */,
       9,    1,   74,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    1,   78,    2, 0x08 /* Private */,
      12,    1,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void UserInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserInterface *_t = static_cast<UserInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ZhuxiaoOrExit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->OnBtnCloseClicked(); break;
        case 2: _t->OnBtnMinClicked(); break;
        case 3: _t->OnBtnFreShenClicked(); break;
        case 4: _t->OnBtnSearchClicked(); break;
        case 5: _t->OnListBookClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->OnCurrentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->BookDeal(); break;
        case 8: _t->OnCmbKuCunIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->OnCmbDateIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UserInterface::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserInterface::ZhuxiaoOrExit)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UserInterface::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UserInterface.data,
      qt_meta_data_UserInterface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UserInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserInterface.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "User"))
        return static_cast< User*>(this);
    return QWidget::qt_metacast(_clname);
}

int UserInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void UserInterface::ZhuxiaoOrExit(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
