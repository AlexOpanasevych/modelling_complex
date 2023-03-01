#include "example_model_2_plugin.h"

#include "model2.h"

#include <qqml.h>

void Example_model_2Plugin::registerTypes(const char *uri)
{
    // @uri com.OleksandrOpanasevych.models
    //    qmlRegisterType<Model2>(uri, 1, 0, "Model2");
}

QString Example_model_2Plugin::name()
{
    return QStringLiteral("Model2");
}

AbstractModel *Example_model_2Plugin::model()
{
    return _model;
}

