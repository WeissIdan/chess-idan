#pragma once
#include "Piece.h"
class Plaeyr;
class Board;
class Queen : public Piece
{
public:
	Queen(Player*, int row, int col, Board*);
	virtual bool isLegalMove(int, int) const;

private:

};