/****************************************************************************
** Meta object code from reading C++ file 'FilterWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FilterWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FilterWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FilterWidget_t {
    QByteArrayData data[11];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FilterWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FilterWidget_t qt_meta_stringdata_FilterWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FilterWidget"
QT_MOC_LITERAL(1, 13, 10), // "FilterDone"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "Filters"
QT_MOC_LITERAL(4, 33, 16), // "CustomFilterDone"
QT_MOC_LITERAL(5, 50, 7), // "Filter*"
QT_MOC_LITERAL(6, 58, 12), // "updateFilter"
QT_MOC_LITERAL(7, 71, 5), // "value"
QT_MOC_LITERAL(8, 77, 15), // "useCustomFilter"
QT_MOC_LITERAL(9, 93, 7), // "toggled"
QT_MOC_LITERAL(10, 101, 12) // "selectFilter"

    },
    "FilterWidget\0FilterDone\0\0Filters\0"
    "CustomFilterDone\0Filter*\0updateFilter\0"
    "value\0useCustomFilter\0toggled\0"
    "selectFilter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FilterWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   45,    2, 0x0a /* Public */,
       8,    1,   48,    2, 0x0a /* Public */,
      10,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,

       0        // eod
};

void FilterWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FilterWidget *_t = static_cast<FilterWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->FilterDone((*reinterpret_cast< Filters(*)>(_a[1]))); break;
        case 1: _t->CustomFilterDone((*reinterpret_cast< Filter*(*)>(_a[1]))); break;
        case 2: _t->updateFilter((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->useCustomFilter((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->selectFilter((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Filter* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FilterWidget::*_t)(Filters );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FilterWidget::FilterDone)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FilterWidget::*_t)(Filter * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FilterWidget::CustomFilterDone)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject FilterWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FilterWidget.data,
      qt_meta_data_FilterWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FilterWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FilterWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FilterWidget.stringdata0))
        return static_cast<void*>(const_cast< FilterWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int FilterWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void FilterWidget::FilterDone(Filters _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FilterWidget::CustomFilterDone(Filter * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
