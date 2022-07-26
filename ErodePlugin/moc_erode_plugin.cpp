/****************************************************************************
** Meta object code from reading C++ file 'erode_plugin.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "erode_plugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'erode_plugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ErodePlugin_t {
    const uint offsetsAndSize[2];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ErodePlugin_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ErodePlugin_t qt_meta_stringdata_ErodePlugin = {
    {
QT_MOC_LITERAL(0, 11) // "ErodePlugin"

    },
    "ErodePlugin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ErodePlugin[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ErodePlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject ErodePlugin::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ErodePlugin.offsetsAndSize,
    qt_meta_data_ErodePlugin,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ErodePlugin_t
, QtPrivate::TypeAndForceComplete<ErodePlugin, std::true_type>



>,
    nullptr
} };


const QMetaObject *ErodePlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ErodePlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ErodePlugin.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "EditorPluginInterface"))
        return static_cast< EditorPluginInterface*>(this);
    if (!strcmp(_clname, "com.ignabelitzky.editorplugininterface"))
        return static_cast< EditorPluginInterface*>(this);
    return QObject::qt_metacast(_clname);
}

int ErodePlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}

#ifdef QT_MOC_EXPORT_PLUGIN_V2
static constexpr unsigned char qt_pluginMetaDataV2_ErodePlugin[] = {
    0xbf, 
    // "IID"
    0x02,  0x78,  0x26,  'c',  'o',  'm',  '.',  'i', 
    'g',  'n',  'a',  'b',  'e',  'l',  'i',  't', 
    'z',  'k',  'y',  '.',  'e',  'd',  'i',  't', 
    'o',  'r',  'p',  'l',  'u',  'g',  'i',  'n', 
    'i',  'n',  't',  'e',  'r',  'f',  'a',  'c', 
    'e', 
    // "className"
    0x03,  0x6b,  'E',  'r',  'o',  'd',  'e',  'P', 
    'l',  'u',  'g',  'i',  'n', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN_V2(ErodePlugin, ErodePlugin, qt_pluginMetaDataV2_ErodePlugin)
#else
QT_PLUGIN_METADATA_SECTION
static constexpr unsigned char qt_pluginMetaData_ErodePlugin[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x26,  'c',  'o',  'm',  '.',  'i', 
    'g',  'n',  'a',  'b',  'e',  'l',  'i',  't', 
    'z',  'k',  'y',  '.',  'e',  'd',  'i',  't', 
    'o',  'r',  'p',  'l',  'u',  'g',  'i',  'n', 
    'i',  'n',  't',  'e',  'r',  'f',  'a',  'c', 
    'e', 
    // "className"
    0x03,  0x6b,  'E',  'r',  'o',  'd',  'e',  'P', 
    'l',  'u',  'g',  'i',  'n', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(ErodePlugin, ErodePlugin)
#endif  // QT_MOC_EXPORT_PLUGIN_V2

QT_WARNING_POP
QT_END_MOC_NAMESPACE
