#pragma once
#include <iostream>


class Piece
{
protected:
	int _piaceColor; //0 with 1 black -> https://www.learn-english-online.org/
	std::string _piace_type; // type of piace
public:
	Piece(int color);
	virtual	bool valid_move(std::string msgFromGraphics, Piece* _board[8][8]) = 0;

	std::string get_piece_type() const;
	int get_piece_color() const;
};

