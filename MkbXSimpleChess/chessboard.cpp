#include "chessboard.h"

//initialisation des variables statiques
QList<ChessSquare*> ChessBoard::m_chessBoard;
QList<ChessSquare*> ChessBoard::m_illusionaryChessBoard;
QString ChessBoard::m_endMateOrStale="playing";
bool ChessBoard::m_tongue=true;
bool ChessBoard::m_choixPlayer=true;
bool ChessBoard::m_getPromo=false;
int ChessBoard::m_promoPieceChoice=0;
QVector<quint8> ChessBoard::m_vectorMaquis(1,127);
QVector<quint8> ChessBoard::m_vectorMaquisIllu(1,127);

//constructeur d'un échiquier 0x88, 128 cases dont 64 cases invalides;
ChessBoard::ChessBoard()
{
    for(quint8 i =0;i<128;i++){
        if(squareIsValid(i))
        m_chessBoard<< new ChessSquare(i);
    }

}

//retrouver la pièce d'une case de l'échiquier par son index
ChessPiece *ChessBoard::getPiece(quint8 endroit)
{
    int endroitToInt= ((8*(endroit >> 4))+(endroit & 7)) ;

    return (endroitToInt >= 0 && endroitToInt < m_chessBoard.count()) ? m_chessBoard.at(endroitToInt)->piece() : nullptr;
}

//retrouver la pièce d'une case de l'échiquier fantôme par son index
ChessPiece *ChessBoard::getPieceIllu(quint8 endroitIllu)
{
    int endroitToIntIllu= ((8*(endroitIllu >> 4))+(endroitIllu & 7)) ;

    return (endroitToIntIllu >= 0 && endroitToIntIllu < m_illusionaryChessBoard.count()) ? m_illusionaryChessBoard.at(endroitToIntIllu)->piece() : nullptr;
}

//vecteur des cases attaquées
void ChessBoard::totalSquaresMaquis(bool colorMaquis)
{

    for(int ii=0; ii<m_chessBoard.count();ii++){
        if((m_chessBoard.at(ii)->piece()!=nullptr)&&
            (m_chessBoard.at(ii)->piece()->isWhite()!=colorMaquis))
            for(int iterMaquis=0; iterMaquis <m_chessBoard.at(ii)->piece()->trivialCanMoveToAttack().size();iterMaquis++){
                 m_vectorMaquis<<m_chessBoard.at(ii)->piece()->trivialCanMoveToAttack()[iterMaquis];
            }
    }
    m_vectorMaquis.erase(std::remove(m_vectorMaquis.begin(), m_vectorMaquis.end(), 127), m_vectorMaquis.end());
}

//vecteur des cases attaquées dans l'échiquier fantôme
void ChessBoard::totalSquaresMaquisIllu(bool colorMaquisIllu)
{
    for(int ii=0; ii<m_illusionaryChessBoard.count();ii++){
        if((m_illusionaryChessBoard.at(ii)->piece()!=nullptr)&&
            (m_illusionaryChessBoard.at(ii)->piece()->isWhite()!=colorMaquisIllu))
            for(int iterMaquis=0; iterMaquis <m_illusionaryChessBoard.at(ii)->piece()->trivialCanMoveToAttackIllu().size();iterMaquis++){
                 m_vectorMaquisIllu<<m_illusionaryChessBoard.at(ii)->piece()->trivialCanMoveToAttackIllu()[iterMaquis];
            }
    }
    m_vectorMaquisIllu.erase(std::remove(m_vectorMaquisIllu.begin(), m_vectorMaquisIllu.end(), 127), m_vectorMaquisIllu.end());
}

//création de l'échiquier fantôme
void ChessBoard::createIllusionaryBoard()
{
    m_illusionaryChessBoard.clear();

    for(quint8 i =0;i<128;i++){
        if(((i & 0x88) == 0))
        m_illusionaryChessBoard<< new ChessSquare(i);
    }


    for(int i=0; i<m_chessBoard.count(); i++){
        if(m_chessBoard.at(i)->piece()!=nullptr){
            if(typeid(*m_chessBoard.at(i)->piece())==typeid(Bishop))
         m_illusionaryChessBoard.at(i)->setPiece(new Bishop(m_chessBoard.at(i)->piece()->squareLocation(),m_chessBoard.at(i)->piece()->isWhite()));

            else if(typeid(*m_chessBoard.at(i)->piece())==typeid(Knight))
         m_illusionaryChessBoard.at(i)->setPiece(new Knight(m_chessBoard.at(i)->piece()->squareLocation(),m_chessBoard.at(i)->piece()->isWhite()));

            else if(typeid(*m_chessBoard.at(i)->piece())==typeid(Rook))
         m_illusionaryChessBoard.at(i)->setPiece(new Rook(m_chessBoard.at(i)->piece()->squareLocation(),m_chessBoard.at(i)->piece()->isWhite()));

            else if(typeid(*m_chessBoard.at(i)->piece())==typeid(Queen))
         m_illusionaryChessBoard.at(i)->setPiece(new Queen(m_chessBoard.at(i)->piece()->squareLocation(),m_chessBoard.at(i)->piece()->isWhite()));

            else if(typeid(*m_chessBoard.at(i)->piece())==typeid(King))
         m_illusionaryChessBoard.at(i)->setPiece(new King(m_chessBoard.at(i)->piece()->squareLocation(),m_chessBoard.at(i)->piece()->isWhite()));

            else if(typeid(*m_chessBoard.at(i)->piece())==typeid(Pawn))
         m_illusionaryChessBoard.at(i)->setPiece(new Pawn(m_chessBoard.at(i)->piece()->squareLocation(),m_chessBoard.at(i)->piece()->isWhite()));
        }

    }

}

//fixer une pièce sur une case dans l'échiquier fantôme
void ChessBoard::setPieceOnSquareIllu(ChessPiece *pIllu, quint8 locHexaIllu)
{
    if(((locHexaIllu & 0x88) == 0)){
        int locInt;
        locInt = ((8*(locHexaIllu >> 4))+(locHexaIllu & 7));


        if(m_illusionaryChessBoard.at(locInt)->piece()!=nullptr){
            qDebug()<<m_illusionaryChessBoard.at(locInt)->piece();
        }
        else{
            m_illusionaryChessBoard.at(locInt)->setPiece(pIllu);
        }
    }
    else {qDebug()<<"invalid hexaIllu";}
}


//échec?
bool ChessBoard::checkCheck()
{
//Opponent Maquis(Ma puissance de feu)

        m_vectorMaquis.clear();
        ChessBoard::totalSquaresMaquis(!m_aMonTour);

    //locate opponent King
    ChessPiece *oppK =nullptr;

    for(int jj=0; jj<m_chessBoard.count();jj++){
        if((m_chessBoard.at(jj)->piece()!=nullptr)&&
            (m_chessBoard.at(jj)->piece()->classeKing()=="KingClass")&&
                (m_chessBoard.at(jj)->piece()->isWhite()!=m_aMonTour)){
            oppK=m_chessBoard.at(jj)->piece();
            break;
        }

    };

    if(std::find(m_vectorMaquis.begin(),m_vectorMaquis.end(),oppK->squareLocation()) !=m_vectorMaquis.end()){
        squareAt(convHexaToInt(oppK->squareLocation()))->setCheck(true);
        return true;
    }


//Mon Maquis(Puissance de feu ennemie)

        m_vectorMaquis.clear();
        ChessBoard::totalSquaresMaquis(m_aMonTour);

    //locate my King
    ChessPiece *myK =nullptr;

    for(int cc=0; cc<m_chessBoard.count();cc++){
        if((m_chessBoard.at(cc)->piece()!=nullptr)&&
            (m_chessBoard.at(cc)->piece()->classeKing()=="KingClass")&&
                (m_chessBoard.at(cc)->piece()->isWhite()==m_aMonTour)){
             myK=m_chessBoard.at(cc)->piece();
             break;
        }

    };

    if(std::find(m_vectorMaquis.begin(),m_vectorMaquis.end(),myK->squareLocation()) !=m_vectorMaquis.end()){
        squareAt(convHexaToInt(myK->squareLocation()))->setCheck(true);
        return true;
    }
    m_vectorMaquis.clear();
    return false;

}

//échec dans le monde sombre?
bool ChessBoard::ownCheckIllu()
{

    //Mon Maquis Illu (Puissance de feu ennemie Illu)
        quint8 myKPosition=0;
            m_vectorMaquisIllu.clear();
            ChessBoard::totalSquaresMaquisIllu(m_aMonTour);

        //locate my King
        ChessPiece *myK =nullptr;

        for(int yy=0; yy< m_illusionaryChessBoard.count();yy++){
            if((m_illusionaryChessBoard.at(yy)->piece()!=nullptr)&&
                (m_illusionaryChessBoard.at(yy)->piece()->classeKing()=="KingClass")&&
                    (m_illusionaryChessBoard.at(yy)->piece()->isWhite()==m_aMonTour)){
                 myK=m_illusionaryChessBoard.at(yy)->piece();
                 myKPosition=myK->squareLocation();
                 break;
            }

        };

        if(std::find(m_vectorMaquisIllu.begin(),m_vectorMaquisIllu.end(),myKPosition) !=m_vectorMaquisIllu.end()){
//            qDebug()<<"illu check trouve ici my "<<myKPosition;
            return true;
        }
        m_vectorMaquisIllu.clear();
        return false;
}

//initialisation du jeu classique
void ChessBoard::initW()
{
    setEndMateOrStale("playing");
    setAMonTour(true);

    for(int i=0; i<64; i++){
        squareAt(i)->setSelected(false);
        squareAt(i)->setDestiSelected(false);
        squareAt(i)->setCheck(false);
        squareAt(i)->setCastlingSelected(false);
    }

    for(int i=0; i<m_chessBoard.count(); i++){
        if(m_chessBoard.at(i)->piece()!=nullptr){
            delete m_chessBoard.at(i)->piece();
            m_chessBoard.at(i)->setPiece(nullptr);

        }
        m_chessBoard.at(i)->setCheck(false);

    }

    ChessPiece* rookAOne=new Rook(112,true);
    ChessPiece* cavalierBUn=new Knight(113,true);
    ChessPiece* bishopCOne=new Bishop(114,true);
    ChessPiece* reineDUn=new Queen(115,true);
    ChessPiece* KingEOne=new King(116,true);
    ChessPiece* fouFUn=new Bishop(117,true);
    ChessPiece* knightGOne=new Knight(118,true);
    ChessPiece* tourHUn=new Rook(119,true);

    ChessPiece* pawnATwo=new Pawn(96,true);
    ChessPiece* pionBDeux=new Pawn(97,true);
    ChessPiece* pawnCTwo=new Pawn(98,true);
    ChessPiece* pionDDeux=new Pawn(99,true);
    ChessPiece* pawnETwo=new Pawn(100,true);
    ChessPiece* pionFDeux=new Pawn(101,true);
    ChessPiece* pawnGTwo=new Pawn(102,true);
    ChessPiece* pionHDeux=new Pawn(103,true);


    ChessPiece* rookAEight=new Rook(0,false);
    ChessPiece* cavalierBHuit=new Knight(1,false);
    ChessPiece* bishopCEight=new Bishop(2,false);
    ChessPiece* reineDHuit=new Queen(3,false);
    ChessPiece* KingEEight=new King(4,false);
    ChessPiece* fouFHuit=new Bishop(5,false);
    ChessPiece* knightGEight=new Knight(6,false);
    ChessPiece* tourHHuit=new Rook(7,false);

    ChessPiece* pawnASeven=new Pawn(16,false);
    ChessPiece* pionBSept=new Pawn(17,false);
    ChessPiece* pawnCSeven=new Pawn(18,false);
    ChessPiece* pionDSept=new Pawn(19,false);
    ChessPiece* pawnESeven=new Pawn(20,false);
    ChessPiece* pionFSept=new Pawn(21,false);
    ChessPiece* pawnGSeven=new Pawn(22,false);
    ChessPiece* pionHSept=new Pawn(23,false);


    setPieceOnSquare(rookAOne,rookAOne->squareLocation());
    setPieceOnSquare(cavalierBUn,cavalierBUn->squareLocation());
    setPieceOnSquare(bishopCOne,bishopCOne->squareLocation());
    setPieceOnSquare(reineDUn,reineDUn->squareLocation());
    setPieceOnSquare(KingEOne,KingEOne->squareLocation());
    setPieceOnSquare(fouFUn,fouFUn->squareLocation());
    setPieceOnSquare(knightGOne,knightGOne->squareLocation());
    setPieceOnSquare(tourHUn,tourHUn->squareLocation());

    setPieceOnSquare(pawnATwo,pawnATwo->squareLocation());
    setPieceOnSquare(pionBDeux,pionBDeux->squareLocation());
    setPieceOnSquare(pawnCTwo,pawnCTwo->squareLocation());
    setPieceOnSquare(pionDDeux,pionDDeux->squareLocation());
    setPieceOnSquare(pawnETwo,pawnETwo->squareLocation());
    setPieceOnSquare(pionFDeux,pionFDeux->squareLocation());
    setPieceOnSquare(pawnGTwo,pawnGTwo->squareLocation());
    setPieceOnSquare(pionHDeux,pionHDeux->squareLocation());


    setPieceOnSquare(rookAEight,rookAEight->squareLocation());
    setPieceOnSquare(cavalierBHuit,cavalierBHuit->squareLocation());
    setPieceOnSquare(bishopCEight,bishopCEight->squareLocation());
    setPieceOnSquare(reineDHuit,reineDHuit->squareLocation());
    setPieceOnSquare(KingEEight,KingEEight->squareLocation());
    setPieceOnSquare(fouFHuit,fouFHuit->squareLocation());
    setPieceOnSquare(knightGEight,knightGEight->squareLocation());
    setPieceOnSquare(tourHHuit,tourHHuit->squareLocation());

    setPieceOnSquare(pawnASeven,pawnASeven->squareLocation());
    setPieceOnSquare(pionBSept,pionBSept->squareLocation());
    setPieceOnSquare(pawnCSeven,pawnCSeven->squareLocation());
    setPieceOnSquare(pionDSept,pionDSept->squareLocation());
    setPieceOnSquare(pawnESeven,pawnESeven->squareLocation());
    setPieceOnSquare(pionFSept,pionFSept->squareLocation());
    setPieceOnSquare(pawnGSeven,pawnGSeven->squareLocation());
    setPieceOnSquare(pionHSept,pionHSept->squareLocation());

}

//initialisation point de vue inversé
void ChessBoard::initB()
{


    setEndMateOrStale("playing");
    setAMonTour(true);

    for(int i=0; i<64; i++){
        squareAt(i)->setSelected(false);
        squareAt(i)->setDestiSelected(false);
        squareAt(i)->setCheck(false);
        squareAt(i)->setCastlingSelected(false);
    }

    for(int i=0; i<m_chessBoard.count(); i++){
        if(m_chessBoard.at(i)->piece()!=nullptr){
            delete m_chessBoard.at(i)->piece();
             m_chessBoard.at(i)->setPiece(nullptr);

        }
        m_chessBoard.at(i)->setCheck(false);
    }

    ChessPiece* rookAOne=new Rook(112,false);
    ChessPiece* cavalierBUn=new Knight(113,false);
    ChessPiece* bishopCOne=new Bishop(114,false);
    ChessPiece* reineDUn=new Queen(116,false);
    ChessPiece* KingEOne=new King(115,false);
    ChessPiece* fouFUn=new Bishop(117,false);
    ChessPiece* knightGOne=new Knight(118,false);
    ChessPiece* tourHUn=new Rook(119,false);

    ChessPiece* pawnATwo=new Pawn(96,false);
    ChessPiece* pionBDeux=new Pawn(97,false);
    ChessPiece* pawnCTwo=new Pawn(98,false);
    ChessPiece* pionDDeux=new Pawn(99,false);
    ChessPiece* pawnETwo=new Pawn(100,false);
    ChessPiece* pionFDeux=new Pawn(101,false);
    ChessPiece* pawnGTwo=new Pawn(102,false);
    ChessPiece* pionHDeux=new Pawn(103,false);


    ChessPiece* rookAEight=new Rook(0,true);
    ChessPiece* cavalierBHuit=new Knight(1,true);
    ChessPiece* bishopCEight=new Bishop(2,true);
    ChessPiece* reineDHuit=new Queen(4,true);
    ChessPiece* KingEEight=new King(3,true);
    ChessPiece* fouFHuit=new Bishop(5,true);
    ChessPiece* knightGEight=new Knight(6,true);
    ChessPiece* tourHHuit=new Rook(7,true);

    ChessPiece* pawnASeven=new Pawn(16,true);
    ChessPiece* pionBSept=new Pawn(17,true);
    ChessPiece* pawnCSeven=new Pawn(18,true);
    ChessPiece* pionDSept=new Pawn(19,true);
    ChessPiece* pawnESeven=new Pawn(20,true);
    ChessPiece* pionFSept=new Pawn(21,true);
    ChessPiece* pawnGSeven=new Pawn(22,true);
    ChessPiece* pionHSept=new Pawn(23,true);


    setPieceOnSquare(rookAOne,rookAOne->squareLocation());
    setPieceOnSquare(cavalierBUn,cavalierBUn->squareLocation());
    setPieceOnSquare(bishopCOne,bishopCOne->squareLocation());
    setPieceOnSquare(reineDUn,reineDUn->squareLocation());
    setPieceOnSquare(KingEOne,KingEOne->squareLocation());
    setPieceOnSquare(fouFUn,fouFUn->squareLocation());
    setPieceOnSquare(knightGOne,knightGOne->squareLocation());
    setPieceOnSquare(tourHUn,tourHUn->squareLocation());

    setPieceOnSquare(pawnATwo,pawnATwo->squareLocation());
    setPieceOnSquare(pionBDeux,pionBDeux->squareLocation());
    setPieceOnSquare(pawnCTwo,pawnCTwo->squareLocation());
    setPieceOnSquare(pionDDeux,pionDDeux->squareLocation());
    setPieceOnSquare(pawnETwo,pawnETwo->squareLocation());
    setPieceOnSquare(pionFDeux,pionFDeux->squareLocation());
    setPieceOnSquare(pawnGTwo,pawnGTwo->squareLocation());
    setPieceOnSquare(pionHDeux,pionHDeux->squareLocation());


    setPieceOnSquare(rookAEight,rookAEight->squareLocation());
    setPieceOnSquare(cavalierBHuit,cavalierBHuit->squareLocation());
    setPieceOnSquare(bishopCEight,bishopCEight->squareLocation());
    setPieceOnSquare(reineDHuit,reineDHuit->squareLocation());
    setPieceOnSquare(KingEEight,KingEEight->squareLocation());
    setPieceOnSquare(fouFHuit,fouFHuit->squareLocation());
    setPieceOnSquare(knightGEight,knightGEight->squareLocation());
    setPieceOnSquare(tourHHuit,tourHHuit->squareLocation());

    setPieceOnSquare(pawnASeven,pawnASeven->squareLocation());
    setPieceOnSquare(pionBSept,pionBSept->squareLocation());
    setPieceOnSquare(pawnCSeven,pawnCSeven->squareLocation());
    setPieceOnSquare(pionDSept,pionDSept->squareLocation());
    setPieceOnSquare(pawnESeven,pawnESeven->squareLocation());
    setPieceOnSquare(pionFSept,pionFSept->squareLocation());
    setPieceOnSquare(pawnGSeven,pawnGSeven->squareLocation());
    setPieceOnSquare(pionHSept,pionHSept->squareLocation());
}


void ChessBoard::finGame()
{
//    Vérification en utilisant QDebug
//    qDebug()<<"Hi";

    QVector<quint8> casesDestinationRestantes;

    for(int gg=0; gg<m_chessBoard.count();gg++){
        if((m_chessBoard.at(gg)->piece()!=nullptr)&&
            (m_chessBoard.at(gg)->piece()->isWhite()==m_aMonTour))
            for(int iterRestantes=0; iterRestantes <m_chessBoard.at(gg)->piece()->trivialCanMoveTo().size();iterRestantes++){
                if(validatePieceTrivialCanMoveTo(m_chessBoard.at(gg)->piece()->trivialCanMoveTo()[iterRestantes],m_chessBoard.at(gg)->piece())){
                 casesDestinationRestantes<<m_chessBoard.at(gg)->piece()->trivialCanMoveTo()[iterRestantes];}
            }
    }

    if(casesDestinationRestantes.isEmpty()){
        if(checkCheck()){
            qDebug()<<"Checkmate!!!!!!!!";
            setEndMateOrStale("checkmate");
            qDebug()<<m_endMateOrStale;
        }
        else {
            qDebug()<<"Stalemate---------";
            setEndMateOrStale("stalemate");
        }

    }

    //    Vérification en utilisant QDebug
//    for(int i=0; i<casesDestinationRestantes.size();i++)
//        qDebug()<<casesDestinationRestantes.at(i)<<endl;
//qDebug()<<"bye";

}

//case valide (sur l'échiquier) ou invalide (en dehors de l'échiquier) ?
bool ChessBoard::squareIsValid(quint8 indexTest) const
{
    return ((indexTest & 0x88) == 0);

}

//fixer une pièce sur une case dans l'échiquier
void ChessBoard::setPieceOnSquare(ChessPiece *p, quint8 locHexa)
{
    if(squareIsValid(locHexa)){
        int locInt;
        locInt = convHexaToInt(locHexa);


        if(squareAt(locInt)->piece()!=nullptr){
            qDebug()<<squareAt(locInt)->piece();
        }
        else{
            squareAt(locInt)->setPiece(p);
        }
    }
    else {qDebug()<<"invalid hexa";}
}


//valider les destinations autorisées des vecteurs de déplacements des pièces
bool ChessBoard::validatePieceTrivialCanMoveTo(quint8 fromlistVector, ChessPiece * pieceV)
{
    if(!squareIsValid(fromlistVector))
        return false;

      if((squareAt(convHexaToInt(fromlistVector))->piece()!=nullptr)&&(squareAt(convHexaToInt(fromlistVector))->piece()->isWhite()==pieceV->isWhite()))
        return false;

      ChessPiece *tempPieceIllu=nullptr;
      createIllusionaryBoard();

//       Vérification en utilisant QDebug
//       for(int iterAffichage=0; iterAffichage <m_illusionaryChessBoard.size();++iterAffichage){
//           qDebug()<<"AvantMoveIllu position : "<<iterAffichage<<" on a : "<<m_illusionaryChessBoard[iterAffichage]->piece()<<endl;}

      tempPieceIllu = m_illusionaryChessBoard.at(convHexaToInt(pieceV->squareLocation()))->piece();

      //Vérification en utilisant QDebug
      //qDebug()<<" desti fromlistvector "<<fromlistVector;

           delete m_illusionaryChessBoard.at(convHexaToInt(fromlistVector))->piece();
           m_illusionaryChessBoard.at(convHexaToInt(fromlistVector))->setPiece(nullptr);
           tempPieceIllu->setSquareLocation(fromlistVector);
           m_illusionaryChessBoard.at(convHexaToInt(pieceV->squareLocation()))->setPiece(nullptr);
           setPieceOnSquareIllu(tempPieceIllu,tempPieceIllu->squareLocation());


           //Test pour autoriser la prise en passant pour contrer un éventuel échec
           //QObject verrouille le constructeur par copie; Par conséquent impossible de créer des fonctions virtuelles "clone" pour cloner les pièces dans l'échiquier sombre :/
           //Donc les pions dont les valeurs enPassant ont été mises à jour dans l'échiquier ne se répercutent pas dans l'échiquier sombre,
           //étant donné que les pièces de l'échiquier sombre ne sont pas des clones de celles de l'échiquier mais des pièces "recréées" avec la fonction createIllusionaryBoard :/
           if((typeid(*tempPieceIllu)==typeid(Pawn))
                   &&(fromlistVector==pieceV->squareLocation()+15)
                   &&(m_chessBoard.at(convHexaToInt(fromlistVector-16))->piece()!=nullptr)
                   &&(m_chessBoard.at(convHexaToInt(fromlistVector-16))->piece()->enPassant()==1)){
                     //Vérification en utilisant QDebug
//               qDebug()<<"yosh black on top / black en passant sur white on bottom : for +15";
               delete m_illusionaryChessBoard.at(convHexaToInt(fromlistVector-16))->piece();
               m_illusionaryChessBoard.at(convHexaToInt(fromlistVector-16))->setPiece(nullptr);
           }/*fois 2*/

           if((typeid(*tempPieceIllu)==typeid(Pawn))
                   &&(fromlistVector==pieceV->squareLocation()+17)
                   &&(m_chessBoard.at(convHexaToInt(fromlistVector-16))->piece()!=nullptr)
                   &&(m_chessBoard.at(convHexaToInt(fromlistVector-16))->piece()->enPassant()==1)){
                     //Vérification en utilisant QDebug
//               qDebug()<<"yosh black on top / black en passant sur white on bottom : for +17";
               delete m_illusionaryChessBoard.at(convHexaToInt(fromlistVector-16))->piece();
               m_illusionaryChessBoard.at(convHexaToInt(fromlistVector-16))->setPiece(nullptr);
           }/*fois 2*/

           if((typeid(*tempPieceIllu)==typeid(Pawn))
                   &&(fromlistVector==pieceV->squareLocation()-17)
                   &&(m_chessBoard.at(convHexaToInt(fromlistVector+16))->piece()!=nullptr)
                   &&(m_chessBoard.at(convHexaToInt(fromlistVector+16))->piece()->enPassant()==1)){
                     //Vérification en utilisant QDebug
//               qDebug()<<"yosh white on bottom / white en passant sur black on top : for -17";
               delete m_illusionaryChessBoard.at(convHexaToInt(fromlistVector+16))->piece();
               m_illusionaryChessBoard.at(convHexaToInt(fromlistVector+16))->setPiece(nullptr);
           }/*fois 2*/

           if((typeid(*tempPieceIllu)==typeid(Pawn))
                   &&(fromlistVector==pieceV->squareLocation()-15)
                   &&(m_chessBoard.at(convHexaToInt(fromlistVector+16))->piece()!=nullptr)
                   &&(m_chessBoard.at(convHexaToInt(fromlistVector+16))->piece()->enPassant()==1)){
                     //Vérification en utilisant QDebug
//               qDebug()<<"yosh white on bottom / white en passant sur black on top : for -15";
               delete m_illusionaryChessBoard.at(convHexaToInt(fromlistVector+16))->piece();
               m_illusionaryChessBoard.at(convHexaToInt(fromlistVector+16))->setPiece(nullptr);
           }/*fois 2*/


       //si un échec subsiste après déplacement dans l'échiquier sombre, le déplacement est non autorisé
       if(ownCheckIllu())
           return false;

        return true;
}

//conversion numéro de case 0x88 en numéro entier
int ChessBoard::convHexaToInt(quint8 hex)
{
    return ((8*(hex >> 4))+(hex & 7));
}

//commencer la promotion du pion
bool ChessBoard::doPawnPromotion(ChessPiece *pawnToPromote, bool isItOkToPromote)
{
    if(isItOkToPromote==false)
        return false;


    m_finishPromotion=pawnToPromote;
    setFinishPromotionIsWhite(pawnToPromote->isWhite());
    m_finishPromotionLocation=pawnToPromote->squareLocation();
    squareAt(convHexaToInt(pawnToPromote->squareLocation()))->setPiece(nullptr);
//    pawnToPromote->setSquareLocation(127); attention erreur si convToHexa un hexa de 127 !!!
    delete m_finishPromotion;
    m_finishPromotion=nullptr;

    setGetPromo(true);

    return true;

}

//fonction d'entraînement pour "linker" C++ et QML
QString ChessBoard::chessBoardSquareAt(int indd) const
{
    return ((squareAt(indd)->piece()==nullptr) ? "0" : squareAt(indd)->piece()->type());
//    return QString("%1").arg(squareAt(indd)->indexHexa());
}

//Modélisation des mouvements des pièces selon les clics des joueurs
void ChessBoard::mouseClick(int indexx)
{
    ChessPiece *selectedPiece=nullptr;
    ChessSquare *destination=nullptr;
    m_vectorMaquis.clear();
    ChessBoard::totalSquaresMaquis(m_aMonTour);

    //       Vérification en utilisant QDebug
//                        for(QVector<quint8>::iterator iter=m_vectorMaquis.begin();iter !=m_vectorMaquis.end();++iter){
//                            qDebug()<<"Maquisposition : "<<m_vectorMaquis.indexOf(*iter)<<" Maquison a : "<<*iter<<endl;

//                     }

    //first click : select piece
    if((squareAt(indexx)->piece()!=nullptr)&&(squareAt(indexx)->piece()->isWhite()==m_aMonTour)&&(m_pieceAlreadySelected==false)){
        m_selectedPieceSquare=squareAt(indexx);
        m_selectedPieceSquare->setSelected(true);
        selectedPiece=m_selectedPieceSquare->piece();

                //       Vérification en utilisant QDebug
//        qDebug()<<"if"<<selectedPiece->moveCount();
//                            for(QVector<quint8>::iterator iter=ChessBoard::totalSquaresMaquis(m_aMonTour).begin();iter !=ChessBoard::totalSquaresMaquis(m_aMonTour).end();++iter){
//                                qDebug()<<"Maquis position : "<<ChessBoard::totalSquaresMaquis(m_aMonTour).indexOf(*iter)<<" Maquis zar on a : "<<*iter<<endl;

//                         }
//        qDebug()<<"selectedPieceSquare : "<<m_selectedPieceSquare;

        for(int iterVali =0; iterVali <selectedPiece->trivialCanMoveTo().size();iterVali++){
            if(validatePieceTrivialCanMoveTo(selectedPiece->trivialCanMoveTo()[iterVali],selectedPiece)){
             m_pieceValidatedMove<<selectedPiece->trivialCanMoveTo()[iterVali];
            squareAt(convHexaToInt(selectedPiece->trivialCanMoveTo().at(iterVali)))->setDestiSelected(true);

            //Highlight rook if castling available
            if((selectedPiece->petitRoqueDispo()==true)
                    && (selectedPiece->isWhite()==true)
                    && (selectedPiece->squareLocation()==116)
                    && (std::find(m_pieceValidatedMove.begin(),m_pieceValidatedMove.end(),118) !=m_pieceValidatedMove.end())){
                squareAt(63)->setCastlingSelected(true);
            }

            if((selectedPiece->petitRoqueDispo()==true)
                    && (selectedPiece->isWhite()==true)
                    && (selectedPiece->squareLocation()==3)
                    && (std::find(m_pieceValidatedMove.begin(),m_pieceValidatedMove.end(),1) !=m_pieceValidatedMove.end())){
                squareAt(0)->setCastlingSelected(true);
            }

            if((selectedPiece->grandRoqueDispo()==true)
                    && (selectedPiece->isWhite()==true)
                    && (selectedPiece->squareLocation()==116)
                    && (std::find(m_pieceValidatedMove.begin(),m_pieceValidatedMove.end(),114) !=m_pieceValidatedMove.end())){
                squareAt(56)->setCastlingSelected(true);
            }

            if((selectedPiece->grandRoqueDispo()==true)
                    && (selectedPiece->isWhite()==true)
                    && (selectedPiece->squareLocation()==3)
                    && (std::find(m_pieceValidatedMove.begin(),m_pieceValidatedMove.end(),5) !=m_pieceValidatedMove.end())){
                squareAt(7)->setCastlingSelected(true);
            }

            if((selectedPiece->petitRoqueDispo()==true)
                    && (selectedPiece->isWhite()==false)
                    && (selectedPiece->squareLocation()==115)
                    && (std::find(m_pieceValidatedMove.begin(),m_pieceValidatedMove.end(),113) !=m_pieceValidatedMove.end())){
                squareAt(56)->setCastlingSelected(true);
            }

            if((selectedPiece->petitRoqueDispo()==true)
                    && (selectedPiece->isWhite()==false)
                    && (selectedPiece->squareLocation()==4)
                    && (std::find(m_pieceValidatedMove.begin(),m_pieceValidatedMove.end(),6) !=m_pieceValidatedMove.end())){
                squareAt(7)->setCastlingSelected(true);
            }

            if((selectedPiece->grandRoqueDispo()==true)
                    && (selectedPiece->isWhite()==false)
                    && (selectedPiece->squareLocation()==115)
                    && (std::find(m_pieceValidatedMove.begin(),m_pieceValidatedMove.end(),117) !=m_pieceValidatedMove.end())){
                squareAt(63)->setCastlingSelected(true);
            }

            if((selectedPiece->grandRoqueDispo()==true)
                    && (selectedPiece->isWhite()==false)
                    && (selectedPiece->squareLocation()==4)
                    && (std::find(m_pieceValidatedMove.begin(),m_pieceValidatedMove.end(),2) !=m_pieceValidatedMove.end())){
                squareAt(0)->setCastlingSelected(true);
            }

            }
        }
        m_pieceAlreadySelected=true;

                //       Vérification en utilisant QDebug
//                            for(int iterAffichage=0; iterAffichage <m_pieceValidatedMove.size();++iterAffichage){
//                                qDebug()<<"position : "<<iterAffichage<<" on a : "<<m_pieceValidatedMove[iterAffichage]<<endl;}


    }
        //2nd click : move piece
    else {

            destination=squareAt(indexx);

                    //       Vérification en utilisant QDebug
//            qDebug()<<"else";
            if (m_selectedPieceSquare){selectedPiece=m_selectedPieceSquare->piece();



                if(std::find(m_pieceValidatedMove.begin(),m_pieceValidatedMove.end(),destination->indexHexa()) !=m_pieceValidatedMove.end()){

                    if((destination->piece()!=nullptr)&&(destination->piece()->isWhite()!=selectedPiece->isWhite())){
                        delete destination->piece();
                        destination->setPiece(nullptr);
                        m_selectedPieceSquare->piece()->setSquareLocation(destination->indexHexa());
                        m_selectedPieceSquare->setPiece(nullptr);
                        setPieceOnSquare(selectedPiece,destination->indexHexa());
                        selectedPiece->setMoveCount(selectedPiece->moveCount()+1);
                        m_selectedPieceSquare->setSelected(false);m_selectedPieceSquare=nullptr;
                        for(int i=0; i<64; i++){
                            squareAt(i)->setDestiSelected(false);
                            squareAt(i)->setCheck(false);}
                        m_pieceValidatedMove.clear();
                        m_pieceAlreadySelected=false;
                        doPawnPromotion(selectedPiece,selectedPiece->pawnPromotion());
                        checkCheck();
//                        qDebug()<<checkCheck();
                        for(int i=0; i<64; i++){
                            if((squareAt(i)->piece()!=nullptr)&&(squareAt(i)->piece()->enPassant()==2||squareAt(i)->piece()->enPassant()==1))
                            squareAt(i)->piece()->setEnPassant(squareAt(i)->piece()->enPassant()-1);}
                        setAMonTour(!m_aMonTour);/*m_aMonTour=!m_aMonTour;*/                        
                        finGame();
                    }
                    else{
                        //Roque
                        if((selectedPiece->petitRoqueDispo()==true)
                                && (selectedPiece->isWhite()==true)
                                && (selectedPiece->squareLocation()==116)
                                && (destination->indexHexa()==118)){
                            ChessPiece *tempRookWhitePetitRoqueBottom=squareAt(63)->piece();
                            squareAt(63)->piece()->setSquareLocation(117);
                            squareAt(63)->setPiece(nullptr);
                            setPieceOnSquare(tempRookWhitePetitRoqueBottom,117);
                            selectedPiece->setPetitRoqueDispo(false);
                            squareAt(63)->setCastlingSelected(false);
                        }

                        if((selectedPiece->petitRoqueDispo()==true)
                                && (selectedPiece->isWhite()==true)
                                && (selectedPiece->squareLocation()==3)
                                && (destination->indexHexa()==1)){
                            ChessPiece *tempRookWhitePetitRoqueTop=squareAt(0)->piece();
                            squareAt(0)->piece()->setSquareLocation(2);
                            squareAt(0)->setPiece(nullptr);
                            setPieceOnSquare(tempRookWhitePetitRoqueTop,2);
                            selectedPiece->setPetitRoqueDispo(false);
                            squareAt(0)->setCastlingSelected(false);
                        }

                        if((selectedPiece->grandRoqueDispo()==true)
                                && (selectedPiece->isWhite()==true)
                                && (selectedPiece->squareLocation()==116)
                                && (destination->indexHexa()==114)){
                            ChessPiece *tempRookWhitegrandRoqueBottom=squareAt(56)->piece();
                            squareAt(56)->piece()->setSquareLocation(115);
                            squareAt(56)->setPiece(nullptr);
                            setPieceOnSquare(tempRookWhitegrandRoqueBottom,115);
                            selectedPiece->setGrandRoqueDispo(false);
                            squareAt(56)->setCastlingSelected(false);
                        }

                        if((selectedPiece->grandRoqueDispo()==true)
                                && (selectedPiece->isWhite()==true)
                                && (selectedPiece->squareLocation()==3)
                                && (destination->indexHexa()==5)){
                            ChessPiece *tempRookWhitegrandRoqueTop=squareAt(7)->piece();
                            squareAt(7)->piece()->setSquareLocation(4);
                            squareAt(7)->setPiece(nullptr);
                            setPieceOnSquare(tempRookWhitegrandRoqueTop,4);
                            selectedPiece->setGrandRoqueDispo(false);
                            squareAt(7)->setCastlingSelected(false);
                        }

                        if((selectedPiece->petitRoqueDispo()==true)
                                && (selectedPiece->isWhite()==false)
                                && (selectedPiece->squareLocation()==115)
                                && (destination->indexHexa()==113)){
                            ChessPiece *tempRookBlackPetitRoqueBottom=squareAt(56)->piece();
                            squareAt(56)->piece()->setSquareLocation(114);
                            squareAt(56)->setPiece(nullptr);
                            setPieceOnSquare(tempRookBlackPetitRoqueBottom,114);
                            selectedPiece->setPetitRoqueDispo(false);
                            squareAt(56)->setCastlingSelected(false);/*fois 2*/
                        }

                        if((selectedPiece->petitRoqueDispo()==true)
                                && (selectedPiece->isWhite()==false)
                                && (selectedPiece->squareLocation()==4)
                                && (destination->indexHexa()==6)){
                            ChessPiece *tempRookBlackPetitRoqueTop=squareAt(7)->piece();
                            squareAt(7)->piece()->setSquareLocation(5);
                            squareAt(7)->setPiece(nullptr);
                            setPieceOnSquare(tempRookBlackPetitRoqueTop,5);
                            selectedPiece->setPetitRoqueDispo(false);
                            squareAt(7)->setCastlingSelected(false);/*fois 2*/
                        }

                        if((selectedPiece->grandRoqueDispo()==true)
                                && (selectedPiece->isWhite()==false)
                                && (selectedPiece->squareLocation()==115)
                                && (destination->indexHexa()==117)){
                            ChessPiece *tempRookBlackGrandRoqueBottom=squareAt(63)->piece();
                            squareAt(63)->piece()->setSquareLocation(116);
                            squareAt(63)->setPiece(nullptr);
                            setPieceOnSquare(tempRookBlackGrandRoqueBottom,116);
                            selectedPiece->setGrandRoqueDispo(false);
                            squareAt(63)->setCastlingSelected(false);/*fois 2*/
                        }

                        if((selectedPiece->grandRoqueDispo()==true)
                                && (selectedPiece->isWhite()==false)
                                && (selectedPiece->squareLocation()==4)
                                && (destination->indexHexa()==2)){
                            ChessPiece *tempRookBlackGrandRoqueTop=squareAt(0)->piece();
                            squareAt(0)->piece()->setSquareLocation(3);
                            squareAt(0)->setPiece(nullptr);
                            setPieceOnSquare(tempRookBlackGrandRoqueTop,3);
                            selectedPiece->setGrandRoqueDispo(false);
                            squareAt(0)->setCastlingSelected(false);/*fois 2*/
                        }

                        //En passant
                        if(ChessBoard::m_choixPlayer==true){
                            if(selectedPiece->isWhite()==true){
                                if(((ChessBoard::getPiece(selectedPiece->squareLocation()-16)==nullptr))
                                        &&(destination->indexHexa()==selectedPiece->squareLocation()-32)&&(ChessBoard::getPiece(selectedPiece->squareLocation()-32)==nullptr)){
                                if(selectedPiece->squareLocation()==96||selectedPiece->squareLocation()==97||selectedPiece->squareLocation()==98||selectedPiece->squareLocation()==99
                                        ||selectedPiece->squareLocation()==100||selectedPiece->squareLocation()==101||selectedPiece->squareLocation()==102||selectedPiece->squareLocation()==103)
                                    selectedPiece->setEnPassant(2);/*qDebug()<<"white bottom moving up en passant setting=2 "<<selectedPiece->enPassant();*/}

                            }



                            else {
                                if(((ChessBoard::getPiece(selectedPiece->squareLocation()+16)==nullptr))
                                        &&(destination->indexHexa()==selectedPiece->squareLocation()+32)&&(ChessBoard::getPiece(selectedPiece->squareLocation()+32)==nullptr)){
                                if(selectedPiece->squareLocation()==16||selectedPiece->squareLocation()==17||selectedPiece->squareLocation()==18||selectedPiece->squareLocation()==19
                                        ||selectedPiece->squareLocation()==20||selectedPiece->squareLocation()==21||selectedPiece->squareLocation()==22||selectedPiece->squareLocation()==23)
                                    selectedPiece->setEnPassant(2);/*qDebug()<<"black top moving down en passant setting=2 "<<selectedPiece->enPassant();*/}


                            }
                        }
                        else {
                            if(selectedPiece->isWhite()==true){
                                if(((ChessBoard::getPiece(selectedPiece->squareLocation()+16)==nullptr))
                                        &&(destination->indexHexa()==selectedPiece->squareLocation()+32)&&(ChessBoard::getPiece(selectedPiece->squareLocation()+32)==nullptr)){
                                if(selectedPiece->squareLocation()==16||selectedPiece->squareLocation()==17||selectedPiece->squareLocation()==18||selectedPiece->squareLocation()==19
                                        ||selectedPiece->squareLocation()==20||selectedPiece->squareLocation()==21||selectedPiece->squareLocation()==22||selectedPiece->squareLocation()==23)
                                    selectedPiece->setEnPassant(2);/*qDebug()<<"white top moving down en passant setting=2 "<<selectedPiece->enPassant();*/}

                            }

                            else {
                                if(((ChessBoard::getPiece(selectedPiece->squareLocation()-16)==nullptr))
                                        &&(destination->indexHexa()==selectedPiece->squareLocation()-32)&&(ChessBoard::getPiece(selectedPiece->squareLocation()-32)==nullptr)){
                                if(selectedPiece->squareLocation()==96||selectedPiece->squareLocation()==97||selectedPiece->squareLocation()==98||selectedPiece->squareLocation()==99
                                        ||selectedPiece->squareLocation()==100||selectedPiece->squareLocation()==101||selectedPiece->squareLocation()==102||selectedPiece->squareLocation()==103)
                                    selectedPiece->setEnPassant(2);/*qDebug()<<"black bottom moving up en passant setting=2 "<<selectedPiece->enPassant();*/}

                            }


                        }

                        if((typeid(*selectedPiece)==typeid(Pawn))&&(destination->indexHexa()==selectedPiece->squareLocation()+15)
                                && (squareAt(convHexaToInt(selectedPiece->squareLocation()-1))->piece()!=nullptr)
                                && (squareAt(convHexaToInt(selectedPiece->squareLocation()-1))->piece()->enPassant()==1)){
                            delete squareAt(convHexaToInt(selectedPiece->squareLocation()-1))->piece();
                            squareAt(convHexaToInt(selectedPiece->squareLocation()-1))->setPiece(nullptr);

                        }/*fois 2*/

                        if((typeid(*selectedPiece)==typeid(Pawn))&&(destination->indexHexa()==selectedPiece->squareLocation()+17)
                                && (squareAt(convHexaToInt(selectedPiece->squareLocation()+1))->piece()!=nullptr)
                                && (squareAt(convHexaToInt(selectedPiece->squareLocation()+1))->piece()->enPassant()==1)){
                            delete squareAt(convHexaToInt(selectedPiece->squareLocation()+1))->piece();
                            squareAt(convHexaToInt(selectedPiece->squareLocation()+1))->setPiece(nullptr);

                        }/*fois 2*/

                        if((typeid(*selectedPiece)==typeid(Pawn))&&(destination->indexHexa()==selectedPiece->squareLocation()-15)
                                && (squareAt(convHexaToInt(selectedPiece->squareLocation()+1))->piece()!=nullptr)
                                && (squareAt(convHexaToInt(selectedPiece->squareLocation()+1))->piece()->enPassant()==1)){
                            delete squareAt(convHexaToInt(selectedPiece->squareLocation()+1))->piece();
                            squareAt(convHexaToInt(selectedPiece->squareLocation()+1))->setPiece(nullptr);

                        }/*fois 2*/

                        if((typeid(*selectedPiece)==typeid(Pawn))&&(destination->indexHexa()==selectedPiece->squareLocation()-17)
                                && (squareAt(convHexaToInt(selectedPiece->squareLocation()-1))->piece()!=nullptr)
                                && (squareAt(convHexaToInt(selectedPiece->squareLocation()-1))->piece()->enPassant()==1)){
                            delete squareAt(convHexaToInt(selectedPiece->squareLocation()-1))->piece();
                            squareAt(convHexaToInt(selectedPiece->squareLocation()-1))->setPiece(nullptr);

                        }/*fois 2*/


                        m_selectedPieceSquare->piece()->setSquareLocation(destination->indexHexa());
                        m_selectedPieceSquare->setPiece(nullptr);
                        setPieceOnSquare(selectedPiece,destination->indexHexa());
                        selectedPiece->setMoveCount(selectedPiece->moveCount()+1);
                        m_selectedPieceSquare->setSelected(false);m_selectedPieceSquare=nullptr;
                        for(int i=0; i<64; i++){
                            squareAt(i)->setDestiSelected(false);
                            squareAt(i)->setCheck(false);}
                        squareAt(63)->setCastlingSelected(false);/*fois 2*/
                        squareAt(0)->setCastlingSelected(false);/*fois 2*/
                        squareAt(56)->setCastlingSelected(false);/*fois 2*/
                        squareAt(7)->setCastlingSelected(false);/*fois 2*/
                        m_pieceValidatedMove.clear();
                        m_pieceAlreadySelected=false;
                        doPawnPromotion(selectedPiece,selectedPiece->pawnPromotion());
                        checkCheck();
//                        qDebug()<<checkCheck();
                        for(int i=0; i<64; i++){
                            if((squareAt(i)->piece()!=nullptr)&&(squareAt(i)->piece()->enPassant()==2||squareAt(i)->piece()->enPassant()==1))
                            squareAt(i)->piece()->setEnPassant(squareAt(i)->piece()->enPassant()-1);}
                        setAMonTour(!m_aMonTour);/*m_aMonTour=!m_aMonTour;*/
                        finGame();
                    }

                }
                else{
//                    qDebug()<<destination->indexHexa();
                    m_selectedPieceSquare->setSelected(false);
                    for(int i=0; i<64; i++)
                    squareAt(i)->setDestiSelected(false);
                    squareAt(63)->setCastlingSelected(false);/*fois 2*/
                    squareAt(0)->setCastlingSelected(false);/*fois 2*/
                    squareAt(56)->setCastlingSelected(false);/*fois 2*/
                    squareAt(7)->setCastlingSelected(false);/*fois 2*/
                    m_pieceValidatedMove.clear();
                    m_pieceAlreadySelected=false;
                            //       Vérification en utilisant QDebug
//                    for(QVector<quint8>::iterator iter=m_pieceValidatedMove.begin();iter !=m_pieceValidatedMove.end();++iter){
//                        qDebug()<<"position : "<<m_pieceValidatedMove.indexOf(*iter)<<" on a : "<<*iter<<endl;

//                 }

                }

            }



    }

}

void ChessBoard::finishPromotion()
{
    switch (m_promoPieceChoice) {

    case 1 :
        m_finishPromotion= new Queen(m_finishPromotionLocation,m_finishPromotionIsWhite);
        setPieceOnSquare(m_finishPromotion,m_finishPromotionLocation);
        setPromoPieceChoice(0);
        checkCheck();
        qDebug()<<checkCheck();
        finGame();
        break;

    case 2 :
        m_finishPromotion= new Rook(m_finishPromotionLocation,m_finishPromotionIsWhite);
        setPieceOnSquare(m_finishPromotion,m_finishPromotionLocation);
        setPromoPieceChoice(0);
        checkCheck();
        qDebug()<<checkCheck();
        finGame();
        break;

    case 3 :
        m_finishPromotion= new Bishop(m_finishPromotionLocation,m_finishPromotionIsWhite);
        setPieceOnSquare(m_finishPromotion,m_finishPromotionLocation);
        setPromoPieceChoice(0);
        checkCheck();
        qDebug()<<checkCheck();
        finGame();
        break;

    case 4 :
        m_finishPromotion= new Knight(m_finishPromotionLocation,m_finishPromotionIsWhite);
        setPieceOnSquare(m_finishPromotion,m_finishPromotionLocation);
        setPromoPieceChoice(0);
        checkCheck();
        qDebug()<<checkCheck();
        finGame();
        break;

    default :
        qDebug()<<"don't forget to check check ^^";




    }
}

