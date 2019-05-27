import QtQuick 2.9
import QtQuick.Window 2.2


Item {

    width: 800
    height: 800


    Rectangle {
      id: background
      anchors.fill: parent
      border.width: 1
      border.color: "#020921"
      gradient: Gradient {
          GradientStop { position: 0.0; color: "#dddddd" }
          GradientStop { position: 1.0; color: "#ffffff" }


      }

    }

    Text {
        visible: !mkbxChessBoard.getPromo ? true : false
        id:jeuEndGame
        anchors.top: parent.top
        anchors.topMargin: 5
        x: 330
        opacity: 0
        font.weight: Font.Light; font.family: "Colibri"; font.pointSize: 25;
        color: "#b50000"; width: 50; height: 50;/* font.italic: true*/
        text:
            if(mkbxChessBoard.tongue===true){
                if(mkbxChessBoard.endMateOrStale=="checkmate"){
                    "Échec et mat";

                }
               else if(mkbxChessBoard.endMateOrStale=="stalemate"){
                    "Pat - partie nulle";

                }
                else
                    ""

            }

            else{
                if(mkbxChessBoard.endMateOrStale=="checkmate"){
                    "Checkmate";

                }
                else if(mkbxChessBoard.endMateOrStale=="stalemate"){
                    "Stalemate - draw";

                }
                else
                    ""

            }
        states: [
        State {
            name: "showEnd"
            when: mkbxChessBoard.endMateOrStale != "playing"
            PropertyChanges {
                target: jeuEndGame
                opacity: 1.0
            }
        }
        ]

        transitions: Transition {
            NumberAnimation {
                properties: "opacity"
                duration: 500
            }
        }



    }

    Text {
        visible: !mkbxChessBoard.getPromo ? true : false
        id:colorToMove
        anchors.top: parent.top
        anchors.topMargin: 5
        x: 555
        color: mkbxChessBoard.aMonTour ? "#ffffff" : "#000000"; width: 50; height: 50; font.italic: true
        font.weight: Font.Light; font.family: "Times New Roman"; font.pointSize: 25;
        text:
            if(mkbxChessBoard.tongue===true){
                if(mkbxChessBoard.aMonTour===true){
                    "Trait aux Blancs";

                }
                else{
                     "Trait aux Noirs";
                }

            }

            else{
                if(mkbxChessBoard.aMonTour===true){
                    "White to move";

                }
                else{
                    "Black to move";
                }

            }



                states: [
                State {
                    name: "plusDeTour"
                    when: mkbxChessBoard.endMateOrStale != "playing"
                    PropertyChanges {
                        target: colorToMove
                        opacity: 0
                    }
                }
                ]

                transitions: Transition {
                    NumberAnimation {
                        properties: "opacity"
                        duration: 20
                    }
                }
    }

    Rectangle{
        id: gridBackground
        visible: !mkbxChessBoard.getPromo ? true : false
        width: 692
        height: 692
        color: "#04212B"
        radius: 7
        anchors.centerIn: parent
    Grid {
        id: chessGrid
        rows:8
        columns: 8
        anchors.centerIn: parent

        Repeater {
            model: mkbxChessBoard.chessboard
            ChessSquare{}
        }
    }

    //Row headers
    Text {
        id:pivotFirstLabel
        anchors.left: parent.left
        anchors.leftMargin: 40
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -50

        text: mkbxChessBoard.choixPlayer===true ? "A" : "H"; font.weight: Font.Light; font.family: "Times New Roman"; font.pointSize: 25; color: "#3d3d3d"; width: 50; height: 50

    }

    Text {
        anchors.left: pivotFirstLabel.left
        anchors.leftMargin: 85
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -50

        text: mkbxChessBoard.choixPlayer===true ? "B" : "G"; font.weight: Font.Light; font.family: "Times New Roman"; font.pointSize: 25; color: "#3d3d3d"; width: 50; height: 50

    }

    Text {
        anchors.left: pivotFirstLabel.left
        anchors.leftMargin: 170
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -50

        text: mkbxChessBoard.choixPlayer===true ? "C" : "F"; font.weight: Font.Light; font.family: "Times New Roman"; font.pointSize: 25; color: "#3d3d3d"; width: 50; height: 50

    }
    Text {
        anchors.left: pivotFirstLabel.left
        anchors.leftMargin: 255
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -50

        text: mkbxChessBoard.choixPlayer===true ? "D" : "E"; font.weight: Font.Light; font.family: "Times New Roman"; font.pointSize: 25; color: "#3d3d3d"; width: 50; height: 50

    }
    Text {
        anchors.left: pivotFirstLabel.left
        anchors.leftMargin: 340
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -50

        text: mkbxChessBoard.choixPlayer===true ? "E" : "D"; font.weight: Font.Light; font.family: "Times New Roman"; font.pointSize: 25; color: "#3d3d3d"; width: 50; height: 50

    }
    Text {
        anchors.left: pivotFirstLabel.left
        anchors.leftMargin: 425
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -50

        text: mkbxChessBoard.choixPlayer===true ? "F" : "C"; font.weight: Font.Light; font.family: "Times New Roman"; font.pointSize: 25; color: "#3d3d3d"; width: 50; height: 50

    }
    Text {
        anchors.left: pivotFirstLabel.left
        anchors.leftMargin: 510
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -50

        text: mkbxChessBoard.choixPlayer===true ? "G" : "B"; font.weight: Font.Light; font.family: "Times New Roman"; font.pointSize: 25; color: "#3d3d3d"; width: 50; height: 50

    }
    Text {
        anchors.left: pivotFirstLabel.left
        anchors.leftMargin: 595
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -50

        text: mkbxChessBoard.choixPlayer===true ? "H" : "A"; font.weight: Font.Light; font.family: "Times New Roman"; font.pointSize: 25; color: "#3d3d3d"; width: 50; height: 50

    }

  //Column headers

    Text {
        anchors.top: parent.top
        anchors.topMargin: 30
        anchors.left: parent.left
        anchors.leftMargin: -30

        text: mkbxChessBoard.choixPlayer===true ? "8" : "1"; font.weight: Font.Light; font.family: "Times New Roman"; font.pointSize: 25; color: "#3d3d3d"; width: 50; height: 50
    }

    Text {
        anchors.top: parent.top
        anchors.topMargin: 115
        anchors.left: parent.left
        anchors.leftMargin: -30

        text: mkbxChessBoard.choixPlayer===true ? "7" : "2"; font.weight: Font.Light; font.family: "Times New Roman"; font.pointSize: 25; color: "#3d3d3d"; width: 50; height: 50

    }

    Text {
        anchors.top: parent.top
        anchors.topMargin: 200
        anchors.left: parent.left
        anchors.leftMargin: -30

        text: mkbxChessBoard.choixPlayer===true ? "6" : "3"; font.weight: Font.Light; font.family: "Times New Roman"; font.pointSize: 25; color: "#3d3d3d"; width: 50; height: 50
    }

    Text {
        anchors.top: parent.top
        anchors.topMargin: 285
        anchors.left: parent.left
        anchors.leftMargin: -30

        text: mkbxChessBoard.choixPlayer===true ? "5" : "4"; font.weight: Font.Light; font.family: "Times New Roman"; font.pointSize: 25; color: "#3d3d3d"; width: 50; height: 50
    }

    Text {
        anchors.top: parent.top
        anchors.topMargin: 370
        anchors.left: parent.left
        anchors.leftMargin: -30

        text: mkbxChessBoard.choixPlayer===true ? "4" : "5"; font.weight: Font.Light; font.family: "Times New Roman"; font.pointSize: 25; color: "#3d3d3d"; width: 50; height: 50

    }

    Text {
        anchors.top: parent.top
        anchors.topMargin: 455
        anchors.left: parent.left
        anchors.leftMargin: -30

        text: mkbxChessBoard.choixPlayer===true ? "3" : "6"; font.weight: Font.Light; font.family: "Times New Roman"; font.pointSize: 25; color: "#3d3d3d"; width: 50; height: 50
    }

    Text {
        anchors.top: parent.top
        anchors.topMargin: 540
        anchors.left: parent.left
        anchors.leftMargin: -30

        text: mkbxChessBoard.choixPlayer===true ? "2" : "7"; font.weight: Font.Light; font.family: "Times New Roman"; font.pointSize: 25; color: "#3d3d3d"; width: 50; height: 50
    }

    Text {
        anchors.top: parent.top
        anchors.topMargin: 625
        anchors.left: parent.left
        anchors.leftMargin: -30

        text: mkbxChessBoard.choixPlayer===true ? "1" : "8"; font.weight: Font.Light; font.family: "Times New Roman"; font.pointSize: 25; color: "#3d3d3d"; width: 50; height: 50

    }






    }

    Rectangle {
        id:promoInterface
        visible: mkbxChessBoard.getPromo ? true : false
        x:350;y:120


        Column{
            spacing : 77
            anchors.top: parent.top

            PromoClic {
                id: firstQueen
                source: mkbxChessBoard.finishPromotionIsWhite ? "chessImages/WQueen.png" : "chessImages/BQueen.png"
                onClicked: {mkbxChessBoard.promoPieceChoice=1;mkbxChessBoard.finishPromotion();mkbxChessBoard.getPromo=false}


            }

            PromoClic {
                id: secondRook
                source: mkbxChessBoard.finishPromotionIsWhite ? "chessImages/WRook.png" : "chessImages/BRook.png"
                onClicked: {mkbxChessBoard.promoPieceChoice=2;mkbxChessBoard.finishPromotion();mkbxChessBoard.getPromo=false}

            }

            PromoClic {
                id: thirdBishop
                source: mkbxChessBoard.finishPromotionIsWhite ? "chessImages/WBishop.png" : "chessImages/BBishop.png"
                onClicked: {mkbxChessBoard.promoPieceChoice=3;mkbxChessBoard.finishPromotion();mkbxChessBoard.getPromo=false}

            }

            PromoClic {
                id: lastKnight
                source: mkbxChessBoard.finishPromotionIsWhite ? "chessImages/WKnight.png" : "chessImages/BKnight.png"
                onClicked: {mkbxChessBoard.promoPieceChoice=4;mkbxChessBoard.finishPromotion();mkbxChessBoard.getPromo=false}

            }

        }

    }

    Config {
        id: configWindow

    }


    Rectangle {
        id: menuShowRect
        x: 787 ; y:54
        width: 15; height:692
        radius:5
        color:"#000000"
        opacity: 0.7
            PromoClic {
                id: menuShow
                anchors.centerIn: parent
                x: 750 ; y: 500
                mirror: configWindow.state=="" ? true : false
                source: "chessImages/menuShow.png"
                 onClicked:{
                     if(configWindow.state=="")
                         configWindow.state="auRevoir"
                     else if(configWindow.state=="auRevoir")
                         configWindow.state=""
                 }
            }


    }

}
