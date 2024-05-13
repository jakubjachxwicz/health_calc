import QtQuick 2.3
import QtQuick.Layouts
import QtQuick.Controls


GridLayout {
	anchors.horizontalCenter: parent.horizontalCenter
	width: parent.width * .9
	rows: 7
	columns: 4

	Label {
		Layout.row: 0
		Layout.column: 0
		Layout.columnSpan: 4
		Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter

		width: parent.width
		padding: 40
		text: "Dzienne zapotrzebowanie kaloryczne"
		font.pixelSize: 36
	}

	Label {
		Layout.row: 1
		Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
		Layout.column: 0

		padding: 5
		text: "Płeć"
	}
	Label {
		Layout.row: 1
		Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
		Layout.column: 1

		padding: 5
		text: "Wiek (lata)"
	}
	Label {
		Layout.row: 1
		Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
		Layout.column: 2

		padding: 5
		text: "Wzrost (cm)"
	}
	Label {
		Layout.row: 1
		Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
		Layout.column: 3

		padding: 5
		text: "Waga (kg)"
	}

	RowLayout {
		Layout.row: 2
		Layout.column: 0
		Layout.preferredWidth: parent.width * .25

		RadioButton {
			id: femaleRadioButton
		
			Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
			text: qsTr("K")
			checked: (BMRHandler.isMale ? false : true)
			MouseArea {
				anchors.fill: parent
				onClicked: BMRHandler.setIsMale(false);
			}
		}
		RadioButton {
			id: maleRadioButton

			Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
			text: qsTr("M")
			checked: (BMRHandler.isMale ? true : false)
			MouseArea {
				anchors.fill: parent
				onClicked: BMRHandler.setIsMale(true);
			}
		}
	}

	TextField {
		Layout.row: 2
		Layout.column: 1
		Layout.preferredWidth: parent.width * .25
		Layout.preferredHeight: 30

		onEditingFinished: BMRHandler.setAge(text)
		text: BMRHandler.age
	}
	TextField {
		Layout.row: 2
		Layout.column: 2
		Layout.preferredHeight: 30
		Layout.preferredWidth: parent.width * .25

		onEditingFinished: BMRHandler.setHeight(text)
		text: BMRHandler.height
	}
	TextField {
		Layout.row: 2
		Layout.column: 3
		Layout.preferredHeight: 30
		Layout.preferredWidth: parent.width * .25

		onEditingFinished: BMRHandler.setWeight(text)
		text: BMRHandler.weight
	}

	Label {
		Layout.row: 3
		Layout.column: 0
		Layout.columnSpan: 4
		Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter

		width: parent.width
		topPadding: 32
		bottomPadding: 4
		text: "Poziom aktywności fizycznej"
		font.pixelSize: 24
	}

	GridLayout {
		Layout.row: 4
		Layout.column: 0
		Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
		Layout.columnSpan: 4

		width: parent.width

		columns: 5
		rows: 2

		Label {
			Layout.row: 0
			Layout.column: 0
			Layout.preferredWidth: parent.width * .2
			horizontalAlignment: Text.AlignHCenter
			text: qsTr("Znikomy/brak")
		}
		Label {
			Layout.row: 0
			horizontalAlignment: Text.AlignHCenter
			Layout.preferredWidth: parent.width * .2
			Layout.column: 1

			text: qsTr("Niski")
		}
		Label {
			Layout.row: 0
			Layout.preferredWidth: parent.width * .2
			horizontalAlignment: Text.AlignHCenter
			Layout.column: 2

			text: qsTr("Przeciętny")
		}
		Label {
			Layout.row: 0
			horizontalAlignment: Text.AlignHCenter
			Layout.preferredWidth: parent.width * .2
			Layout.column: 3

			text: qsTr("Wysoki")
		}
		Label {
			Layout.row: 0
			horizontalAlignment: Text.AlignHCenter
			Layout.preferredWidth: parent.width * .2
			Layout.column: 4

			text: qsTr("Bardzo wysoki")
		}

		RadioButton {
			Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
			Layout.row: 1
			Layout.column: 0

			checked: (BMRHandler.activityLevel == 0 ? true : false)
			MouseArea {
				anchors.fill: parent
				onClicked: BMRHandler.setActivityLevel(0)
			}
		}
		RadioButton {
			Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
			Layout.row: 1
			Layout.column: 1

			checked: (BMRHandler.activityLevel == 1 ? true : false)
			MouseArea {
				anchors.fill: parent
				onClicked: BMRHandler.setActivityLevel(1)
			}
		}
		RadioButton {
			Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
			Layout.row: 1
			Layout.column: 2

			checked: (BMRHandler.activityLevel == 2 ? true : false)
			MouseArea {
				anchors.fill: parent
				onClicked: BMRHandler.setActivityLevel(2)
			}
		}
		RadioButton {
			Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
			Layout.row: 1
			Layout.column: 3

			checked: (BMRHandler.activityLevel == 3 ? true : false)
			MouseArea {
				anchors.fill: parent
				onClicked: BMRHandler.setActivityLevel(3)
			}
		}
		RadioButton {
			Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
			Layout.row: 1
			Layout.column: 4

			checked: (BMRHandler.activityLevel == 4 ? true : false)
			MouseArea {
				anchors.fill: parent
				onClicked: BMRHandler.setActivityLevel(4)
			}
		}
	}

	Button {
		Layout.row: 5
		Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
		Layout.column: 0

		implicitWidth: 294
		implicitHeight: 64
		text: qsTr("Oblicz")
	}

	Label {
		Layout.row: 5
		Layout.column: 1
		Layout.columnSpan: 3
		Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
		Layout.margins: 80

		font.pixelSize: 16
		text: BMRHandler.resultMessage
	}

	ColumnLayout {
		Layout.row: 6
		Layout.column: 3

		Button {
			text: qsTr("Eksportuj do pliku")
			implicitWidth: 213
			implicitHeight: 41
		}
		Button {
			text: qsTr("Informacje")
			implicitWidth: 213
			implicitHeight: 41
		}
	}
}
