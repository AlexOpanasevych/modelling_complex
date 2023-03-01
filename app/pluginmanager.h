#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QObject>

#include <QPluginLoader>

#include <QQmlEngine>

#include <abstractplugininterface.h>

class SceneManager;

class PluginData: public QObject {
    Q_OBJECT

    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString path READ path CONSTANT)
    Q_PROPERTY(bool enabled READ enabled CONSTANT)
    Q_PROPERTY(AbstractModel * model READ model CONSTANT)

    QString _name;

    QString _path;

    bool _enabled = true;

    AbstractModel *_model = nullptr;

    friend class PluginManager;

public:
    explicit PluginData(QObject * parent = nullptr);
    const QString &name() const;
    const QString &path() const;
    bool enabled() const;
    AbstractModel *model() const;
};

class PluginManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVariantMap plugins READ plugins NOTIFY pluginsChanged)

//    struct PluginData {
//        QString name;
//        QString path;
//        QDateTime created;
//        bool enabled;
//        AbstractModelPluginInterface * pluginLoader;
//    };



    QList<PluginData*> _plugins;

    SceneManager * pSceneManager;


public:
    explicit PluginManager(QObject *parent = nullptr);


    void save();
    void load();

//    void unload();
public:

    Q_INVOKABLE void addPlugin(QString path);

    Q_INVOKABLE void scanPlugins();

    void setSceneManager(SceneManager *newPSceneManager);

    QVariantMap plugins() const;

private:
    AbstractModelPluginInterface * load(const QString & path);
//    void unload(const QString & pluginName);

signals:
    void pluginsChanged();
};

#endif // PLUGINMANAGER_H
