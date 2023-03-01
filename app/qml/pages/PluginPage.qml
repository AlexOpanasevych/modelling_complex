import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

import com.OleksandrOpanasevych.models 1.0

import "../common"
import "../components"

RowLayout {
    id: root

    property string pluginName
    property var params

    property var values: ({})

    objectName: pluginName

    ScrollView {
        Layout.fillHeight: true

        Layout.fillWidth: true

        contentHeight: propertyCol.implicitHeight
        contentWidth: width

        Layout.preferredWidth: (root.width - spacing) / 2
        Layout.minimumWidth: 200


        ColumnLayout {
            id: propertyCol

            width: parent.width

            Repeater {

                model: params

                delegate: PropertyResolver {
                    id:delegate
                    paramType: modelData.type
                    paramName: modelData.name
                    defaultValue: modelData.defaultValue

                    Layout.fillWidth: true

                    onValueChanged: {
                        console.log(values[paramName])
                        values[paramName] = delegate.value
                        console.log(values[paramName])
                    }

                }
            }
        }
    }



    Line {
        Layout.fillHeight: true
        orientation: Qt.Vertical
    }

    ColumnLayout {
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.minimumWidth: (root.width - spacing) / 2

        ButtonToPage {
            text: "Обчислити"

            Layout.alignment: Qt.AlignHCenter

            onClicked: {

                console.log(JSON.stringify(AppCore.pluginManager.plugins[pluginName].plugin))

                text.text = "Результат обчислення: " + AppCore.pluginManager.plugins[pluginName].model.getResult(values)
            }
        }

        Text {
            Layout.alignment: Qt.AlignHCenter
            id: text
        }
    }

    Component.onCompleted: {
        for(let i = 0; i < params.length; i++) {
            let param = params[i]
            if(param.defaultValue)
                values[param.name] = param.defaultValue
        }
    }
}
