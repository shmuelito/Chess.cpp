#pragma once
#include "02_Piece.h"
#include <iostream>


class Board
{
protected:
	Piece* _board[8][8];
	int _curr_player; // 0 - white | 1 - black
	bool isGameOver;
public:
	Board();
	~Board();
	void intialise_board();
	void print_board();
	void switchTurn();
	int valid_Move(std::string msgFromGraphics);
	bool check_if_check(int _curr_player);
};
