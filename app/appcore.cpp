#include "appcore.h"

#include <QCoreApplication>

void registerTypes() {
    REGISTER_SINGLETON_TYPE(AppCore)

}

AppCore::AppCore(QObject *parent) : QObject(parent)
{
    _pluginManager->setSceneManager(_sceneManager);
}

PluginManager *AppCore::pluginManager() const
{
    return _pluginManager;
}

Q_COREAPP_STARTUP_FUNCTION(registerTypes)

SceneManager *AppCore::sceneManager() const
{
    return _sceneManager;
}
