import QtQuick.Controls
import QtQuick 2.3


TabButton {
    id: headerTabButton
    text: qsTr("Example")
    background: Rectangle {
        implicitHeight: 36
        color: headerTabButton.focus ? "lightslategrey" : "silver"
        border.color: "#1c1919"
        border.width: 1
    }
}
