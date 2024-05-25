import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls
import QtQuick.Layouts

import "ui/HeaderTabButton"
import "ui/BMI"
import "ui/BMRTab"
import "ui/BFP"
import "ui/Macro"
import "ui/User"

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
            text: qsTr("BMI")
        }

        HeaderTabButton {
            id: htbBMR
            text: qsTr("Zapotrzebowanie kaloryczne")
        }

        HeaderTabButton {
            id: htb3
            text: qsTr("BFP")
        }

        HeaderTabButton {
            id: htb4
            text: qsTr("Makroskładniki")
        }

        HeaderTabButton {
            id: htb5
            text: qsTr("Dane użytkownika")
        }
    }

    StackLayout {
        width: parent.width
        height: parent.height
        currentIndex: headerTabBar.currentIndex
        anchors.fill: parent

        Item {
            id: tab1
            BMI {}
        }

        Item {
            id: tabBMR
            BMRTab {}
        }

        Item {
            id: tab3
            BFP {}
        }

        Item {
            id: tab4
            Macro {}
        }

        Item {
            id: tab5
            User {}
        }
    }
}
