#include "example_model_1_plugin.h"

#include "model1.h"

#include <qqml.h>


void Example_model_1Plugin::registerTypes(const char *uri)
{
    // @uri com.OleksandrOpanasevych.models
//    qmlRegisterSingletonType<Model1>(uri, 1, 0, "Model1");

}

QString Example_model_1Plugin::name()
{
    return "Model1";
}

AbstractModel *Example_model_1Plugin::model()
{
    return _model;
}
