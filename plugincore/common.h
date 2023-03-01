#ifndef COMMON_H
#define COMMON_H

#define SINGLETON(NAME) \
public: \
    static NAME * instance() { \
        static NAME instance; \
        return &instance; \
    }

#define QML_INSTANCE(NAME) \
SINGLETON(NAME) \
    static QObject * qmlInstance(QQmlEngine * eng, QJSEngine *) { \
        auto obj = instance(); \
        eng->setObjectOwnership(obj, QQmlEngine::CppOwnership); \
        return obj; \
    }

#define LIB_NAME "com.OleksandrOpanasevych.models"
#define LIB_VERSION_MAJOR 1
#define LIB_VERSION_MINOR 0

#define REGISTER_QML_TYPE(Type) \
    qmlRegisterType<Type>(LIB_NAME, LIB_VERSION_MAJOR, LIB_VERSION_MINOR, #Type);

#define REGISTER_SINGLETON_TYPE(Type) \
    qmlRegisterSingletonType<Type>(LIB_NAME, LIB_VERSION_MAJOR, LIB_VERSION_MINOR, #Type, &Type::qmlInstance);

#endif // COMMON_H
