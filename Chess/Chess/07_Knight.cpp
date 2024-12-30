#include "07_Knight.h"

Knight::Knight(int color) : Piece(color) {
    if (color == 0) {
        _piace_type = "N";
    }
    else {
        _piace_type = "n";
    }
}
bool Knight::valid_move(std::string msgFromGraphics, Piece* board[8][8])
{
    return false;
}
