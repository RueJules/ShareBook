#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>
#include <QtCore/qhash.h>
#include <QtCore/qstring.h>

namespace QmlCacheGeneratedCode {
namespace _0x5f_ShareBook_Prototype_run_media_root_linux_school_have_many_P_important_pro_ShareBook_ShareBook_src_ShareBook_Prototype__0x2e__Main_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _0x5f_ShareBook_Prototype_run_media_root_linux_school_have_many_P_important_pro_ShareBook_ShareBook_src_ShareBook_Prototype__0x2e__UI_EditDialog_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _0x5f_ShareBook_Prototype_run_media_root_linux_school_have_many_P_important_pro_ShareBook_ShareBook_src_ShareBook_Prototype__0x2e__UI_Main_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::TypedFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    ~Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
    resourcePathToCachedUnit.insert(QStringLiteral("/ShareBook_Prototype/run/media/root/linux/school_have_many_P/important_pro/ShareBook/ShareBook/src/ShareBook_Prototype/./Main.qml"), &QmlCacheGeneratedCode::_0x5f_ShareBook_Prototype_run_media_root_linux_school_have_many_P_important_pro_ShareBook_ShareBook_src_ShareBook_Prototype__0x2e__Main_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/ShareBook_Prototype/run/media/root/linux/school_have_many_P/important_pro/ShareBook/ShareBook/src/ShareBook_Prototype/./UI/EditDialog.qml"), &QmlCacheGeneratedCode::_0x5f_ShareBook_Prototype_run_media_root_linux_school_have_many_P_important_pro_ShareBook_ShareBook_src_ShareBook_Prototype__0x2e__UI_EditDialog_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/ShareBook_Prototype/run/media/root/linux/school_have_many_P/important_pro/ShareBook/ShareBook/src/ShareBook_Prototype/./UI/Main.qml"), &QmlCacheGeneratedCode::_0x5f_ShareBook_Prototype_run_media_root_linux_school_have_many_P_important_pro_ShareBook_ShareBook_src_ShareBook_Prototype__0x2e__UI_Main_qml::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.structVersion = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
}

Registry::~Registry() {
    QQmlPrivate::qmlunregister(QQmlPrivate::QmlUnitCacheHookRegistration, quintptr(&lookupCachedUnit));
}

const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qmlcache_appShareBook_Prototype)() {
    ::unitRegistry();
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qmlcache_appShareBook_Prototype))
int QT_MANGLE_NAMESPACE(qCleanupResources_qmlcache_appShareBook_Prototype)() {
    return 1;
}
