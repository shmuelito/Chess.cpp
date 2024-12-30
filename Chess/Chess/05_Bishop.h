#pragma once
#include "01_Board.h"
#include "02_Piece.h"

class Bishop : public Piece
{
public:
	Bishop(int color);
	bool valid_move(std::string msgFromGraphics, Piece* board[8][8]) override;
};

