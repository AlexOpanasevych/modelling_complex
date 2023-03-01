import QtQuick 2.0

Rectangle {
    property int orientation: Qt.Horizontal
    property int implicitSize: 1

    implicitHeight: orientation === Qt.Horizontal ? implicitSize : 0
    implicitWidth: orientation === Qt.Vertical ? implicitSize : 0
}
