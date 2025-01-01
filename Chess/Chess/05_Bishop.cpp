#include "05_Bishop.h"
Bishop::Bishop(int color) : Piece(color) {
    if (color == 0) {
        _piece_type = "B";
    }
    else {
        _piece_type = "b";
    }
}
bool Bishop::valid_move(std::string msgFromGraphics, Piece* board[8][8])
{
    return false;
}
