#pragma once
#include "01_Board.h"
#include "02_Piece.h"

class Pawn : public Piece
{
public:
	Pawn(int color);
	bool valid_move(std::string msgFromGraphics, Piece* board[8][8]) override;
};
