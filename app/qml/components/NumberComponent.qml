import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "../common"

ColumnLayout {
    id: col

    width: parent.width

    Label {
        Layout.leftMargin: 5
        Layout.rightMargin: 5
        Layout.fillWidth: true
        text: paramName
    }

    TextField {
        id: textField
        Layout.leftMargin: 5
        Layout.rightMargin: 5
        Layout.fillWidth: true

        text: defaultValue || ""

        onTextChanged: {
            if(acceptableInput)
                value = parseFloat(text)
        }

        validator: RegularExpressionValidator {
            regularExpression: /^\d+(\.\d+)?$/
        }
    }

}

