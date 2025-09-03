#pragma once

#include "Piece.h"
class Plaeyr;
class Board;

class Pawn : public Piece
{
public:
	Pawn(Player*, int row, int col, Board*);

	virtual bool isLegalMove(int, int) const;
private:
};