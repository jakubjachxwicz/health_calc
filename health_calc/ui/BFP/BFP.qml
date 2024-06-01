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
		text: "BFP"
		font.pixelSize: 36
	}

	RowLayout {
		ColumnLayout {
			Label {
				Layout.fillWidth: true
				Layout.fillHeight: true
			
				horizontalAlignment: Text.AlignHCenter
				padding: 5
				text: "Płeć"
			}

			RowLayout {
				RadioButton {
					id: femaleRadioButton
					
					Layout.fillWidth: true
					Layout.fillHeight: true

					text: qsTr("K")
					checked: (BFPHandler.isMale ? false : true)
					MouseArea {
						anchors.fill: parent
						onClicked: BFPHandler.setIsMale(false);
					}
				}
				RadioButton {
					id: maleRadioButton

					Layout.fillWidth: true
					Layout.fillHeight: true

					text: qsTr("M")
					checked: (BFPHandler.isMale ? true : false)
					MouseArea {
						anchors.fill: parent
						onClicked: BFPHandler.setIsMale(true);
					}
				}
			}
		}
		ColumnLayout {
			Label {
				Layout.fillWidth: true
				Layout.fillHeight: true

				horizontalAlignment: Text.AlignHCenter
				padding: 5
				text: "Wiek (lata)"
			}

			TextField {
				Layout.fillWidth: true
				Layout.fillHeight: true
			
				onEditingFinished: BFPHandler.setAge(text)
				text: BFPHandler.age
			}
		}
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
			
				onEditingFinished: BFPHandler.setHeight(text)
				text: BFPHandler.height
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
			
				onEditingFinished: BFPHandler.setWeight(text)
				text: BFPHandler.weight
			}
		}
	}

	
	Rectangle {
		Layout.fillWidth: true
		Layout.fillHeight: true
		Layout.margins: 60
		color: BFPHandler.rectColor
		width: 100
		height: 100
		radius: 10

		Label {
			Layout.fillWidth: true
			Layout.fillHeight: true
			Layout.margins: 60

			width: parent.width
			horizontalAlignment: Text.AlignHCenter
			wrapMode: Text.WrapAnywhere
			padding: 16
			font.pixelSize: 16
			text: BFPHandler.resultMessage
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
				text: "BFP (Body Fat Percentage) to wskaźnik określający, jaki procent masy ciała danej osoby stanowi tłuszcz. Jest to ważny miernik zdrowia i kondycji fizycznej, pozwalający ocenić proporcje tkanki tłuszczowej w organizmie."
			}
			Text {
				Layout.fillWidth: true
				Layout.fillHeight: true	
				wrapMode: Text.WordWrap
				text: "Wzór:\nDla mężczyzn: (1.20*BMI) + (0.23*Wiek) – 16.2\nDla kobiet: (1.20*BMI) + (0.23*Wiek) – 5.4"
			}
		}
	}

	FolderDialog {
		id: folderDialog
		currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
		onAccepted: BFPHandler.exportToFile(currentFolder)
	}
}