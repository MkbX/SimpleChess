import QtQuick 2.0


    Image {
        id: imClic
        signal clicked
        scale: imageMouseArea.containsMouse ? 2.0 : 1.2

       MouseArea{
           id:imageMouseArea
           anchors.fill: parent
           onClicked: imClic.clicked()
           hoverEnabled: true

       }
    }


