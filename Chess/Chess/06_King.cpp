#include "06_King.h"
King::King(int color) : Piece(color) {
    if (color == 0) {
        _piace_type = "K";
    }
    else {
        _piace_type = "k";
    }
}
bool King::valid_move(std::string msgFromGraphics, Piece* board[8][8])
{
    return false;
}
