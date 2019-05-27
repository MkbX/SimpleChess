#include "chesspiece.h"


ChessPiece::ChessPiece(QObject *parent):QObject(parent)
{

}

ChessPiece::ChessPiece(quint8 indexLocation, bool color):m_squareLocation(indexLocation),m_isWhite(color),m_type("P")
{
    m_type = (color ? "WP" : "BP");
    m_classeKing = "NoKing";
    m_moveCount=0;
    m_petitRoqueDispo=false;
    m_grandRoqueDispo=false;
    m_enPassant=0;
}

//vecteur de déplacement
QVector<quint8> ChessPiece::trivialCanMoveTo()
{
    QVector<quint8> invalidVector(1,127);
    return invalidVector;

}

//vecteur d'attaque
QVector<quint8> ChessPiece::trivialCanMoveToAttack()
{
    QVector<quint8> invalidVectorAttack(1,127);
    return invalidVectorAttack;
}

//vecteur d'attaque dans l'échiquier sombre
QVector<quint8> ChessPiece::trivialCanMoveToAttackIllu()
{
    QVector<quint8> invalidVectorAttackIllu(1,127);
    return invalidVectorAttackIllu;
}

int ChessPiece::moveCount() const
{
    return m_moveCount;
}

void ChessPiece::setMoveCount(int moveCount)
{
    m_moveCount = moveCount;
}

bool ChessPiece::petitRoqueDispo() const
{
    return m_petitRoqueDispo;
}

void ChessPiece::setPetitRoqueDispo(bool petitRoqueDispo)
{
    m_petitRoqueDispo = petitRoqueDispo;
}

bool ChessPiece::grandRoqueDispo() const
{
    return m_grandRoqueDispo;
}

void ChessPiece::setGrandRoqueDispo(bool grandRoqueDispo)
{
    m_grandRoqueDispo = grandRoqueDispo;
}

int ChessPiece::enPassant() const
{
    return m_enPassant;
}

void ChessPiece::setEnPassant(int enPassant)
{
    m_enPassant = enPassant;
}

ChessPiece::~ChessPiece()
{
    
}


