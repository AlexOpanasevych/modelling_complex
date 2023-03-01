#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QObject>
#include <QMap>

class SceneManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVariantMap components READ components NOTIFY componentsChanged)

//    Q_PROPERTY(QVariantMap paramTypes READ paramTypes CONSTANT)
                              // component
                              // type
//    using ComponentsMap = QMap<QString, QVariantList>;

    QVariantMap _componentsMap;

//    static QVariantMap m_paramTypes = {
//        {"number", "number"}
//    };

public:
    explicit SceneManager(QObject *parent = nullptr);

    void addComponent(const QString & type, const QVariant &data);

    void addMenuItem(const QString & name);

    void addParameters(const QString & name, const QVariantList &parameters);

//    QVariantList getComponents(const QString & type);

    const QVariantMap &components() const;

//    const QVariantMap &paramTypes() const;

signals:

    void componentsChanged();
};

#endif // SCENEMANAGER_H
