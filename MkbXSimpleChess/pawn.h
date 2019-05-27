#ifndef PAWN_H
#define PAWN_H

#include "chesspiece.h"

/**
 * @brief The Pawn class; Inherits ChessPiece class; Move one square onward; Can move two squares in initial position; Capture diagonally;
 */

class Pawn : public ChessPiece
{
        Q_OBJECT

public:

    Pawn(quint8 indexLocationPn, bool colorPn);
    QVector<quint8> trivialCanMoveTo();
    bool pawnPromotion() const;
    QVector<quint8> trivialCanMoveToAttack();
    QVector<quint8> trivialCanMoveToAttackIllu();


};

#endif // PAWN_H
