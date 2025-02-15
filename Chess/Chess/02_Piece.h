#pragma once
#include <iostream>


class Piece
{
protected:
	int _piaceColor; //0 white 1 black 
	std::string _piece_type; // type of piace
public:
	Piece(int color);
	virtual	bool valid_move(std::string msgFromGraphics, Piece* _board[8][8]) = 0;

	std::string get_piece_type() const;
	int get_piece_color() const;
};

