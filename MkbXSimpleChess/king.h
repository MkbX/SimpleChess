#ifndef KING_H
#define KING_H

#include "chesspiece.h"

/**
 * @brief The King class; Inherits ChessPiece class; Move one square in every direction;
 */

class King : public ChessPiece
{
        Q_OBJECT

public:

    King(quint8 indexLocationK, bool colorK);
    QVector<quint8> trivialCanMoveTo();
    QVector<quint8> trivialCanMoveToAttack();
    QVector<quint8> trivialCanMoveToAttackIllu();


};

#endif // KING_H
