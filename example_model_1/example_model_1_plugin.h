#ifndef EXAMPLE_MODEL_1_PLUGIN_H
#define EXAMPLE_MODEL_1_PLUGIN_H

#include <abstractplugininterface.h>
#include <model1.h>

#define ExampleModel1Interface_iid "org.OleksandrOpanasevych.ExampleModel1/1.0"

class Example_model_1Plugin : public AbstractModelPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID ExampleModel1Interface_iid)
    Q_INTERFACES(AbstractModelPluginInterface)


public:
    void registerTypes(const char *uri) override;

    // AbstractModelPluginInterface interface
public:
    QString name() override;
private:
    Model1 *_model = new Model1(this);

    // AbstractModelPluginInterface interface
public slots:
    AbstractModel *model() override;
};

#endif // EXAMPLE_MODEL_1_PLUGIN_H
