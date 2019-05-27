#ifndef QUEEN_H
#define QUEEN_H

#include "chesspiece.h"

/**
 * @brief The Queen class; Inherits ChessPiece class; Moves are combination of Bishop's moves and Rook's moves;
 */

class Queen : public ChessPiece
{
        Q_OBJECT

public:

    Queen(quint8 indexLocationQ, bool colorQ);
    QVector<quint8> trivialCanMoveTo();
    QVector<quint8> trivialCanMoveToAttack();
    QVector<quint8> trivialCanMoveToAttackIllu();
};

#endif // QUEEN_H
