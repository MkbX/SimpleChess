import QtQuick 2.0
import QtQuick.Controls 2.4

Button {
    id: control
    text: qsTr("Button")


    contentItem: Text {
        color: "#253126"
        text: control.text
        font.family: "Georgia"
        font.bold: true
        font.italic: true
        font.pointSize: 17
        opacity: enabled ? 1.0 : 0.3
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        implicitWidth: 100
        implicitHeight: 40
        color: control.down ? "#000000" : "#e7e7e7"
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#ffffff" }
            GradientStop { position: 1.0; color: "#dddddd" }
        }
        border.color: control.down ? "#red" : "#21be2b"
        border.width: 1
        radius: 15
    }
}
