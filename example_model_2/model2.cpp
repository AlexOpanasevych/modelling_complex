#include "model2.h"

Model2::Model2(QObject *parent)
    : AbstractModel(parent)
{

}

QVariantList Model2::getVariables()
{
    return QVariantList{
        QVariantMap{{"type", "number"}, {"name", "множник"}, {"defaultValue", 3}},
        QVariantMap{{"type", "sequence"}, {"name", "послідовність"}, {"defaultValue", QVariantList{1.2, 2.3, 3.4, 4.2}}},
        QVariantMap{{"type", "number"}, {"name", "множник 2"}, {"defaultValue", 3}},
        QVariantMap{{"type", "number"}, {"name", "множник 3"}, {"defaultValue", 3}},
        QVariantMap{{"type", "number"}, {"name", "множник 4"}, {"defaultValue", 3}},
        QVariantMap{{"type", "number"}, {"name", "множник 5"}, {"defaultValue", 3}},
        QVariantMap{{"type", "number"}, {"name", "множник 6"}, {"defaultValue", 3}},
        QVariantMap{{"type", "number"}, {"name", "множник 7"}, {"defaultValue", 3}},
    };
}

QVariant Model2::getResult(const QVariantMap &params)
{
    qDebug() << params;
    auto first = params["множник"].toDouble();
    auto second = params["послідовність"].toList();
//    QVariantList _result;
    std::for_each(second.begin(), second.end(), [&first](QVariant & value){value = QString::number(value.toDouble() * first, 'g', 2).toDouble();});
    return second;
//    return std::accumulate(second.begin(), second.end(), double(0), [](double sum, const QVariant & v){return sum + v.toDouble();}) * first;
}
