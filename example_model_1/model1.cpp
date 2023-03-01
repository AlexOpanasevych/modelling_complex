#include "model1.h"

#include <QVariantMap>
#include <QDebug>

Model1::Model1(QObject *parent)
    : AbstractModel(parent)
{

}

Model1::~Model1()
{
}

QVariantList Model1::getVariables()
{
    return QVariantList{
        QVariantMap{{"type", "number"}, {"name", "first"}},
        QVariantMap{{"type", "number"}, {"name", "second"}}
    };
}

QVariant Model1::getResult(const QVariantMap & params)
{
    qDebug() << params;
    return QString::number(params["first"].toDouble() * params["second"].toDouble(), 'g', 2).toDouble();
}
