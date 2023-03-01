import QtQuick 2.15
import QtQuick.Controls 2.15

import QtQuick.Layouts 1.15

import QtQuick.Dialogs 1.3

import com.OleksandrOpanasevych.models 1.0


Page {

    objectName: "LoadPluginsPage"

    contentItem: GridLayout {
        rows: 2

        TextField {
            id: pathField
            Layout.alignment: Qt.AlignRight
        }


        Button {

            Layout.alignment: Qt.AlignLeft


            padding: 5

            text: "Огляд"

            onClicked: pathDialog.open()

            FileDialog {
                id: pathDialog

                title: "Будь ласка виберіть файл плагіна"

                folder: shortcuts.home

                nameFilters: [("Файли плагінів (*.dll)")]

                onAccepted: {
                    console.log("you chose:", fileUrls)

                    for(let i = 0; i < fileUrls.length; i++)
                        AppCore.pluginManager.addPlugin(removeUrl(fileUrls[i]))
                }
            }
        }

        Item {
            Layout.fillHeight: true
        }
    }

    function removeUrl(url) {
        return url.replace('file:///', '')
    }

}
