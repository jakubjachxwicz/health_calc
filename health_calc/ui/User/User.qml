import QtQuick 2.3
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Dialogs

ColumnLayout
{
	width: parent.width * .8
	anchors.horizontalCenter: parent.horizontalCenter

	Label
	{
		horizontalAlignment: Text.AlignHCenter
		Layout.fillWidth: true
		Layout.fillHeight: true

		wrapMode: Text.WrapAnywhere
		padding: 36
		text: "Dane użytkownika"
		font.pixelSize: 36
	}

	RowLayout
	{
		ColumnLayout
		{
			Label
			{
				Layout.fillWidth: true
				Layout.fillHeight: true
				text: "Imię"
			}
			Label
			{
				Layout.fillWidth: true
				Layout.fillHeight: true
				text: "Nazwisko"
			}
			Label
			{
				Layout.fillWidth: true
				Layout.fillHeight: true
				text: "Wiek"
			}
			Label
			{
				Layout.fillWidth: true
				Layout.fillHeight: true
				text: "Waga"
			}
			Label
			{
				Layout.fillWidth: true
				Layout.fillHeight: true
				text: "Wzrost"
			}
			Label
			{
				Layout.fillWidth: true
				Layout.fillHeight: true
				text: "Płeć"
			}
		}
		ColumnLayout
		{
			TextField
			{
				Layout.fillWidth: true
				Layout.fillHeight: true
				onEditingFinished: UserHandler.setFirstName(text)
				text: UserHandler.firstName
			}
			TextField
			{
				Layout.fillWidth: true
				Layout.fillHeight: true
				onEditingFinished: UserHandler.setLastName(text)
				text: UserHandler.lastName
			}
			TextField
			{
				Layout.fillWidth: true
				Layout.fillHeight: true
				onEditingFinished: UserHandler.setAge(text)
				text: UserHandler.age
			}
			TextField
			{
				Layout.fillWidth: true
				Layout.fillHeight: true
				onEditingFinished: UserHandler.setWeight(text)
				text: UserHandler.weight
			}
			TextField
			{
				Layout.fillWidth: true
				Layout.fillHeight: true
				onEditingFinished: UserHandler.setHeight(text)
				text: UserHandler.height
			}
			RowLayout {
				RadioButton {
					id: femaleRadioButton
					
					Layout.fillHeight: true

					text: qsTr("K")
					checked: (UserHandler.isMale ? false : true)
					MouseArea {
						anchors.fill: parent
						onClicked: UserHandler.setIsMale(false);
					}
				}
				RadioButton {
					id: maleRadioButton

					Layout.fillHeight: true

					text: qsTr("M")
					checked: (UserHandler.isMale ? true : false)
					MouseArea {
						anchors.fill: parent
						onClicked: UserHandler.setIsMale(true);
					}
				}
			}
		}
	}

	Button {
		// Layout.fillHeight: true
		anchors.horizontalCenter: parent
	
		text: qsTr("Zapisz")
		implicitWidth: 213
		implicitHeight: 41

		onClicked: UserHandler.save();
	}
}