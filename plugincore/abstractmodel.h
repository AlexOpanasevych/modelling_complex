#ifndef ABSTRACTMODEL_H
#define ABSTRACTMODEL_H

#include <plugincore_global.h>
#include <QObject>
#include <QVariant>

class PLUGINCORE_LIB_EXPORT AbstractModel : public QObject
{
    Q_OBJECT
public:
    explicit AbstractModel(QObject *parent = nullptr);

    virtual QVariantList getVariables() = 0;

    Q_INVOKABLE virtual QVariant getResult(const QVariantMap & params) = 0;


signals:

};

#endif // ABSTRACTMODEL_H
