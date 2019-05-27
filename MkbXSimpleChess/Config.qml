import QtQuick 2.0
import QtQuick.Controls 2.4

Item {
    id:configMoule
    width: parent.width
    height: parent.height
    Rectangle {
        anchors.fill:parent
        color:"#000000"
        opacity: 0.8

        Rectangle {
            width: 650
            height: 500
            anchors.centerIn: parent
            color:"white"
            border.color: "#04212B"
            border.width: 3
            radius: 7

            Image {
                id: logo
                anchors.top: parent.top
                anchors.topMargin: 10
                anchors.horizontalCenter: parent.horizontalCenter
                source: "chessImages/MkbX.png"
                Text {
                    anchors.centerIn: parent
                    font.family: "Georgia"
                    font.italic: true
                    font.pointSize: 22
                    smooth: true
                    color: "white"
                    style: Text.Outline
                    opacity:0.7
                    styleColor: "black"
                    text: french.checked ? "Échecs" : "Chess"
                }
            }

            Rectangle{
                id:newGameFrame
                width:400; height:120
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 15
                anchors.right: parent.right
                anchors.rightMargin: 20
                color: "transparent"
                border.color: "#eeeeee"
                border.width: 2
                radius: 5
                opacity:0.7

                Text{
                    anchors.top: parent.top
                    anchors.topMargin: -25
                    anchors.right: parent.right
                    anchors.rightMargin: 2
                    font.family: "Times New Roman"
                    font.italic: true
                    font.pointSize: 15
                    color: "#2f3030"
                    text: french.checked ? "Nouvelle partie" : "New Game"

                }

            }

            Column {
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                anchors.right: parent.right
                anchors.top: logo.bottom
                anchors.margins: 10
                spacing: 10



                Text {
                    id: configText
                    width: parent.width-15
                    anchors.horizontalCenter: parent.horizontalCenter
                    wrapMode: Text.WordWrap
                    horizontalAlignment: Text.AlignHCenter
                    font.family: "Georgia"
                    font.pointSize: 15
                    text: french.checked ? "\n  Bonjour et bienvenue sur MkbX - jeu d'échecs!\n " +
                    "\nCréé par goût des échecs et comme occasion de pratiquer les" +
                    " langages C++ et QML sous Qt, ce petit programme, pour deux" +
                    "\n joueurs, implémente les règles basiques du jeu."+
                    "\n (En passant et roque incluses.)"+
                    "\n\n      Amusez-vous bien! :)\n\n" :
                    "\n  Hi and welcome to MkbX - chess game!\n " +
                    "\nCreated out of love for chess and to practice C++" +
                    " \n along with Qt-QML languages, this two-player" +
                    "\n  little program implements basic rules of the game."+
                    "\n (En passant and castling embedded.)"+
                    "\n\n      Have fun! :)\n\n"
                        }


                Row {
                    anchors.left: parent.left
                    anchors.leftMargin: 100
                    spacing: 50
                    width: 200
                    Column {

                        Text{
                            font.family: "Georgia"
                            font.italic: true
                            font.pointSize: 13
                            text: french.checked ? "Langue" : "Language"

                        }

                        RadioButton {
                            id:french
                            checked: true
                            text: "Français"
                            onClicked: {mkbxChessBoard.tongue=french.checked;/*console.log(mkbxChessBoard.tongue)*/}
                        }
                        RadioButton {
                            id:anglais
                            text: "English"
                            onClicked: {mkbxChessBoard.tongue=french.checked;/*console.log(mkbxChessBoard.tongue)*/}
                        }

                    }
                    Column {

                        Text{
                            font.family: "Georgia"
                            font.italic: true
                            font.pointSize: 13
                            text: french.checked ? "Orientation de l'échiquier" : "Board orientation"


                        }

                        RadioButton {
                            id:classic
                            checked: true
                            text: french.checked ? "Noirs haut / Blancs bas" : "Black on top / White at bottom"

                        }
                        RadioButton {
                            id:inverted
                            text: french.checked ? "Blancs haut / Noirs bas" : "White on top / Black at bottom"

                        }
                    }
                    ButtonCustZ {
                        id: playButton
                        anchors.top: parent.top
                        anchors.topMargin: 30
                        width: 120 ; height: 60
                        text: french.checked ? "Duel !" : "Begin !"
                        onClicked: {configMoule.state="auRevoir"; mkbxChessBoard.choixPlayer=classic.checked; mkbxChessBoard.choixPlayer ? mkbxChessBoard.initW() : mkbxChessBoard.initB()}
                    }

                }
            }



        }


    }

    states: [
    State {
        name: "auRevoir"
        PropertyChanges {
            target: configMoule
            opacity: 0
            x: configMoule.width
        }
    }
    ]

    transitions: Transition {
        NumberAnimation {
            properties: "opacity, x"
            duration: 150
        }
    }



}
