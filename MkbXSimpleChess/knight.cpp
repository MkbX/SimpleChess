#include "knight.h"

Knight::Knight(quint8 indexLocationKt, bool colorKt):ChessPiece (indexLocationKt, colorKt)
{
    m_type = (colorKt ? "WKt" : "BKt");
}

QVector<quint8> Knight::trivialCanMoveTo()
{
    QVector<quint8> allDest(8,127);

    allDest[0]=this->squareLocation()-14;
    allDest[1]=this->squareLocation()-31;
    allDest[2]=this->squareLocation()-33;
    allDest[3]=this->squareLocation()-18;
    allDest[4]=this->squareLocation()+14;
    allDest[5]=this->squareLocation()+31;
    allDest[6]=this->squareLocation()+33;
    allDest[7]=this->squareLocation()+18;

    return allDest;
}

QVector<quint8> Knight::trivialCanMoveToAttack()
{
    QVector<quint8> allDestAttack(8,127);
    allDestAttack[0]=this->squareLocation()-14;
    allDestAttack[1]=this->squareLocation()-31;
    allDestAttack[2]=this->squareLocation()-33;
    allDestAttack[3]=this->squareLocation()-18;
    allDestAttack[4]=this->squareLocation()+14;
    allDestAttack[5]=this->squareLocation()+31;
    allDestAttack[6]=this->squareLocation()+33;
    allDestAttack[7]=this->squareLocation()+18;

    return allDestAttack;
}

QVector<quint8> Knight::trivialCanMoveToAttackIllu()
{
    QVector<quint8> allDeskAttackIllu(8,127);
    allDeskAttackIllu[0]=this->squareLocation()-14;
    allDeskAttackIllu[1]=this->squareLocation()-31;
    allDeskAttackIllu[2]=this->squareLocation()-33;
    allDeskAttackIllu[3]=this->squareLocation()-18;
    allDeskAttackIllu[4]=this->squareLocation()+14;
    allDeskAttackIllu[5]=this->squareLocation()+31;
    allDeskAttackIllu[6]=this->squareLocation()+33;
    allDeskAttackIllu[7]=this->squareLocation()+18;

    return allDeskAttackIllu;
}
