/****************************************************************************
** Meta object code from reading C++ file 'qrcodebatchgenerator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qrcodebatchgenerator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qrcodebatchgenerator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QRcodeBatchGenerator_t {
    QByteArrayData data[11];
    char stringdata[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QRcodeBatchGenerator_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QRcodeBatchGenerator_t qt_meta_stringdata_QRcodeBatchGenerator = {
    {
QT_MOC_LITERAL(0, 0, 20), // "QRcodeBatchGenerator"
QT_MOC_LITERAL(1, 21, 25), // "on_btnGenerateOne_clicked"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 29), // "on_pushButtonGenerate_clicked"
QT_MOC_LITERAL(4, 78, 27), // "on_btnOpenExcelFile_clicked"
QT_MOC_LITERAL(5, 106, 25), // "on_btnGenerateNew_clicked"
QT_MOC_LITERAL(6, 132, 7), // "onError"
QT_MOC_LITERAL(7, 140, 11), // "errorString"
QT_MOC_LITERAL(8, 152, 10), // "onFinished"
QT_MOC_LITERAL(9, 163, 17), // "onProgressChanged"
QT_MOC_LITERAL(10, 181, 5) // "value"

    },
    "QRcodeBatchGenerator\0on_btnGenerateOne_clicked\0"
    "\0on_pushButtonGenerate_clicked\0"
    "on_btnOpenExcelFile_clicked\0"
    "on_btnGenerateNew_clicked\0onError\0"
    "errorString\0onFinished\0onProgressChanged\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QRcodeBatchGenerator[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    1,   53,    2, 0x0a /* Public */,
       8,    0,   56,    2, 0x0a /* Public */,
       9,    1,   57,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void QRcodeBatchGenerator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QRcodeBatchGenerator *_t = static_cast<QRcodeBatchGenerator *>(_o);
        switch (_id) {
        case 0: _t->on_btnGenerateOne_clicked(); break;
        case 1: _t->on_pushButtonGenerate_clicked(); break;
        case 2: _t->on_btnOpenExcelFile_clicked(); break;
        case 3: _t->on_btnGenerateNew_clicked(); break;
        case 4: _t->onError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->onFinished(); break;
        case 6: _t->onProgressChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject QRcodeBatchGenerator::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QRcodeBatchGenerator.data,
      qt_meta_data_QRcodeBatchGenerator,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QRcodeBatchGenerator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QRcodeBatchGenerator::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QRcodeBatchGenerator.stringdata))
        return static_cast<void*>(const_cast< QRcodeBatchGenerator*>(this));
    return QDialog::qt_metacast(_clname);
}

int QRcodeBatchGenerator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
