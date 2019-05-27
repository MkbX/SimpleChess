#ifndef BISHOP_H
#define BISHOP_H



#include "chesspiece.h"

/**
 * @brief The Bishop class; Inherits ChessPiece class; Moves diagonally (sliding);
 */

class Bishop : public ChessPiece
{
        Q_OBJECT

public:

    Bishop(quint8 indexLocationB, bool colorB);
    QVector<quint8> trivialCanMoveTo();
    QVector<quint8> trivialCanMoveToAttack();
    QVector<quint8> trivialCanMoveToAttackIllu();

};

#endif // BISHOP_H
