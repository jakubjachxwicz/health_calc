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
		text: "Dzienne zapotrzebowanie kaloryczne"
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
					checked: (BMRHandler.isMale ? false : true)
					MouseArea {
						anchors.fill: parent
						onClicked: BMRHandler.setIsMale(false);
					}
				}
				RadioButton {
					id: maleRadioButton

					Layout.fillWidth: true
					Layout.fillHeight: true

					text: qsTr("M")
					checked: (BMRHandler.isMale ? true : false)
					MouseArea {
						anchors.fill: parent
						onClicked: BMRHandler.setIsMale(true);
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
			
				onEditingFinished: BMRHandler.setAge(text)
				text: BMRHandler.age
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
			
				onEditingFinished: BMRHandler.setHeight(text)
				text: BMRHandler.height
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
			
				onEditingFinished: BMRHandler.setWeight(text)
				text: BMRHandler.weight
			}
		}
	}

	Label {
		Layout.fillWidth: true
		Layout.fillHeight: true
		
		wrapMode: Text.WrapAnywhere
		horizontalAlignment: Text.AlignHCenter
		topPadding: 32
		bottomPadding: 16
		text: "Poziom aktywności fizycznej"
		font.pixelSize: 24
	}

	RowLayout {
		ColumnLayout {
			Label {
				Layout.fillWidth: true
				Layout.fillHeight: true

				horizontalAlignment: Text.AlignHCenter
				text: qsTr("Znikomy/brak")
			}

			RadioButton {
				// Layout.fillWidth: true
				anchors.horizontalCenter: parent.horizontalCenter
				Layout.fillHeight: true

				checked: (BMRHandler.activityLevel == 0 ? true : false)
				MouseArea {
					anchors.fill: parent
					onClicked: BMRHandler.setActivityLevel(0)
				}
			}
		}
		ColumnLayout {
			Label {
				Layout.fillWidth: true
				Layout.fillHeight: true

				horizontalAlignment: Text.AlignHCenter
				text: qsTr("Niski")
			}

			RadioButton {
				// Layout.fillWidth: true
				anchors.horizontalCenter: parent.horizontalCenter
				Layout.fillHeight: true

				checked: (BMRHandler.activityLevel == 1 ? true : false)
				MouseArea {
					anchors.fill: parent
					onClicked: BMRHandler.setActivityLevel(1)
				}
			}
		}
		ColumnLayout {
			Label {
				Layout.fillWidth: true
				Layout.fillHeight: true

				horizontalAlignment: Text.AlignHCenter
				text: qsTr("Przeciętny")
			}

			RadioButton {
				// Layout.fillWidth: true
				anchors.horizontalCenter: parent.horizontalCenter
				Layout.fillHeight: true

				checked: (BMRHandler.activityLevel == 2 ? true : false)
				MouseArea {
					anchors.fill: parent
					onClicked: BMRHandler.setActivityLevel(2)
				}
			}
		}
		ColumnLayout {
			Label {
				Layout.fillWidth: true
				Layout.fillHeight: true

				horizontalAlignment: Text.AlignHCenter
				text: qsTr("Wysoki")
			}

			RadioButton {
				// Layout.fillWidth: true
				anchors.horizontalCenter: parent.horizontalCenter
				Layout.fillHeight: true

				checked: (BMRHandler.activityLevel == 3 ? true : false)
				MouseArea {
					anchors.fill: parent
					onClicked: BMRHandler.setActivityLevel(3)
				}
			}
		}
		ColumnLayout {
			Label {
				Layout.fillWidth: true
				Layout.fillHeight: true

				horizontalAlignment: Text.AlignHCenter
				text: qsTr("Bardzo wysoki")
			}

			RadioButton {
				// Layout.fillWidth: true
				anchors.horizontalCenter: parent.horizontalCenter
				Layout.fillHeight: true

				checked: (BMRHandler.activityLevel == 4 ? true : false)
				MouseArea {
					anchors.fill: parent
					onClicked: BMRHandler.setActivityLevel(4)
				}
			}
		}
	}

	Label {
		Layout.fillWidth: true
		Layout.fillHeight: true
		Layout.margins: 60

		horizontalAlignment: Text.AlignHCenter
		wrapMode: Text.WrapAnywhere
		font.pixelSize: 16
		text: BMRHandler.resultMessage
	}

	Button {
		Layout.fillHeight: true
		anchors.right: parent.right

		text: qsTr("Eksportuj do pliku")
		implicitWidth: 213
		implicitHeight: 41
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
		width: 460

		contentItem: ColumnLayout {
			spacing: 20

			Text {
				Layout.fillWidth: true
				Layout.fillHeight: true
				wrapMode: Text.WordWrap
				text: "Dzienne zapotrzebowanie kaloryczne to ilość kalorii, którą organizm człowieka potrzebuje codziennie, aby utrzymać swoje podstawowe funkcje życiowe oraz poziom aktywności fizycznej. Jest to suma energii niezbędnej do podtrzymania procesów metabolicznych, oddychania, krążenia krwi, trawienia, regulacji temperatury ciała oraz wykonywania wszelkich czynności fizycznych."
			}
			Text {
				Layout.fillWidth: true
				Layout.fillHeight: true	
				wrapMode: Text.WordWrap
				text: "Wzór:\nDla mężczyzn: 66.47 + (13.75 * masa [kg]) + (5.003 * wzrost [cm]) − (6.755 * wiek [lata])\nDla kobiet: 655.1 + (9.563 * masa [kg]) + (1.85 * wzrost [cm]) − (4.676 * wiek [lata])\nDodatkowe mnożniki w zależności od poziomu aktywności fizycznej:\nZnikomy: 1,2\nLekki: 1,375\nPrzeciętny: 1,55\nWysoki: 1,725\nBardzo wysoki: 1,9"
			}
		}
	}
}