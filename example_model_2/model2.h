#ifndef MODEL2_H
#define MODEL2_H

#include <QQuickItem>
#include <abstractmodel.h>

class Model2 : public AbstractModel
{
    Q_OBJECT

public:
    explicit Model2(QObject *parent = nullptr);

    // AbstractModel interface
public:
    QVariantList getVariables() override;
    QVariant getResult(const QVariantMap &params) override;
};

#endif // MODEL2_H
