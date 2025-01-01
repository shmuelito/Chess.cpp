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
    int curr_col = msgFromGraphics[0] - 'a'; //convert char to int
    int curr_row = 8 - (msgFromGraphics[1] - '0'); //convert char to int - 1 so 0-7

    int des_col = msgFromGraphics[2] - 'a'; //convert char to int
    int des_row = 8 - (msgFromGraphics[3] - '0'); //convert char to int - 1 so 0-7

    char origin = msgFromGraphics[0];
    int maxmove = 0;
    int count = 0;

    //MADE TWO IFS BECAUSE ONE LONG IF IS NOT SIGMA!!!
    if ((des_row == curr_row + 1) && (des_col == curr_col - 1 || des_col == curr_col +1) && board[curr_row][curr_col]->get_piece_color() == 0) // if white eats a piece 
    {
        if (board[des_row][des_col] == nullptr) // Check is empty
        {
            return false; //if we try an eating move when theres no one on the piece we are eating, return false
        }

        else if (board[des_row][des_col] != nullptr)
        {
            if (board[curr_row][curr_col]->get_piece_color() != board[des_row][des_col]->get_piece_color())
            {
                return true;
            }
        }

        return true;
    }

    else if ((des_row = curr_row - 1) && (des_col == des_col - 1 || des_col + 1) && board[curr_row][curr_col]->get_piece_color() == 1) // if black eats a piece 
    {
        if (board[des_row][des_col] == nullptr) // Check is empty
        {
            return false; //if we try an eating move when theres no one on the piece we are eating, return false
        }

        else if (board[des_row][des_col] != nullptr)
        {
            if (board[curr_row][curr_col]->get_piece_color() != board[des_row][des_col]->get_piece_color())
            {
                return true;
            }
        }
        return true;
    }

    else //this will happen only if we are not eating something
    {
        if (des_col != curr_col)
        {
            return false; //can't happen, pawn can only move in it's own column.
        }

        else if ((des_row < curr_row && board[curr_row][curr_col]->get_piece_color() == 0) || des_row > curr_row && board[curr_row][curr_col]->get_piece_color() == 1)//checking if moving BACKWARDS
        {
            return false; //can't happen, a pawn can't move backwards.
        }

        if (curr_row == 2 && board[curr_row][curr_col]->get_piece_color() == 0|| curr_row == 7 && board[curr_row][curr_col]->get_piece_color() == 1)
        {
            maxmove = 2;
        }
        else
        {
            maxmove = 1;
        }

        if ((des_row - curr_row > maxmove && board[curr_row][curr_col]->get_piece_color() == 0) || curr_row - des_row > maxmove && board[curr_row][curr_col]->get_piece_color() == 1)
        {
            return false; //can't move more than the limit of the pawn
        }

        if (board[curr_row][curr_col]->get_piece_color() == 0)
        {
            for (int i = curr_row + 1; i < des_row; i++, count++)
            {
                if (board[i][curr_col] != nullptr) // Check is empty
                {
                    return false;
                }

                if (count > maxmove)
                {
                    return false;
                }
            }

            return true;
        }
          
        if (board[curr_row][curr_col]->get_piece_color() == 1)
        {
            for (int i = curr_row + 1; i > des_row; i--, count++)
            {
                if (board[i][curr_col] != nullptr) // Check is empty
                {
                    return false;
                }

                if (count > maxmove)
                {
                    return false;
                }
            }

            return true;
        }

    }
}
