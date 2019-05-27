#include "king.h"
#include "chessboard.h"

King::King(quint8 indexLocationK, bool colorK):ChessPiece (indexLocationK,colorK)
{
    m_type = (colorK ? "WK" : "BK");    
    m_classeKing = "KingClass";
    m_petitRoqueDispo=true;
    m_grandRoqueDispo=true;
}

QVector<quint8> King::trivialCanMoveTo()
{
    QVector<quint8> allDest(10,127);

    allDest[0]=this->squareLocation()-15;
    allDest[1]=this->squareLocation()-16;
    allDest[2]=this->squareLocation()-17;
    allDest[3]=this->squareLocation()-1;
    allDest[4]=this->squareLocation()+15;
    allDest[5]=this->squareLocation()+16;
    allDest[6]=this->squareLocation()+17;
    allDest[7]=this->squareLocation()+1;

    if(this->petitRoqueDispo()==true){
        if(this->isWhite()==true){
            if((this->squareLocation()==116)
                    && (this->moveCount()==0)
                    && (ChessBoard::getPiece(117)==nullptr)
                    && (ChessBoard::getPiece(118)==nullptr)
                    && (ChessBoard::getPiece(119)!=nullptr)
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),116) !=ChessBoard::m_vectorMaquis.end())
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),117) !=ChessBoard::m_vectorMaquis.end())
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),118) !=ChessBoard::m_vectorMaquis.end())
                    && (ChessBoard::getPiece(119)->moveCount()==0))
                allDest[8]=118;

            if((this->squareLocation()==3)
                    && (this->moveCount()==0)
                    && (ChessBoard::getPiece(2)==nullptr)
                    && (ChessBoard::getPiece(1)==nullptr)
                    && (ChessBoard::getPiece(0)!=nullptr)
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),3) !=ChessBoard::m_vectorMaquis.end())
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),2) !=ChessBoard::m_vectorMaquis.end())
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),1) !=ChessBoard::m_vectorMaquis.end())
                    && (ChessBoard::getPiece(0)->moveCount()==0))
                allDest[8]=1;

        }
        else {
            if((this->squareLocation()==115)
                    && (this->moveCount()==0)
                    && (ChessBoard::getPiece(114)==nullptr)
                    && (ChessBoard::getPiece(113)==nullptr)
                    && (ChessBoard::getPiece(112)!=nullptr)
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),115) !=ChessBoard::m_vectorMaquis.end())
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),114) !=ChessBoard::m_vectorMaquis.end())
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),113) !=ChessBoard::m_vectorMaquis.end())
                    && (ChessBoard::getPiece(112)->moveCount()==0))
                allDest[8]=113;

            if((this->squareLocation()==4)
                    && (this->moveCount()==0)
                    && (ChessBoard::getPiece(5)==nullptr)
                    && (ChessBoard::getPiece(6)==nullptr)
                    && (ChessBoard::getPiece(7)!=nullptr)
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),4) !=ChessBoard::m_vectorMaquis.end())
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),5) !=ChessBoard::m_vectorMaquis.end())
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),6) !=ChessBoard::m_vectorMaquis.end())
                    && (ChessBoard::getPiece(7)->moveCount()==0))
                allDest[8]=6;

        }

    }

    if(this->grandRoqueDispo()==true){
        if(this->isWhite()==true){
            if((this->squareLocation()==116)
                    && (this->moveCount()==0)
                    && (ChessBoard::getPiece(113)==nullptr)
                    && (ChessBoard::getPiece(114)==nullptr)
                    && (ChessBoard::getPiece(115)==nullptr)
                    && (ChessBoard::getPiece(112)!=nullptr)
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),116) !=ChessBoard::m_vectorMaquis.end())
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),115) !=ChessBoard::m_vectorMaquis.end())
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),114) !=ChessBoard::m_vectorMaquis.end())
                    && (ChessBoard::getPiece(112)->moveCount()==0))
                allDest[9]=114;

            if((this->squareLocation()==3)
                    && (this->moveCount()==0)
                    && (ChessBoard::getPiece(4)==nullptr)
                    && (ChessBoard::getPiece(5)==nullptr)
                    && (ChessBoard::getPiece(6)==nullptr)
                    && (ChessBoard::getPiece(7)!=nullptr)
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),3) !=ChessBoard::m_vectorMaquis.end())
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),4) !=ChessBoard::m_vectorMaquis.end())
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),5) !=ChessBoard::m_vectorMaquis.end())
                    && (ChessBoard::getPiece(7)->moveCount()==0))
                allDest[9]=5;



        }
        else {
            if((this->squareLocation()==115)
                    && (this->moveCount()==0)
                    && (ChessBoard::getPiece(116)==nullptr)
                    && (ChessBoard::getPiece(117)==nullptr)
                    && (ChessBoard::getPiece(118)==nullptr)
                    && (ChessBoard::getPiece(119)!=nullptr)
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),115) !=ChessBoard::m_vectorMaquis.end())
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),116) !=ChessBoard::m_vectorMaquis.end())
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),117) !=ChessBoard::m_vectorMaquis.end())
                    && (ChessBoard::getPiece(119)->moveCount()==0))
                allDest[9]=117;

            if((this->squareLocation()==4)
                    && (this->moveCount()==0)
                    && (ChessBoard::getPiece(3)==nullptr)
                    && (ChessBoard::getPiece(2)==nullptr)
                    && (ChessBoard::getPiece(1)==nullptr)
                    && (ChessBoard::getPiece(0)!=nullptr)
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),4) !=ChessBoard::m_vectorMaquis.end())
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),3) !=ChessBoard::m_vectorMaquis.end())
                    && !(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),2) !=ChessBoard::m_vectorMaquis.end())
                    && (ChessBoard::getPiece(0)->moveCount()==0))
                allDest[9]=2;

        }

    }




    for (quint8 i=0; i<8; i++) {
        if(std::find(ChessBoard::m_vectorMaquis.begin(),ChessBoard::m_vectorMaquis.end(),allDest[i]) !=ChessBoard::m_vectorMaquis.end())
            allDest[i]=127;
        }


    return allDest;
}

QVector<quint8> King::trivialCanMoveToAttack()
{
    QVector<quint8> allDestAttack(8,127);

    allDestAttack[0]=this->squareLocation()-15;
    allDestAttack[1]=this->squareLocation()-16;
    allDestAttack[2]=this->squareLocation()-17;
    allDestAttack[3]=this->squareLocation()-1;
    allDestAttack[4]=this->squareLocation()+15;
    allDestAttack[5]=this->squareLocation()+16;
    allDestAttack[6]=this->squareLocation()+17;
    allDestAttack[7]=this->squareLocation()+1;



    return allDestAttack;

}

QVector<quint8> King::trivialCanMoveToAttackIllu()
{
    QVector<quint8> allDeskAttackIllu(8,127);

    allDeskAttackIllu[0]=this->squareLocation()-15;
    allDeskAttackIllu[1]=this->squareLocation()-16;
    allDeskAttackIllu[2]=this->squareLocation()-17;
    allDeskAttackIllu[3]=this->squareLocation()-1;
    allDeskAttackIllu[4]=this->squareLocation()+15;
    allDeskAttackIllu[5]=this->squareLocation()+16;
    allDeskAttackIllu[6]=this->squareLocation()+17;
    allDeskAttackIllu[7]=this->squareLocation()+1;



    return allDeskAttackIllu;
}
