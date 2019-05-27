#include "pawn.h"
#include "chessboard.h"
#include "bishop.h"
#include "knight.h"
#include "queen.h"
#include "rook.h"

Pawn::Pawn(quint8 indexLocationPn, bool colorPn):ChessPiece (indexLocationPn,colorPn)
{
     m_type = (colorPn ? "WPn" : "BPn");
}

QVector<quint8> Pawn::trivialCanMoveTo()
{
    QVector<quint8> allDest(5,127);

    if(ChessBoard::m_choixPlayer==true){
        if(this->isWhite()==true){
            if((ChessBoard::getPiece(this->squareLocation()-15)!=nullptr)
                           &&(ChessBoard::getPiece(this->squareLocation()-15)->isWhite()!=this->isWhite()))
                       allDest[0]=this->squareLocation()-15;

            if((ChessBoard::getPiece(this->squareLocation()-17)!=nullptr)
                           &&(ChessBoard::getPiece(this->squareLocation()-17)->isWhite()!=this->isWhite()))
                       allDest[1]=this->squareLocation()-17;

            if(ChessBoard::getPiece(this->squareLocation()-16)==nullptr)
                allDest[2]=this->squareLocation()-16;

            if(((ChessBoard::getPiece(this->squareLocation()-16)==nullptr))&&(ChessBoard::getPiece(this->squareLocation()-32)==nullptr)){
            if(this->squareLocation()==96||this->squareLocation()==97||this->squareLocation()==98||this->squareLocation()==99
                    ||this->squareLocation()==100||this->squareLocation()==101||this->squareLocation()==102||this->squareLocation()==103)
                allDest[3]=this->squareLocation()-32;}

            if((ChessBoard::getPiece(this->squareLocation()-1)!=nullptr)&&(ChessBoard::getPiece(this->squareLocation()-1)->enPassant()==1)){
                allDest[4]=this->squareLocation()-17;
            }
            else if((ChessBoard::getPiece(this->squareLocation()+1)!=nullptr)&&(ChessBoard::getPiece(this->squareLocation()+1)->enPassant()==1)) {
                allDest[4]=this->squareLocation()-15;
            }
        }



        else {
            if((ChessBoard::getPiece(this->squareLocation()+15)!=nullptr)
                           &&(ChessBoard::getPiece(this->squareLocation()+15)->isWhite()!=this->isWhite()))
                       allDest[0]=this->squareLocation()+15;

            if((ChessBoard::getPiece(this->squareLocation()+17)!=nullptr)
                           &&(ChessBoard::getPiece(this->squareLocation()+17)->isWhite()!=this->isWhite()))
                       allDest[1]=this->squareLocation()+17;

            if(ChessBoard::getPiece(this->squareLocation()+16)==nullptr)
                allDest[2]=this->squareLocation()+16;

            if(((ChessBoard::getPiece(this->squareLocation()+16)==nullptr))&&(ChessBoard::getPiece(this->squareLocation()+32)==nullptr)){
            if(this->squareLocation()==16||this->squareLocation()==17||this->squareLocation()==18||this->squareLocation()==19
                    ||this->squareLocation()==20||this->squareLocation()==21||this->squareLocation()==22||this->squareLocation()==23)
                allDest[3]=this->squareLocation()+32;}

            if((ChessBoard::getPiece(this->squareLocation()-1)!=nullptr)&&(ChessBoard::getPiece(this->squareLocation()-1)->enPassant()==1)){
                allDest[4]=this->squareLocation()+15;
            }
            else if((ChessBoard::getPiece(this->squareLocation()+1)!=nullptr)&&(ChessBoard::getPiece(this->squareLocation()+1)->enPassant()==1)) {
                allDest[4]=this->squareLocation()+17;
            }

        }
    }
    else {
        if(this->isWhite()==true){
            if((ChessBoard::getPiece(this->squareLocation()+15)!=nullptr)
                           &&(ChessBoard::getPiece(this->squareLocation()+15)->isWhite()!=this->isWhite()))
                       allDest[0]=this->squareLocation()+15;

            if((ChessBoard::getPiece(this->squareLocation()+17)!=nullptr)
                           &&(ChessBoard::getPiece(this->squareLocation()+17)->isWhite()!=this->isWhite()))
                       allDest[1]=this->squareLocation()+17;

            if(ChessBoard::getPiece(this->squareLocation()+16)==nullptr)
                allDest[2]=this->squareLocation()+16;

            if(((ChessBoard::getPiece(this->squareLocation()+16)==nullptr))&&(ChessBoard::getPiece(this->squareLocation()+32)==nullptr)){
            if(this->squareLocation()==16||this->squareLocation()==17||this->squareLocation()==18||this->squareLocation()==19
                    ||this->squareLocation()==20||this->squareLocation()==21||this->squareLocation()==22||this->squareLocation()==23)
                allDest[3]=this->squareLocation()+32;}

            if((ChessBoard::getPiece(this->squareLocation()-1)!=nullptr)&&(ChessBoard::getPiece(this->squareLocation()-1)->enPassant()==1)){
                allDest[4]=this->squareLocation()+15;
            }
            else if((ChessBoard::getPiece(this->squareLocation()+1)!=nullptr)&&(ChessBoard::getPiece(this->squareLocation()+1)->enPassant()==1)) {
                allDest[4]=this->squareLocation()+17;
            }
        }

        else {
            if((ChessBoard::getPiece(this->squareLocation()-15)!=nullptr)
                           &&(ChessBoard::getPiece(this->squareLocation()-15)->isWhite()!=this->isWhite()))
                       allDest[0]=this->squareLocation()-15;

            if((ChessBoard::getPiece(this->squareLocation()-17)!=nullptr)
                           &&(ChessBoard::getPiece(this->squareLocation()-17)->isWhite()!=this->isWhite()))
                       allDest[1]=this->squareLocation()-17;

            if(ChessBoard::getPiece(this->squareLocation()-16)==nullptr)
                allDest[2]=this->squareLocation()-16;

            if(((ChessBoard::getPiece(this->squareLocation()-16)==nullptr))&&(ChessBoard::getPiece(this->squareLocation()-32)==nullptr)){
            if(this->squareLocation()==96||this->squareLocation()==97||this->squareLocation()==98||this->squareLocation()==99
                    ||this->squareLocation()==100||this->squareLocation()==101||this->squareLocation()==102||this->squareLocation()==103)
                allDest[3]=this->squareLocation()-32;}

            if((ChessBoard::getPiece(this->squareLocation()-1)!=nullptr)&&(ChessBoard::getPiece(this->squareLocation()-1)->enPassant()==1)){
                allDest[4]=this->squareLocation()-17;
            }
            else if((ChessBoard::getPiece(this->squareLocation()+1)!=nullptr)&&(ChessBoard::getPiece(this->squareLocation()+1)->enPassant()==1)) {
                allDest[4]=this->squareLocation()-15;
            }
        }


    }

return allDest;
}

bool Pawn::pawnPromotion() const
{
    if(ChessBoard::m_choixPlayer==true){
        if(this->isWhite()==true){
            return (this->squareLocation()==0||this->squareLocation()==1||this->squareLocation()==2||this->squareLocation()==3
                    ||this->squareLocation()==4||this->squareLocation()==5||this->squareLocation()==6||this->squareLocation()==7) ? true : false;


        }



        else {
            return (this->squareLocation()==112||this->squareLocation()==113||this->squareLocation()==114||this->squareLocation()==115
                    ||this->squareLocation()==116||this->squareLocation()==117||this->squareLocation()==118||this->squareLocation()==119) ? true : false;

        }
    }
    else {
        if(this->isWhite()==true){
            return (this->squareLocation()==112||this->squareLocation()==113||this->squareLocation()==114||this->squareLocation()==115
                    ||this->squareLocation()==116||this->squareLocation()==117||this->squareLocation()==118||this->squareLocation()==119) ? true : false;

        }

        else {
            return (this->squareLocation()==0||this->squareLocation()==1||this->squareLocation()==2||this->squareLocation()==3
                    ||this->squareLocation()==4||this->squareLocation()==5||this->squareLocation()==6||this->squareLocation()==7) ? true : false;

        }


    }
}

QVector<quint8> Pawn::trivialCanMoveToAttack()
{
    QVector<quint8> allDestAttack(2,127);

    if(ChessBoard::m_choixPlayer==true){
        if(this->isWhite()==true){
            allDestAttack[0]=this->squareLocation()-15;
            allDestAttack[1]=this->squareLocation()-17;

        }



        else {
            allDestAttack[0]=this->squareLocation()+15;
            allDestAttack[1]=this->squareLocation()+17;

        }
    }
    else {
        if(this->isWhite()==true){
            allDestAttack[0]=this->squareLocation()+15;
            allDestAttack[1]=this->squareLocation()+17;

        }

        else {
            allDestAttack[0]=this->squareLocation()-15;
            allDestAttack[1]=this->squareLocation()-17;

        }


    }


return allDestAttack;

}

QVector<quint8> Pawn::trivialCanMoveToAttackIllu()
{
    QVector<quint8> allDeskAttackIllu(2,127);

    if(ChessBoard::m_choixPlayer==true){
        if(this->isWhite()==true){
            allDeskAttackIllu[0]=this->squareLocation()-15;
            allDeskAttackIllu[1]=this->squareLocation()-17;

        }



        else {
            allDeskAttackIllu[0]=this->squareLocation()+15;
            allDeskAttackIllu[1]=this->squareLocation()+17;

        }
    }
    else {
        if(this->isWhite()==true){
            allDeskAttackIllu[0]=this->squareLocation()+15;
            allDeskAttackIllu[1]=this->squareLocation()+17;

        }

        else {
            allDeskAttackIllu[0]=this->squareLocation()-15;
            allDeskAttackIllu[1]=this->squareLocation()-17;

        }


    }


return allDeskAttackIllu;
}
