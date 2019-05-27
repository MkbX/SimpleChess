#ifndef ROOTWINDOW_H
#define ROOTWINDOW_H
#include <QQmlContext>
#include <QQuickView>
#include "chessboard.h"

/**
 * @brief The RootWindow class; C++ and QML linking window
 */

class RootWindow: public QQuickView
{
public:
    RootWindow();

private:
    QQmlContext *m_context;
    ChessBoard m_uniqueChessBoard;
};

#endif // ROOTWINDOW_H
