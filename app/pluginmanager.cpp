#include "pluginmanager.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDir>
#include <QCoreApplication>
#include <QDirIterator>

#include "scenemanager.h"


void PluginManager::setSceneManager(SceneManager *newPSceneManager)
{
    pSceneManager = newPSceneManager;
}

PluginManager::PluginManager(QObject *parent) : QObject(parent)
{
}

void PluginManager::save()
{
    QFile file("plugins.json");

    Q_ASSERT(file.open(QFile::Truncate));

    QJsonDocument doc;

    QJsonArray plugins;

    for(const auto &plugin : qAsConst(_plugins)) {
        QJsonObject pluginObject;
        pluginObject["name"] = plugin->name();
        pluginObject["path"] = plugin->path();
        pluginObject["enabled"] = plugin->enabled();
    }

    doc.setArray(plugins);

    file.write(doc.toJson());

}

AbstractModelPluginInterface * PluginManager::load(const QString &path)
{

    QPluginLoader loader(path);

    AbstractModelPluginInterface * instance = nullptr;

    if(loader.load())
        instance = qobject_cast<AbstractModelPluginInterface*>(loader.instance());

    if(!instance)
        qInfo() << "Сannot load plugin file: " << path;
    else
        qInfo() << "Plugin loaded: " << instance->name();

    return instance;

    // do stuff




}

void PluginManager::load()
{
//    unload();

    QFile file("plugins.json");

    if(!file.open(QFile::ReadOnly))
        return;

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());

    auto plugins = doc.array();

    for(auto plugin : plugins) {

        auto object = plugin.toObject();

        PluginData * pData = new PluginData(this);

        pData->_name = object["name"].toString();
        pData->_path = object["path"].toString();
        pData->_enabled = object["enabled"].toBool();

        _plugins.append(pData);
    }

    if(!_plugins.isEmpty())
        emit pluginsChanged();
}

//void PluginManager::unload()
//{
//    for(const auto &plugin : qAsConst(_plugins))
//        if(plugin.pluginLoader)
//            dynamic_cast<QObject*>(plugin.pluginLoader)->deleteLater();
//    _plugins.clear();
//}

//void PluginManager::unload(const QString &pluginName)
//{
//    auto plugin = std::find_if(_plugins.begin(), _plugins.end(), [&pluginName](const PluginData & d){return d.name == pluginName;});
//    if(plugin != _plugins.end())
//        dynamic_cast<QObject*>((*plugin).pluginLoader)->deleteLater();
//    _plugins.erase(plugin);
//}

void PluginManager::addPlugin(QString path)
{
    if(std::find_if(_plugins.begin(), _plugins.end(), [&path](const PluginData * data){return path == data->_path;}) != _plugins.end()) {
        qWarning() << "Plugin is already presented";
        return;
    }

    if(!QDir::isAbsolutePath(path))
        path = QDir(path).absolutePath();

//    QFileInfo fileInfo(path);

//    data.created = fileInfo.metadataChangeTime();



    auto plugin = load(path);

    if(!plugin)
        return;

    PluginData * data = new PluginData(this);

    data->_path = path;

    data->_enabled = true;

    data->_model = plugin->model();

    data->_name = plugin->name();

    _plugins.append(data);

    pSceneManager->addMenuItem(data->_name);

    pSceneManager->addParameters(data->_name, data->_model->getVariables());

    emit pluginsChanged();
}

void PluginManager::scanPlugins()
{
    QDir pluginsDir(QCoreApplication::applicationDirPath() + '/' + "plugins");

    pluginsDir.setFilter(QDir::Dirs);

    QDirIterator it(pluginsDir);

    while(it.hasNext())
    {
        auto pluginDir = it.next();

        pluginsDir.cd(pluginDir);

        QFile qmldir(pluginsDir.path() + "/" + "qmldir");


        if(qmldir.exists() && qmldir.open(QFile::ReadOnly) && QFile::exists(pluginsDir.path())) {

            qInfo() << "new plugin detected:" << qmldir.readLine() << qmldir.readLine();

//            addPLugin(path);

        }


    }


}

PluginData::PluginData(QObject *parent) : QObject(parent)
{

}

const QString &PluginData::name() const
{
    return _name;
}

const QString &PluginData::path() const
{
    return _path;
}

bool PluginData::enabled() const
{
    return _enabled;
}

AbstractModel *PluginData::model() const
{
    return _model;
}

QVariantMap PluginManager::plugins() const
{
    QVariantMap plugins;
    for (auto plugin : _plugins) {
        plugins[plugin->_name] = QVariant::fromValue(plugin);
//        qDebug() << plugins[plugin->name()].value<PluginData*>()->plugin();/*.value<QObject*>()->metaObject()->className();*/
    }
    return plugins;
}
