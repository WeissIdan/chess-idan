#pragma once
#include "Piece.h"
class Player;
class Board;
class Queen : public Piece
{
public:
	Queen(Player* player, int row, int col, Board* board);
	virtual bool isLegalMove(int, int) const;

private:

};