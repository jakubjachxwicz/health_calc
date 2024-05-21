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
		text: "BMI"
		font.pixelSize: 36
	}

	Label {
		Layout.row: 1
		Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
		Layout.column: 1

		padding: 5
		text: "Wzrost (cm)"
	}
	Label {
		Layout.row: 1
		Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
		Layout.column: 2

		padding: 5
		text: "Waga (kg)"
	}

	TextField {
		Layout.row: 2
		Layout.column: 1
		Layout.preferredWidth: parent.width * .25
		Layout.preferredHeight: 30

		onEditingFinished: BMIHandler.setAge(text)
		text: BMIHandler.age
	}
	TextField {
		Layout.row: 2
		Layout.column: 2
		Layout.preferredHeight: 30
		Layout.preferredWidth: parent.width * .25

		onEditingFinished: BMIHandler.setHeight(text)
		text: BMIHandler.height
	}

	GridLayout {
		Layout.row: 4
		Layout.column: 0
		Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
		Layout.columnSpan: 4

		width: parent.width

		columns: 5
		rows: 2
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
		text: BMIHandler.resultMessage
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

