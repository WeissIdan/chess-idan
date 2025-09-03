#pragma once

#include "Piece.h"
class Player;
class Board;
class Bishop : public Piece
{
public:
	Bishop(Player* p, int row, int col, Board* b);
	virtual bool isLegalMove(int, int) const;

private:

};