#ifndef CHESSSQUARE_H
#define CHESSSQUARE_H

#include <QObject>
#include "chesspiece.h"

/**
 * @brief The ChessSquare class; Basically each square composing the board;
 */

class ChessSquare : public QObject
{
    Q_OBJECT

public:

    Q_PROPERTY(quint8 indexHexa READ indexHexa CONSTANT)

    Q_PROPERTY(ChessPiece* piece READ piece WRITE setPiece NOTIFY pieceChanged)
    ChessPiece *piece() const {return m_piece;}
    void setPiece(ChessPiece *piece) {if(piece==m_piece) return; m_piece = piece; emit pieceChanged();}

    Q_PROPERTY(bool selected READ selected WRITE setSelected NOTIFY selectedChanged)
    bool selected() const {return m_selected;}
    void setSelected(bool selected) {if(selected==m_selected) return; m_selected = selected; emit selectedChanged();}

    Q_PROPERTY(bool destiSelected READ destiSelected WRITE setDestiSelected NOTIFY destiSelectedChanged)
    bool destiSelected() const {return m_destiSelected;}
    void setDestiSelected(bool destiSelected) {if(destiSelected==m_destiSelected) return; m_destiSelected = destiSelected; emit destiSelectedChanged();}

    Q_PROPERTY(bool check READ check WRITE setCheck NOTIFY checkChanged)
    bool check() const {return m_check;}
    void setCheck(bool newCheck) {if(newCheck==m_check) return; m_check = newCheck; emit checkChanged();}

    Q_PROPERTY(bool castlingSelected READ castlingSelected WRITE setCastlingSelected NOTIFY castlingSelectedChanged)
    bool castlingSelected() const {return m_castlingSelected;}
    void setCastlingSelected(bool newCastling) {if(newCastling==m_castlingSelected) return; m_castlingSelected = newCastling; emit castlingSelectedChanged();}

    ChessSquare(QObject *parent=nullptr);
    ChessSquare(quint8 indexAssign);

    quint8 indexHexa() const;
    int rank() const;
    int file() const;



private:
    quint8 m_indexHexa;
    int m_rank;
    int m_file;
    int m_indexInt;
    ChessPiece* m_piece;
    bool m_selected;
    bool m_destiSelected;
    bool m_check;
    bool m_castlingSelected;

signals:
    void selectedChanged();
    void pieceChanged();
    void destiSelectedChanged();
    void checkChanged();
    void castlingSelectedChanged();

};

#endif // CHESSSQUARE_H
