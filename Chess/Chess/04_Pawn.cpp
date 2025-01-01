#include "04_Pawn.h"


Pawn::Pawn(int color) : Piece(color) 
{
    if (color == 0) 
    {
        _piece_type = "P";
    }
    else 
    {
        _piece_type = "p";
    }
}

bool Pawn::valid_move(std::string msgFromGraphics, Piece* board[8][8])
{
    int curr_col = msgFromGraphics[0] - 'a'; //convert char to int
    int curr_row = 8 - (msgFromGraphics[1] - '0'); //convert char to int - 1 so 0-7

    int des_col = msgFromGraphics[2] - 'a'; //convert char to int
    int des_row = 8 - (msgFromGraphics[3] - '0'); //convert char to int - 1 so 0-7

    int direction;

    if (_piaceColor == 0) //if  White moves up -1 if Black moves down +1
    {
        direction = -1;
    }
    else
    {
        direction = 1;
    }

    // Check for regular forward move 1 square
    if (curr_col == des_col)
    {
        bool isOneStep = des_row == curr_row + direction;
        bool isDestEmpty = board[des_row][des_col] == nullptr;

        if (isOneStep && isDestEmpty)
        {
            return true;
        }

        // Check if it's the first move 2 squares forward
        bool isStartPos = (_piaceColor == 0 && curr_row == 6) || (_piaceColor == 1 && curr_row == 1);
        bool isTwoSteps = des_row == curr_row + 2 * direction;
        bool isSquareEmpty = board[curr_row + direction][curr_col] == nullptr;

        if (isStartPos && isTwoSteps && isSquareEmpty && isDestEmpty)
        {
            return true;
        }
    }

    // Check for diagonal capture
    if (std::abs(des_col - curr_col) == 1)
    {
        bool isOneStepDiag = des_row == curr_row + direction;
        bool isNotYourPiece = board[des_row][des_col] != nullptr && board[des_row][des_col]->get_piece_color() != this->_piaceColor;

        if (isOneStepDiag && isNotYourPiece)
        {
            return true;
        }
    }

    // Invalid move
    return false;
}
