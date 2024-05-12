import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls


ApplicationWindow {
    visible: true
    width: 1280
    height: 720
    title: "Kalkulator zdrowotny"

    Text {
        anchors.fill: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        font.pointSize: 42
        text: "Hello World!"
    }
}
