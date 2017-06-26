import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    signal langChangePressed(string lang)

//    Alternative, when using connections in C++
//    function reload() {
//        mainLoader.setSource("mainWindow.qml");
//    }

    Connections {
        target: translator
        onTranslatorChanged: {
            mainLoader.setSource("mainWindow.qml");
            window.title = qsTr("Hello World");
        }
    }

    Loader {
        id: mainLoader

        width: parent.width
        height: parent.height

        source: "mainWindow.qml"
    }
}
