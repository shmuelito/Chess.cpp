#include "06_King.h"
King::King(int color) : Piece(color) 
{
    if (color == 0) 
    {
        _piece_type = "K";
    }
    else 
    {
        _piece_type = "k";
    }
}
bool King::valid_move(std::string msgFromGraphics, Piece* board[8][8])
{
    int curr_col = msgFromGraphics[0] - 'a'; // Convert column char to index 0-7
    int curr_row = 8 - (msgFromGraphics[1] - '0'); // Flip the row index for 2D array

    int des_col = msgFromGraphics[2] - 'a'; // Convert column char to index 0-7
    int des_row = 8 - (msgFromGraphics[3] - '0'); // Flip the row index for 2D array

    char origin = msgFromGraphics[0];

    //really long if statement for each possible move
    if ((des_col == curr_col + 1 && des_row == curr_row) || (des_col == curr_col - 1 && des_row == curr_row) || (des_col == curr_col && des_row == curr_row + 1) || (des_col == curr_col && des_row == curr_row - 1) || (des_col == curr_col + 1 && des_row == curr_row + 1) || (des_col == curr_col - 1 && des_row == curr_row - 1) || (des_col == curr_col + 1 && des_row == curr_row - 1) || (des_col == curr_col - 1 && des_row == curr_row + 1))
    {
        if (board[des_row][des_col] == nullptr)
        {
            return true;
        }

        else if (board[des_row][des_col] != nullptr)
        {
            if (board[curr_row][curr_col]->get_piece_color() != board[des_row][des_col]->get_piece_color())
            {
                return true;
            }
        }
    }
    return false;
}
