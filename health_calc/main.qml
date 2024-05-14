import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls
import QtQuick.Layouts

import "ui/HeaderTabButton"
import "ui/BMRTab"
import "ui/TestComponent"


ApplicationWindow {
    visible: true
    width: 1280
    height: 720
    title: "Kalkulator zdrowotny"

    header: TabBar {
        id: headerTabBar
        width: parent.width

        HeaderTabButton {
            id: htb1
            text: qsTr("\u0141osie")
        }

        HeaderTabButton {
            id: htbBMR
            text: qsTr("Zapotrzebowanie kaloryczne")
        }

        HeaderTabButton {
            id: htb3
            text: qsTr("Sarny")
        }

        HeaderTabButton {
            id: htb4
            text: qsTr("Dziki")
        }

        HeaderTabButton {
            id: htb5
            text: qsTr("Lisy")
        }
    }

    StackLayout {
        width: parent.width
        height: parent.height
        currentIndex: headerTabBar.currentIndex
        anchors.fill: parent

        Item {
            id: tab1
            Text {
                text: "\u0141osie"
            }
        }

        Item {
            id: tabBMR
            BMRTab {}
        }

        Item {
            id: tab3
            Text {
                text: "Sarny"
            }
        }

        Item {
            id: tab4
            Text {
                text: "Dziki"
            }
        }

        Item {
            id: tab5
            Text {
                text: "Lisy"
            }
        }
    }
}
