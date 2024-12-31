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
bool Rook::valid_move(std::string msgFromGraphics, Piece* _board[8][8])
{
    int curr_col = msgFromGraphics[0] - 'a'; // Convert column char to index 0-7
    int curr_row = 8 - (msgFromGraphics[1] - '0'); // Flip the row index for 2D array

    int des_col = msgFromGraphics[2] - 'a'; // Convert column char to index 0-7
    int des_row = 8 - (msgFromGraphics[3] - '0'); // Flip the row index for 2D array

    if (curr_col == des_col)
    {
        // If moving along the same column
        if (curr_col == des_col)
        {
            int start = std::min(curr_row, des_row) + 1;
            int end = std::max(curr_row, des_row);
            for (int i = start; i < end; ++i)
            {
                if (_board[i][curr_col] != nullptr) // Check for obstacles
                {
                    return false;
                }
            }
        }
        // If moving along the same row
        if (curr_row == des_row)
        {
            int start = std::min(curr_col, des_col) + 1;
            int end = std::max(curr_col, des_col);
            for (int i = start; i < end; ++i)
            {
                if (_board[curr_row][i] != nullptr) // Check for obstacles
                {
                    return false;
                }
            }
        }
        // The path is clear
        return true;
    }

    // Not a valid rook move
    return false;
}
