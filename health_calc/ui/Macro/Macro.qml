import QtQuick 2.3
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Dialogs

ColumnLayout {
	width: parent.width * .8
	anchors.horizontalCenter: parent.horizontalCenter
	
	Label {
		horizontalAlignment: Text.AlignHCenter
		Layout.fillWidth: true
		Layout.fillHeight: true
		
		wrapMode: Text.WrapAnywhere
		padding: 36
		text: "Makroskładniki"
		font.pixelSize: 36
	}

	RowLayout {
		Label {
			Layout.fillWidth: true
			Layout.fillHeight: true

			horizontalAlignment: Text.AlignHCenter
			padding: 5
			text: "BMR:"
		}

		TextField {
			Layout.fillHeight: true
			Layout.fillWidth: true
			
			onEditingFinished: MacroHandler.setBMR(text)
			text: MacroHandler.bmr
		}
	}

	Label {
		Layout.fillWidth: true
		Layout.fillHeight: true
		Layout.margins: 60

		horizontalAlignment: Text.AlignHCenter
		wrapMode: Text.WrapAnywhere
		font.pixelSize: 16
		text: MacroHandler.resultMessage
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
				text: "Makroskładniki – to podstawowe składniki odżywcze, które dostarczane są do ludzkiego organizmu. W ich skład wchodzą przede wszystkim białka, węglowodany i tłuszcze."
			}
			Text {
				Layout.fillWidth: true
				Layout.fillHeight: true	
				wrapMode: Text.WordWrap
				text: "Wzór:\nBiałka: 30% zapotrzebowania kalorycznego, 4kcal/g\nWęglowodany: 40% zapotrzbowania kalorycznego, 4kcal/g\nTłuszcze: 30% zapotrzbowania kalorycznego, 9kcal/g"
			}
		}
	}

	FolderDialog {
		id: folderDialog
		currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
		onAccepted: MacroHandler.exportToFile(currentFolder)
	}
}