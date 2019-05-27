#ifndef ROOK_H
#define ROOK_H

#include "chesspiece.h"

/**
 * @brief The Rook class; Vertical and horizontal moves (sliding);
 */

class Rook : public ChessPiece
{
        Q_OBJECT

public:

    Rook(quint8 indexLocationR, bool colorR);
    QVector<quint8> trivialCanMoveTo();
    QVector<quint8> trivialCanMoveToAttack();
    QVector<quint8> trivialCanMoveToAttackIllu();
};

#endif // ROOK_H
