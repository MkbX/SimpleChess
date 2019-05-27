#include "chesssquare.h"

ChessSquare::ChessSquare(QObject *parent):QObject(parent)
{

}

ChessSquare::ChessSquare(quint8 indexAssign):m_indexHexa(indexAssign),m_piece(nullptr),m_selected(false),m_destiSelected(false),m_castlingSelected(false)
{
    m_rank= m_indexHexa >> 4;
    m_file=m_indexHexa & 7;
    m_indexInt = (8*m_rank)+m_file;
}

quint8 ChessSquare::indexHexa() const
{
    return m_indexHexa;
}

int ChessSquare::rank() const
{
    return m_rank;
}

int ChessSquare::file() const
{
    return m_file;
}




