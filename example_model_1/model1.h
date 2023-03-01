#ifndef MODEL1_H
#define MODEL1_H

#include <abstractmodel.h>

class Model1 : public AbstractModel
{
    Q_OBJECT
public:
    explicit Model1(QObject *parent = nullptr);
    ~Model1();

    // AbstractModel interface
public:
    QVariantList getVariables() override;
    QVariant getResult(const QVariantMap &params) override;
};

#endif // MODEL1_H
