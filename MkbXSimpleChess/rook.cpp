#include "rook.h"
#include "chessboard.h"

Rook::Rook(quint8 indexLocationR, bool colorR):ChessPiece (indexLocationR,colorR)
{
        m_type = (colorR ? "WR" : "BR");

}

QVector<quint8> Rook::trivialCanMoveTo()
{

    QVector<quint8> allDest(64,127);



    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()-16*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-16*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()-16*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-16*(i+1))->isWhite()!=this->isWhite())){
                       allDest[i]=this->squareLocation()-16*(i+1);
                       break;
                       }
        allDest[i]=(this->squareLocation()-(16*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()-1*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-1*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()-1*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-1*(i+1))->isWhite()!=this->isWhite())){
                       allDest[i+7]=this->squareLocation()-1*(i+1);
                       break;
                       }
        allDest[i+7]=(this->squareLocation()-(1*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()+16*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+16*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()+16*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+16*(i+1))->isWhite()!=this->isWhite())){
                       allDest[i+14]=this->squareLocation()+16*(i+1);
                       break;
                       }
        allDest[i+14]=(this->squareLocation()+(16*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()+1*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+1*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()+1*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+1*(i+1))->isWhite()!=this->isWhite())){
                       allDest[i+21]=this->squareLocation()+1*(i+1);
                       break;
                       }
        allDest[i+21]=(this->squareLocation()+(1*(i+1)));
    }


    return allDest;
}

QVector<quint8> Rook::trivialCanMoveToAttack()
{

    QVector<quint8> allDestAttack(64,127);



    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()-16*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-16*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()-16*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-16*(i+1))->isWhite()!=this->isWhite())){
                       allDestAttack[i]=this->squareLocation()-16*(i+1);
                       break;
                       }
        allDestAttack[i]=(this->squareLocation()-(16*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()-1*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-1*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()-1*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-1*(i+1))->isWhite()!=this->isWhite())){
                       allDestAttack[i+7]=this->squareLocation()-1*(i+1);
                       break;
                       }
        allDestAttack[i+7]=(this->squareLocation()-(1*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()+16*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+16*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()+16*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+16*(i+1))->isWhite()!=this->isWhite())){
                       allDestAttack[i+14]=this->squareLocation()+16*(i+1);
                       break;
                       }
        allDestAttack[i+14]=(this->squareLocation()+(16*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()+1*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+1*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()+1*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+1*(i+1))->isWhite()!=this->isWhite())){
                       allDestAttack[i+21]=this->squareLocation()+1*(i+1);
                       break;
                       }
        allDestAttack[i+21]=(this->squareLocation()+(1*(i+1)));
    }


    return allDestAttack;

}

QVector<quint8> Rook::trivialCanMoveToAttackIllu()
{
    QVector<quint8> allDeskAttackIllu(64,127);



    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPieceIllu(this->squareLocation()-16*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()-16*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPieceIllu(this->squareLocation()-16*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()-16*(i+1))->isWhite()!=this->isWhite())){
                       allDeskAttackIllu[i]=this->squareLocation()-16*(i+1);
                       break;
                       }
        allDeskAttackIllu[i]=(this->squareLocation()-(16*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPieceIllu(this->squareLocation()-1*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()-1*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPieceIllu(this->squareLocation()-1*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()-1*(i+1))->isWhite()!=this->isWhite())){
                       allDeskAttackIllu[i+7]=this->squareLocation()-1*(i+1);
                       break;
                       }
        allDeskAttackIllu[i+7]=(this->squareLocation()-(1*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPieceIllu(this->squareLocation()+16*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()+16*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPieceIllu(this->squareLocation()+16*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()+16*(i+1))->isWhite()!=this->isWhite())){
                       allDeskAttackIllu[i+14]=this->squareLocation()+16*(i+1);
                       break;
                       }
        allDeskAttackIllu[i+14]=(this->squareLocation()+(16*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPieceIllu(this->squareLocation()+1*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()+1*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPieceIllu(this->squareLocation()+1*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()+1*(i+1))->isWhite()!=this->isWhite())){
                       allDeskAttackIllu[i+21]=this->squareLocation()+1*(i+1);
                       break;
                       }
        allDeskAttackIllu[i+21]=(this->squareLocation()+(1*(i+1)));
    }


    return allDeskAttackIllu;
}
