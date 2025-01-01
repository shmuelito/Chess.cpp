#include "02_Piece.h"


Piece::Piece(int color) : _piaceColor(color), _piece_type(""){}

std::string Piece::get_piece_type() const
{
	return _piece_type;
}

int Piece::get_piece_color() const
{
	return _piaceColor;
}

bool validmoves()
{
	return false;
}
