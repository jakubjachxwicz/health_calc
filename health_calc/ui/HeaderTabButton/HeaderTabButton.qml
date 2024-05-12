import QtQuick.Controls
import QtQuick 2.3


TabButton {
    id: headerTabButton
    text: qsTr("Example")
    background: Rectangle {
        implicitHeight: 36
        color: headerTabButton.focus ? "pink" : "bisque"
        border.color: "#1c1919"
        border.width: 1
    }
}
