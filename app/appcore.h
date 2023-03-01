#ifndef APPCORE_H
#define APPCORE_H

#include <QObject>
#include <common.h>
#include <pluginmanager.h>
#include <scenemanager.h>

class AppCore : public QObject
{
    Q_OBJECT

    Q_PROPERTY(PluginManager * pluginManager READ pluginManager CONSTANT)
    Q_PROPERTY(SceneManager * sceneManager READ sceneManager CONSTANT)

    QML_INSTANCE(AppCore)

public:
    explicit AppCore(QObject *parent = nullptr);

    PluginManager *pluginManager() const;

    SceneManager *sceneManager() const;

signals:


private:
    PluginManager * _pluginManager = new PluginManager(this);
    SceneManager * _sceneManager = new SceneManager(this);
};

#endif // APPCORE_H
