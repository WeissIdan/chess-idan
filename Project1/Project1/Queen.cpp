#include "Queen.h"

Queen::Queen(Player* player, int row, int col, Board* board)
    : Piece(player, 'Q', row, col, board)
{
}

bool Queen::isLegalMove(int row, int col) const
{
    // Implement Queen-specific move logic here
    return false;
}