import QtQuick 2.0

Item {

    id: piece

    Image {
        id: pieceImage
        anchors.centerIn: parent

        source: {
            if(modelData.piece===null) {return ""}

            if (modelData.piece.type === "BB") {return "chessImages/BBishop.png"}
            if (modelData.piece.type === "BKt") {return "chessImages/BKnight.png"}
            if (modelData.piece.type === "BR") {return "chessImages/BRook.png"}
            if (modelData.piece.type === "BQ") {return "chessImages/BQueen.png"}
            if (modelData.piece.type === "BK") {return "chessImages/BKing.png"}
            if (modelData.piece.type === "BPn") {return "chessImages/BPawn.png"}

            if (modelData.piece.type === "WB") {return "chessImages/WBishop.png"}
            if (modelData.piece.type === "WKt") {return "chessImages/WKnight.png"}
            if (modelData.piece.type === "WR") {return "chessImages/WRook.png"}
            if (modelData.piece.type === "WQ") {return "chessImages/WQueen.png"}
            if (modelData.piece.type === "WK") {return "chessImages/WKing.png"}
            if (modelData.piece.type === "WPn") {return "chessImages/WPawn.png"}

        }

    }


}
