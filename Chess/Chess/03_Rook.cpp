#include "03_Rook.h"


 Rook::Rook(int color) : Piece(color) {
     if (color == 0) 
     {
         _piace_type = "R";
     }
     else 
     {
         _piace_type = "r";
     }
 }
bool Rook::valid_move(std::string msgFromGraphics, Piece* board[8][8])
{
    return false;
}
