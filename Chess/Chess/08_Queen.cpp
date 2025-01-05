#include "08_Queen.h"
#include "stdafx.h"

Queen::Queen(int color) : Piece(color) 
{
    if (color == 0) 
    {
        _piece_type = "Q";
    }
    else {
        _piece_type = "q";
    }
}

/**
 * @brief 
 * @param msgFromGraphics 
 * @param board 
 * @return 
 */
bool Queen::valid_move(std::string msgFromGraphics, Piece* board[8][8])
{
    Bishop bishop(_piaceColor); 
    Rook rook(_piaceColor);
    // bishop + rook = Queen
    return bishop.valid_move(msgFromGraphics, board) || rook.valid_move(msgFromGraphics, board);
}
