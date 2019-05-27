#ifndef KNIGHT_H
#define KNIGHT_H

#include "chesspiece.h"

/**
 * @brief The Knight class; Inherits ChessPiece class; Move in an "L pattern";
 */

class Knight : public ChessPiece
{
        Q_OBJECT

public:

    Knight(quint8 indexLocationKt, bool colorKt);
    QVector<quint8> trivialCanMoveTo();
    QVector<quint8> trivialCanMoveToAttack();
    QVector<quint8> trivialCanMoveToAttackIllu();

};

#endif // KNIGHT_H
