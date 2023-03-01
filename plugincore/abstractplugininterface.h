#ifndef ABSTRACTPLUGININTERFACE_H
#define ABSTRACTPLUGININTERFACE_H

#include "plugincore_global.h"
#include "common.h"
#include "abstractmodel.h"

#include <QtPlugin>
#include <QQmlExtensionPlugin>


class PLUGINCORE_LIB_EXPORT AbstractModelPluginInterface : public QQmlExtensionPlugin {
    Q_OBJECT
public:
    explicit AbstractModelPluginInterface(QObject * parent = nullptr);

    ~AbstractModelPluginInterface();

    virtual QString name() = 0;

public slots:

    virtual AbstractModel * model() = 0;

};

Q_DECLARE_INTERFACE(AbstractModelPluginInterface, LIB_NAME)

#endif // ABSTRACTPLUGININTERFACE_H
