#include "queen.h"
#include "chessboard.h"

Queen::Queen(quint8 indexLocationQ, bool colorQ):ChessPiece (indexLocationQ,colorQ)
{
    m_type = (colorQ ? "WQ" : "BQ");
}

QVector<quint8> Queen::trivialCanMoveTo()
{
    QVector<quint8> allDest(64,127);

    //from Bishop
    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()-15*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-15*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()-15*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-15*(i+1))->isWhite()!=this->isWhite())){
                       allDest[i]=this->squareLocation()-15*(i+1);
                       break;
                       }
        allDest[i]=(this->squareLocation()-(15*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()-17*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-17*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()-17*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-17*(i+1))->isWhite()!=this->isWhite())){
                       allDest[i+7]=this->squareLocation()-17*(i+1);
                       break;
                       }
        allDest[i+7]=(this->squareLocation()-(17*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()+15*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+15*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()+15*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+15*(i+1))->isWhite()!=this->isWhite())){
                       allDest[i+14]=this->squareLocation()+15*(i+1);
                       break;
                       }
        allDest[i+14]=(this->squareLocation()+(15*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()+17*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+17*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()+17*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+17*(i+1))->isWhite()!=this->isWhite())){
                       allDest[i+21]=this->squareLocation()+17*(i+1);
                       break;
                       }
        allDest[i+21]=(this->squareLocation()+(17*(i+1)));
    }

    //from Rook

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()-16*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-16*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()-16*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-16*(i+1))->isWhite()!=this->isWhite())){
                       allDest[i+28]=this->squareLocation()-16*(i+1);
                       break;
                       }
        allDest[i+28]=(this->squareLocation()-(16*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()-1*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-1*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()-1*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-1*(i+1))->isWhite()!=this->isWhite())){
                       allDest[i+35]=this->squareLocation()-1*(i+1);
                       break;
                       }
        allDest[i+35]=(this->squareLocation()-(1*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()+16*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+16*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()+16*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+16*(i+1))->isWhite()!=this->isWhite())){
                       allDest[i+42]=this->squareLocation()+16*(i+1);
                       break;
                       }
        allDest[i+42]=(this->squareLocation()+(16*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()+1*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+1*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()+1*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+1*(i+1))->isWhite()!=this->isWhite())){
                       allDest[i+49]=this->squareLocation()+1*(i+1);
                       break;
                       }
        allDest[i+49]=(this->squareLocation()+(1*(i+1)));
    }

    return allDest;
}

QVector<quint8> Queen::trivialCanMoveToAttack()
{
    QVector<quint8> allDestAttack(64,127);

    //from Bishop
    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()-15*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-15*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()-15*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-15*(i+1))->isWhite()!=this->isWhite())){
                       allDestAttack[i]=this->squareLocation()-15*(i+1);
                       break;
                       }
        allDestAttack[i]=(this->squareLocation()-(15*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()-17*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-17*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()-17*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-17*(i+1))->isWhite()!=this->isWhite())){
                       allDestAttack[i+7]=this->squareLocation()-17*(i+1);
                       break;
                       }
        allDestAttack[i+7]=(this->squareLocation()-(17*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()+15*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+15*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()+15*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+15*(i+1))->isWhite()!=this->isWhite())){
                       allDestAttack[i+14]=this->squareLocation()+15*(i+1);
                       break;
                       }
        allDestAttack[i+14]=(this->squareLocation()+(15*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()+17*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+17*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()+17*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+17*(i+1))->isWhite()!=this->isWhite())){
                       allDestAttack[i+21]=this->squareLocation()+17*(i+1);
                       break;
                       }
        allDestAttack[i+21]=(this->squareLocation()+(17*(i+1)));
    }

    //from Rook

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()-16*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-16*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()-16*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-16*(i+1))->isWhite()!=this->isWhite())){
                       allDestAttack[i+28]=this->squareLocation()-16*(i+1);
                       break;
                       }
        allDestAttack[i+28]=(this->squareLocation()-(16*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()-1*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-1*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()-1*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()-1*(i+1))->isWhite()!=this->isWhite())){
                       allDestAttack[i+35]=this->squareLocation()-1*(i+1);
                       break;
                       }
        allDestAttack[i+35]=(this->squareLocation()-(1*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()+16*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+16*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()+16*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+16*(i+1))->isWhite()!=this->isWhite())){
                       allDestAttack[i+42]=this->squareLocation()+16*(i+1);
                       break;
                       }
        allDestAttack[i+42]=(this->squareLocation()+(16*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPiece(this->squareLocation()+1*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+1*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPiece(this->squareLocation()+1*(i+1))!=nullptr)
                               &&(ChessBoard::getPiece(this->squareLocation()+1*(i+1))->isWhite()!=this->isWhite())){
                       allDestAttack[i+49]=this->squareLocation()+1*(i+1);
                       break;
                       }
        allDestAttack[i+49]=(this->squareLocation()+(1*(i+1)));
    }

    return allDestAttack;

}

QVector<quint8> Queen::trivialCanMoveToAttackIllu()
{
    QVector<quint8> allDeskAttackIllu(64,127);

    //from Bishop
    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPieceIllu(this->squareLocation()-15*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()-15*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPieceIllu(this->squareLocation()-15*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()-15*(i+1))->isWhite()!=this->isWhite())){
                       allDeskAttackIllu[i]=this->squareLocation()-15*(i+1);
                       break;
                       }
        allDeskAttackIllu[i]=(this->squareLocation()-(15*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPieceIllu(this->squareLocation()-17*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()-17*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPieceIllu(this->squareLocation()-17*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()-17*(i+1))->isWhite()!=this->isWhite())){
                       allDeskAttackIllu[i+7]=this->squareLocation()-17*(i+1);
                       break;
                       }
        allDeskAttackIllu[i+7]=(this->squareLocation()-(17*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPieceIllu(this->squareLocation()+15*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()+15*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPieceIllu(this->squareLocation()+15*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()+15*(i+1))->isWhite()!=this->isWhite())){
                       allDeskAttackIllu[i+14]=this->squareLocation()+15*(i+1);
                       break;
                       }
        allDeskAttackIllu[i+14]=(this->squareLocation()+(15*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPieceIllu(this->squareLocation()+17*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()+17*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPieceIllu(this->squareLocation()+17*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()+17*(i+1))->isWhite()!=this->isWhite())){
                       allDeskAttackIllu[i+21]=this->squareLocation()+17*(i+1);
                       break;
                       }
        allDeskAttackIllu[i+21]=(this->squareLocation()+(17*(i+1)));
    }

    //from Rook

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPieceIllu(this->squareLocation()-16*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()-16*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPieceIllu(this->squareLocation()-16*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()-16*(i+1))->isWhite()!=this->isWhite())){
                       allDeskAttackIllu[i+28]=this->squareLocation()-16*(i+1);
                       break;
                       }
        allDeskAttackIllu[i+28]=(this->squareLocation()-(16*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPieceIllu(this->squareLocation()-1*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()-1*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPieceIllu(this->squareLocation()-1*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()-1*(i+1))->isWhite()!=this->isWhite())){
                       allDeskAttackIllu[i+35]=this->squareLocation()-1*(i+1);
                       break;
                       }
        allDeskAttackIllu[i+35]=(this->squareLocation()-(1*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPieceIllu(this->squareLocation()+16*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()+16*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPieceIllu(this->squareLocation()+16*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()+16*(i+1))->isWhite()!=this->isWhite())){
                       allDeskAttackIllu[i+42]=this->squareLocation()+16*(i+1);
                       break;
                       }
        allDeskAttackIllu[i+42]=(this->squareLocation()+(16*(i+1)));
    }

    for(quint8 i=0; i<7;i++){
                if((ChessBoard::getPieceIllu(this->squareLocation()+1*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()+1*(i+1))->isWhite()==this->isWhite()))
                           break;
                       if((ChessBoard::getPieceIllu(this->squareLocation()+1*(i+1))!=nullptr)
                               &&(ChessBoard::getPieceIllu(this->squareLocation()+1*(i+1))->isWhite()!=this->isWhite())){
                       allDeskAttackIllu[i+49]=this->squareLocation()+1*(i+1);
                       break;
                       }
        allDeskAttackIllu[i+49]=(this->squareLocation()+(1*(i+1)));
    }

    return allDeskAttackIllu;
}
