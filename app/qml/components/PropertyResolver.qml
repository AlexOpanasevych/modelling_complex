import QtQuick 2.15

import com.OleksandrOpanasevych.models 1.0

Loader {
    id: root
    property string paramType: "number"

    property string paramName

    property var defaultValue

    property var value

    source: {
        switch(paramType) {
        case "number": // todo: rework to take Types from corelib like
                       // Types.Number or Types.Array
            return "NumberComponent.qml"
        case "sequence":
            return "ArrayComponent.qml"
        }
    }
}
