#include "04_Pawn.h"


Pawn::Pawn(int color) : Piece(color) 
{
    if (color == 0) 
    {
        _piace_type = "P";
    }
    else 
    {
        _piace_type = "p";
    }
}

bool Pawn::valid_move(std::string msgFromGraphics, Piece* board[8][8])
{
    return true;
}
