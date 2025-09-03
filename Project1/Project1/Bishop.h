#pragma once

#include "Piece.h"
class Plaeyr;
class Board;
class Bishop : public Piece
{
public:
	Bishop(Player*, int row, int col, Board*);
	virtual bool isLegalMove(int, int) const;

private:

};