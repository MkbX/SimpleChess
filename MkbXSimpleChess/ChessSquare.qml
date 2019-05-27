import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {

    id: square
    width: 85
    height: 85

    Rectangle {
        id: squareRect
        anchors.fill: parent
        color:  (parseInt(index / 8) + index) % 2 == 0 ? "#FDE4BB" : "#BF8E65"
        border.color: "#F5F5F5"; border.width: 0



        ChessPiece {
            id:squarePiece
            anchors.centerIn: parent
        }
//        Texte pour avoir le numéro de chaque case de visu
//        Text {
//            anchors.centerIn: parent
//            text: modelData.indexHexa ; font.pointSize: 25; color: "white"; width: 50; height: 50
//        }
        states: [
            State {
                name: "selected" ; when: modelData.selected===true
                PropertyChanges { target: squareRect; color:"#FFF699" ; border.color: "#FFDF4F"}
            },

            State {
                name: "destiSelected" ; when: modelData.destiSelected===true
                PropertyChanges { target: squareRect; color:"#53813D" /*53813D*/;  border.color: "#F5F5F5" ; border.width: 3;}
            },

            State {
                name: "check" ; when: modelData.check===true
                PropertyChanges { target: squareRect; color:"red";}
            },
            State {
                name: "castlingSelected" ; when: modelData.castlingSelected===true
                PropertyChanges { target: squareRect; color:"#fce399";}
            }

        ]
    }


    MouseArea {
        anchors.fill: parent
        onClicked: {mkbxChessBoard.mouseClick(index);/*console.log(modelData.indexHexa,modelData.piece.type,modelData.piece.squareLocation);*/}
    }


}
