import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    width: window.width
    height: window.height

    Column {
        anchors.centerIn: parent
        spacing: 5

        Text {
            text: qsTr("Translate me")
            anchors.horizontalCenter: deButton.horizontalCenter
        }

        Button {
            id: deButton
            text: "de"
            onClicked: { window.langChangePressed("de"); }
        }

        Button {
            id: frButton
            text: "fr"
            onClicked: { window.langChangePressed("fr"); }
        }
    }
}
