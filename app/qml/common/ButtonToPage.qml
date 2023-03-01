import QtQuick 2.15
import QtQuick.Controls 2.15

Button {
    id: root

    hoverEnabled: true

    implicitHeight: contentItem.implicitHeight + 10

    contentItem: Text {
        id: menuItemText

        text: root.text

        anchors.centerIn: parent
    }

    background: Rectangle {
        border.width: 2
        color: {
            if(root.pressed)
                return "gray"
            if(root.hovered)
                return "darkgray"
            if(root.highlighted)
                return "lightgray"
            return "white"
        }
    }

}
