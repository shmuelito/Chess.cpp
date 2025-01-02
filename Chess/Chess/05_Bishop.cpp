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
    int curr_col = msgFromGraphics[0] - 'a'; //convert char to int
    int curr_row = 8 - (msgFromGraphics[1] - '0'); //convert char to int - 1 so 0-7
    int des_col = msgFromGraphics[2] - 'a'; //convert char to int
    int des_row = 8 - (msgFromGraphics[3] - '0'); //convert char to int - 1 so 0-7

    // Check if the move is diagonal
    if (abs(des_col - curr_col) != abs(des_row - curr_row)) 
    {
        return false;
    }

    int col_step = 0;
    int row_step = 0;

    // direction of move
    if (des_col > curr_col) 
    {
        col_step = 1;
    }
    else 
    {
        col_step = -1;
    }

    if (des_row > curr_row) 
    {
        row_step = 1;
    }
    else 
    {
        row_step = -1;
    }

    int col = curr_col + col_step;
    int row = curr_row + row_step;

    // Check if the path is clear
    while (col != des_col && row != des_row) 
    {
        if (board[row][col] != nullptr) 
        {
            return false; // Path is blocked
        }
        col += col_step;
        row += row_step;
    }

    Piece* dest_piece = board[des_row][des_col];
    if (dest_piece != nullptr && dest_piece->get_piece_color() == this->get_piece_color()) 
    {
        return false; // piece of the same color
    }

    return true; 
}

