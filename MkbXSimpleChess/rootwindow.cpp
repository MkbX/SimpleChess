#include "rootwindow.h"

RootWindow::RootWindow()
{


    setTitle("MkbX Échecs/Chess");
    setResizeMode(QQuickView::SizeRootObjectToView);
    setMaximumSize(QSize(800,800));
    setMinimumSize(QSize(800,800));
    setIcon(QIcon(QPixmap(":/chessImages/MkbXLogo.png")));

   //"enregistre" en QML les classes C++
   qmlRegisterType<ChessSquare>("ChessSquareQml", 1, 0, "ChessSquare");
   qmlRegisterType<ChessPiece>("ChessPieceQml", 1, 0, "ChessPiece");

   //"enregistre" des objets C++ spécifiques à appeler depuis QML
    m_context = rootContext();
    m_context->setContextProperty("rootWindow", this);
    m_context->setContextProperty("mkbxChessBoard", &m_uniqueChessBoard);
    setSource(QUrl("qrc:/main.qml"));
}
