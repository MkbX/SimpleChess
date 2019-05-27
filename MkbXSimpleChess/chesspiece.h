#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <QObject>
#include <QVector>

/**
 * @brief The ChessPiece class; Base class for pieces;
 */

class ChessPiece : public QObject
{
    Q_OBJECT

public:

    Q_PROPERTY(QString type READ type CONSTANT)
    QString type() const {return m_type;}

    Q_PROPERTY(QString classeKing READ classeKing CONSTANT)
    QString classeKing() const {return m_classeKing;}

    Q_PROPERTY(bool isWhite READ isWhite CONSTANT)
    bool isWhite()const {return m_isWhite;}

    Q_PROPERTY(quint8 squareLocation READ squareLocation WRITE setSquareLocation NOTIFY squareLocationChanged)
    quint8 squareLocation() const {return m_squareLocation;}
    void setSquareLocation(const quint8 &squareLocation){if(squareLocation==m_squareLocation) return; m_squareLocation = squareLocation; emit squareLocationChanged();}

    ChessPiece(QObject *parent=nullptr);
    ChessPiece(quint8 indexLocation, bool color);

    virtual ~ChessPiece()/*=0*/;
    virtual QVector<quint8> trivialCanMoveTo();
    virtual QVector<quint8> trivialCanMoveToAttack();
    virtual QVector<quint8> trivialCanMoveToAttackIllu();
    virtual bool pawnPromotion() const{return false;}





    int moveCount() const;
    void setMoveCount(int moveCount);

    bool petitRoqueDispo() const;
    void setPetitRoqueDispo(bool petitRoqueDispo);

    bool grandRoqueDispo() const;
    void setGrandRoqueDispo(bool grandRoqueDispo);

    int enPassant() const;
    void setEnPassant(int enPassant);

protected:
    quint8 m_squareLocation;
    bool m_isWhite;
    QString m_type;
    QString m_classeKing;
    int m_moveCount;
    bool m_petitRoqueDispo;
    bool m_grandRoqueDispo;
    int m_enPassant;

signals:
    void typeChanged();
    void squareLocationChanged();
};

#endif // CHESSPIECE_H
