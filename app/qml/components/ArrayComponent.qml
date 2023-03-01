import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

import "../common"

ColumnLayout {

    width: parent.width

    Component.onCompleted: {
        if(defaultValue)
            value = defaultValue
    }

    Label {
        Layout.leftMargin: 5
        Layout.rightMargin: 5
        Layout.fillWidth: true
        text: paramName
    }



    Pane {
        id: pane_main

        Layout.leftMargin: 5
        Layout.rightMargin: 5
        Layout.fillWidth: true


        leftPadding: 5
        rightPadding: 5

        background: Rectangle {
            border.color: "lightgray"
            border.width: 1
        }

        GridLayout {

            id: grid

            width: parent.width

            columns: 2

            ScrollView {

                clip: true

                width: parent.width

                Layout.preferredHeight: 150

                Layout.fillWidth: true

                background: Rectangle {
                    border.color: "lightgray"
                    border.width: 1
                }

                padding: 0

                contentHeight: arrayCol.implicitHeight
                contentWidth: width

                ColumnLayout {

                    id: arrayCol

                    width: parent.width

                    spacing: 0

                    Repeater {

                        id: valueRepeater

                        property int currentSelectedIndex: -1


                        model: value

                        TextField {
                            Layout.fillWidth: true
                            text: modelData

                            background: Rectangle {
                                color: {
                                    if(valueRepeater.currentSelectedIndex === index)
                                        return "blue";

                                    return index % 2 == 0 ? "gray" : "lightgray"
                                }
                            }

                            padding: 2

                            color: {
                                if(valueRepeater.currentSelectedIndex === index)
                                    return "white";


                                return index % 2 == 0 ? "white" : "black"
                            }

                            onTextChanged: {
                                if(acceptableInput)
                                    value[index] = parseFloat(text)
                            }

                            onPressed: {
                                valueRepeater.currentSelectedIndex = index
                            }

                            validator: RegularExpressionValidator {
                                regularExpression: /^\d+(\.\d+)?$/
                            }
                        }

                    }


                }
            }

            ColumnLayout {

                Layout.minimumWidth: (grid.width - grid.columnSpacing) / 2
                Layout.maximumWidth: (grid.width - grid.columnSpacing) / 2

                Layout.alignment: Qt.AlignTop

                ButtonToPage {
                    text: "Додати значення"

                    Layout.fillWidth: true

                    onClicked: {
                        console.log(value)
                        value.push('')
                        valueChanged()

                        console.log(value)
                    }
                }

                ButtonToPage {
                    text: "Видалити значення"
                    Layout.fillWidth: true

                    onClicked: {

                        if(valueRepeater.currentSelectedIndex == -1)
                            return

                        value.splice(valueRepeater.currentSelectedIndex, 1)
                        valueChanged()

                    }
                }

            }









        }
    }
}

