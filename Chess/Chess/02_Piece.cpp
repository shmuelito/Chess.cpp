#include "02_Piece.h"


Piece::Piece(int color) : _piaceColor(color),_piace_type(""){}

std::string Piece::get_piece_type() const
{
	return _piace_type;
}

int Piece::get_piece_color() const
{
	return _piaceColor;
}

bool validmoves()
{
	return false;
}
