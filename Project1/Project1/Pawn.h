#pragma once

#include "Piece.h"
class Player;
class Board;

class Pawn : public Piece
{
public:
	Pawn(Player*, int row, int col, Board*);

	virtual bool isLegalMove(int, int) const;
private:
};