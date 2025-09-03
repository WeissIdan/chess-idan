#pragma once

#include "Piece.h"
class Player;
class Board;
class Knight : public Piece
{
public:
	Knight(Player*, int row, int col, Board*);
	virtual bool isLegalMove(int, int) const;

private:

};