#include "01_Board.h"
#include "stdafx.h"
#include <string>


Board::Board() : _curr_player(0), isGameOver(false)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			_board[i][j] = nullptr;
		}
	}
}

void Board::intialise_board()
{
    // Initialize pawns
    for (int i = 0; i < 8; ++i) {
        _board[1][i] = new Pawn(1); // Black pawns
        _board[6][i] = new Pawn(0); // White pawns
    }

    // Initialize rooks
    _board[0][0] = new Rook(1);
    _board[0][7] = new Rook(1);
    _board[7][0] = new Rook(0);
    _board[7][7] = new Rook(0);

    // Initialize knights
    _board[0][1] = new Knight(1);
    _board[0][6] = new Knight(1);
    _board[7][1] = new Knight(0);
    _board[7][6] = new Knight(0);

    // Initialize bishops
    _board[0][2] = new Bishop(1);
    _board[0][5] = new Bishop(1);
    _board[7][2] = new Bishop(0);
    _board[7][5] = new Bishop(0);

    // Initialize queens
    _board[0][3] = new Queen(1);
    _board[7][3] = new Queen(0);

    // Initialize kings
    _board[0][4] = new King(1);
    _board[7][4] = new King(0);
}

void Board::print_board()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (_board[i][j] == nullptr)
                std::cout << "# ";
            else
                std::cout << _board[i][j]->get_piece_type() << " ";
        }
        std::cout << std::endl;
    }
}


void Board::switchTurn()
{
    if (_curr_player == 1)
    {
        _curr_player = 0;
    }
    else
    {
        _curr_player = 1;
    }
}

int Board::valid_Move(std::string msgFromGraphics)
{
    Piece* curr_square;
    Piece* des_square;

    int curr_col = msgFromGraphics[0] - 'a'; // Convert column char to index 0-7
    int curr_row = 8 - (msgFromGraphics[1] - '0'); // Flip the row index for 2D array

    int des_col = msgFromGraphics[2] - 'a'; // Convert column char to index 0-7
    int des_row = 8 - (msgFromGraphics[3] - '0'); // Flip the row index for 2D array


    if (curr_row < 0 || curr_row > 7 || curr_col < 0 || curr_col > 7 ||
        des_row < 0 || des_row > 7 || des_col < 0 || des_col > 7)
    {
        return 5; // Invalid move
    }

    if (curr_row == des_row && curr_col == des_col)
    {
        return 7; // Invalid move curr and des squares are the same
    }

    curr_square = _board[curr_row][curr_col];
    des_square = _board[des_row][des_col];

    std::cout << "Current position (" << curr_row << ", " << curr_col << "): " << std::endl;
    std::cout << "Destination position (" << des_row << ", " << des_col << "): " << std::endl;

    if (curr_square == nullptr)
    {
        return 2; //error, because we can't move an empty square to somewhere
    }

    if (curr_square->get_piece_color() != _curr_player)
    {
        return 6; //error, Wrong player's piece
    }

    if (des_square != nullptr && curr_square->get_piece_color() == des_square->get_piece_color())
    {
        return 3; //error, Same color piece at des
    }

    if (!curr_square->valid_move(msgFromGraphics, _board))
    {
        return 6; // Invalid move
    }

    if (des_square != nullptr)
    {
        if (des_square->get_piece_type() == "K" && _curr_player == 1 || des_square->get_piece_type() == "k" && _curr_player == 0)
        {
            return 6; 
        }
    }

    //update the board
    _board[curr_row][curr_col] = nullptr;
    _board[des_row][des_col] = curr_square;

    // Check if curr player king in check
    if (check_if_check(1 - _curr_player))
    {
        // Undo the move
        _board[curr_row][curr_col] = curr_square;
        _board[des_row][des_col] = des_square;
        return 4;
    }

    // Check if the opponent King is in check
    if (check_if_check(_curr_player))
    {
        return 1;
    }

    return 0;
}

bool Board::check_if_check(int curr_player)
{
    std::string goalPosition;
    std::string currPosition;
    std::string msgFromGraphics;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (_board[i][j] != nullptr && _board[i][j]->get_piece_color() != curr_player)
            {
                if (_board[i][j]->get_piece_type() == "k" || _board[i][j]->get_piece_type() == "K")
                {
                    goalPosition = std::string(1, 'a' + j) + std::to_string(8 - i);
                    break;
                }
            }
        }
        if (!goalPosition.empty()) break;
    }

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (_board[i][j] != nullptr && _board[i][j]->get_piece_color() == curr_player)
            {
                currPosition = std::string(1, 'a' + j) + std::to_string(8 - i);
                msgFromGraphics = currPosition + goalPosition;

                if (_board[i][j]->valid_move(msgFromGraphics, _board))
                {
                    return true;
                }
            }
        }
    }

    return false; // No check
}


