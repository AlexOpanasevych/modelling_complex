import QtQuick 2.15
import QtQuick.Window 2.15

import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import com.OleksandrOpanasevych.models 1.0

import "pages"
import "common"

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Прототип")

    RowLayout {
        anchors.fill: parent
        spacing: 0
        ScrollView {
            Layout.preferredWidth: 150
            Layout.margins: 5
            Layout.fillHeight: true

            contentWidth: width
            contentHeight: menuCol.implicitHeight

            ColumnLayout {
                id: menuCol
                width: parent.width

                ButtonToPage {
                    Layout.fillWidth: true
                    text: "Завантажити плагіни"

                    highlighted: stackView.currentItem.objectName === "LoadPluginsPage"

                    onClicked: {

                        if(highlighted)
                            return

                        stackView.replace("pages/LoadPluginsPage.qml")
                        pageLabel.text = text
                    }
                }

                ButtonToPage {
                    Layout.fillWidth: true
                    text: "графік функції"

                    highlighted: stackView.currentItem.objectName === "PlotPage"

                    onClicked: {

                        if(highlighted)
                            return

                        stackView.replace("pages/PlotPage.qml")
                        pageLabel.text = text
                    }
                }

                Repeater {
                    model: AppCore.sceneManager.components.menu
                    ButtonToPage {
                        Layout.fillWidth: true
                        text: modelData

                        highlighted: stackView.currentItem.objectName === modelData


                        onClicked: {
//                            console.log(JSON.stringify(AppCore.sceneManager.components.params[modelData]))
                            if(highlighted)
                                return
                            stackView.replace("pages/PluginPage.qml", {"pluginName": modelData, "params": AppCore.sceneManager.components.params[modelData]})
                            pageLabel.text = text
                        }
                    }


                }
            }
        }

        Rectangle {
            Layout.fillHeight: true
            implicitWidth: 1
            color: "black"
        }

        ColumnLayout {

            Layout.fillHeight: true

            Rectangle {
                Layout.preferredHeight: 30
                Layout.fillWidth: true

                color: "lightgray"

                RowLayout {
                    anchors.fill: parent

                    Item {

                        Layout.preferredHeight: 24
                        Layout.preferredWidth: 24
                    }

                    Label {
                        id: pageLabel
                        text: "Завантажити плагіни"
                        elide: Label.ElideRight
                        horizontalAlignment: Qt.AlignHCenter
                        verticalAlignment: Qt.AlignVCenter
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                    }
                    ToolButton {
                        Layout.preferredHeight: 24
                        Layout.preferredWidth: 24

                        padding: 5
                        contentItem: Text {
                            anchors.centerIn: parent
                            text: qsTr("⋮")
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            font.pixelSize: 32
                        }
                    }
                }
            }

            StackView {

                id: stackView

                Layout.fillWidth: true
                Layout.fillHeight: true

                clip: true

                initialItem: LoadPluginsPage {

                }

                replaceEnter: Transition {
                    ParallelAnimation {
                        PropertyAnimation {
                            property: "opacity"
                            from: 0
                            to: 1

                        }
                        PropertyAnimation {
                            property: "y"
                            from: stackView.height
                            to: 0
                        }
                    }



                }

                replaceExit: Transition {
                    ParallelAnimation {
                        PropertyAnimation {
                            property: "opacity"
                            from: 1
                            to: 0

                        }
                        PropertyAnimation {
                            property: "y"
                            from: 0
                            to: stackView.height
                        }
                    }
                }

            }
        }
    }
}
