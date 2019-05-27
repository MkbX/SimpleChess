#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QObject>
#include <QQmlListProperty>
#include <QDebug>

#include "chesssquare.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"

/**
 * @brief The ChessBoard class; Essentially a list of ChessSquares; Controls game logic;
 */

class ChessBoard : public QObject
{
        Q_OBJECT

public:

    ChessBoard();

    Q_PROPERTY(QQmlListProperty<ChessSquare> chessboard READ chessboard CONSTANT)
    QQmlListProperty<ChessSquare> chessboard() {return QQmlListProperty<ChessSquare>(this,m_chessBoard);}

    Q_PROPERTY(QString endMateOrStale READ endMateOrStale WRITE setEndMateOrStale NOTIFY endMateOrStaleChanged)
    QString endMateOrStale()const {return m_endMateOrStale;}
    void setEndMateOrStale(QString newEnd){if(newEnd==m_endMateOrStale) return; m_endMateOrStale = newEnd; emit endMateOrStaleChanged();}

    Q_PROPERTY(bool choixPlayer READ choixPlayer WRITE setChoixPlayer NOTIFY choixPlayerChanged)
    bool choixPlayer()const {return m_choixPlayer;}
    void setChoixPlayer(bool newChoiceP){if(newChoiceP==m_choixPlayer) return; m_choixPlayer = newChoiceP; emit choixPlayerChanged();}

    Q_PROPERTY(bool tongue READ tongue  WRITE setTongue NOTIFY tongueChanged)
    bool tongue()const {return m_tongue;}
    void setTongue(bool newTongue){if(newTongue==m_tongue) return; m_tongue = newTongue; emit tongueChanged();}

    Q_PROPERTY(bool getPromo READ getPromo  WRITE setGetPromo NOTIFY getPromoChanged)
    bool getPromo()const {return m_getPromo;}
    void setGetPromo(bool newBool){if(newBool==m_getPromo) return; m_getPromo = newBool; emit getPromoChanged();}

    Q_PROPERTY(int promoPieceChoice READ promoPieceChoice  WRITE setPromoPieceChoice NOTIFY promoPieceChoiceChanged)
    int promoPieceChoice()const {return m_promoPieceChoice;}
    void setPromoPieceChoice(int intPiece){if(intPiece==m_promoPieceChoice) return; m_promoPieceChoice = intPiece; emit promoPieceChoiceChanged();}

    Q_PROPERTY(bool finishPromotionIsWhite READ finishPromotionIsWhite  WRITE setFinishPromotionIsWhite NOTIFY finishPromotionIsWhiteChanged)
    bool finishPromotionIsWhite()const {return m_finishPromotionIsWhite;}
    void setFinishPromotionIsWhite(bool bFinish){if(bFinish==m_finishPromotionIsWhite) return; m_finishPromotionIsWhite = bFinish; emit finishPromotionIsWhiteChanged();}

    Q_PROPERTY(bool aMonTour READ aMonTour  WRITE setAMonTour NOTIFY aMonTourChanged)
    bool aMonTour()const {return m_aMonTour;}
    void setAMonTour(bool qaMonTour){if(qaMonTour==m_aMonTour) return; m_aMonTour = qaMonTour; emit aMonTourChanged();}

    static QList<ChessSquare*> m_chessBoard;
    static QList<ChessSquare*> m_illusionaryChessBoard;
    static ChessPiece *getPiece(quint8 endroit);
    static ChessPiece *getPieceIllu(quint8 endroitIllu);
    static void totalSquaresMaquis(bool colorMaquis);
    static void totalSquaresMaquisIllu(bool colorMaquisIllu);
    static void createIllusionaryBoard();
    static void setPieceOnSquareIllu(ChessPiece* pIllu, quint8 locHexaIllu);   

    static QString m_endMateOrStale;
    static bool m_tongue;
    static bool m_choixPlayer;
    static bool m_getPromo;
    static int m_promoPieceChoice;
    static QVector<quint8> m_vectorMaquis;
    static QVector<quint8> m_vectorMaquisIllu;

private:

    ChessSquare *m_selectedPieceSquare=nullptr;        
    QVector<quint8> m_pieceValidatedMove;
    bool m_pieceAlreadySelected=false;
    bool m_aMonTour=true;

    ChessPiece *m_finishPromotion=nullptr; quint8 m_finishPromotionLocation=127; bool m_finishPromotionIsWhite;

    bool squareIsValid(quint8 indexTest) const;
    ChessSquare *squareAt(int index) const {return (index >= 0 && index < m_chessBoard.count()) ? m_chessBoard.at(index) : nullptr;}
    void setPieceOnSquare(ChessPiece* p, quint8 locHexa);
    bool validatePieceTrivialCanMoveTo(quint8 fromlistVector, ChessPiece *pieceV);



    int convHexaToInt(quint8 hex);
    bool doPawnPromotion(ChessPiece *pawnToPromote, bool isItOkToPromote);

public slots:

    QString chessBoardSquareAt(int indd) const;
    void mouseClick(int indexx);
    void finishPromotion();
    bool checkCheck();
    bool ownCheckIllu();
    void initW();
    void initB();
    void finGame();


signals:
    void chessBoardChanged();
    void getPromoChanged();
    void promoPieceChoiceChanged();
    void finishPromotionIsWhiteChanged();
    void aMonTourChanged();
    void tongueChanged();
    void choixPlayerChanged();
    void endMateOrStaleChanged();



};

#endif // CHESSBOARD_H
