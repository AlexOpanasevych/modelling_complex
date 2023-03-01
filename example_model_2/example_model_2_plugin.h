#ifndef EXAMPLE_MODEL_2_PLUGIN_H
#define EXAMPLE_MODEL_2_PLUGIN_H

#include <abstractplugininterface.h>
#include <model2.h>

#define ExampleModel1Interface_iid "org.OleksandrOpanasevych.ExampleModel2/1.0"

class Example_model_2Plugin : public AbstractModelPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID ExampleModel1Interface_iid)
    Q_INTERFACES(AbstractModelPluginInterface)

public:
    void registerTypes(const char *uri) override;

private:
    Model2 * _model = new Model2(this);

    // AbstractModelPluginInterface interface
public:
    QString name() override;

public slots:
    AbstractModel *model() override;
};

#endif // EXAMPLE_MODEL_2_PLUGIN_H
