import QtQuick 2.3
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Dialogs


ColumnLayout {
	width: parent.width * .7
	anchors.horizontalCenter: parent.horizontalCenter
	
	Label {
		horizontalAlignment: Text.AlignHCenter
		Layout.fillWidth: true
		Layout.fillHeight: true
		
		wrapMode: Text.WrapAnywhere
		padding: 36
		text: "BMI"
		font.pixelSize: 36
	}

	RowLayout {
		ColumnLayout {
			Label {
				Layout.fillWidth: true
				Layout.fillHeight: true

				horizontalAlignment: Text.AlignHCenter
				padding: 5
				text: "Wzrost (cm)"
			}

			TextField {
				Layout.fillWidth: true
				Layout.fillHeight: true
			
				onEditingFinished: BMIHandler.setHeight(text)
				text: BMIHandler.height
			}
		}
		ColumnLayout {
			Label {
				Layout.fillWidth: true
				Layout.fillHeight: true

				horizontalAlignment: Text.AlignHCenter
				padding: 5
				text: "Waga (kg)"
			}

			TextField {
				Layout.fillWidth: true
				Layout.fillHeight: true
			
				onEditingFinished: BMIHandler.setWeight(text)
				text: BMIHandler.weight
			}
		}
	}

	Rectangle {
		Layout.fillWidth: true
		Layout.fillHeight: true
		Layout.margins: 60
		color: BMIHandler.rectColor
		width: 100
		height: 100
		radius: 10
		Label {
			width: parent.width
			horizontalAlignment: Text.AlignHCenter
			padding: 16
			wrapMode: Text.WrapAnywhere
			font.pixelSize: 16
			text: BMIHandler.resultMessage
		}
	}

	Button {
		Layout.fillHeight: true
		anchors.right: parent.right

		text: qsTr("Eksportuj do pliku")
		implicitWidth: 213
		implicitHeight: 41

		onClicked: folderDialog.open()
	}

	Button {
		Layout.fillHeight: true
		anchors.right: parent.right
	
		text: qsTr("Informacje")
		implicitWidth: 213
		implicitHeight: 41

		onClicked: infoDialog.open()
	}

	Dialog {
		id: infoDialog
		standardButtons: Dialog.Ok
		title: "Informacje"
		width: 500

		contentItem: ColumnLayout {
			spacing: 20

			Text {
				Layout.fillWidth: true
				Layout.fillHeight: true
				wrapMode: Text.WordWrap
				text: "BMI (Body Mass Index) to wskaźnik masy ciała w stosunku do wzrostu, który jest powszechnie używany do oceny, czy dana osoba ma prawidłową masę ciała w stosunku do swojego wzrostu."
			}
			Text {
				Layout.fillWidth: true
				Layout.fillHeight: true	
				wrapMode: Text.WordWrap
				text: "Wzór:\nBMI=masa/(wzrost*wzrost)"
			}
		}
	}
	FolderDialog {
	id: folderDialog
	currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
	onAccepted: BMIHandler.exportToFile(currentFolder)
	}
}