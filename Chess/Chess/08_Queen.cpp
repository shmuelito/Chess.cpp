#include "08_Queen.h"

Queen::Queen(int color) : Piece(color) {
    if (color == 0) {
        _piace_type = "Q";
    }
    else {
        _piace_type = "q";
    }
}
bool Queen::valid_move(std::string msgFromGraphics, Piece* board[8][8])
{
    return false;
}
