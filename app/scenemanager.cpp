#include "scenemanager.h"
#include <QVariant>
#include <QDebug>

SceneManager::SceneManager(QObject *parent) : QObject(parent)
{

}

void SceneManager::addComponent(const QString &type, const QVariant & data)
{
    _componentsMap[type] = data;

    emit componentsChanged();
}

void SceneManager::addMenuItem(const QString &name)
{
    auto _items =  components()["menu"].toList();
    _items.append(name);
    addComponent("menu", _items);
}

void SceneManager::addParameters(const QString &name, const QVariantList &parameters)
{
    auto _parameters = components()["params"].toMap();
    _parameters[name] = parameters;
    qDebug() << _parameters;
    addComponent("params", _parameters);
    emit componentsChanged();
}

const QVariantMap &SceneManager::components() const
{
    return _componentsMap;
}

//const QVariantMap &SceneManager::paramTypes() const
//{
//    return m_paramTypes;
//}
