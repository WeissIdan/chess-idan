#include "Rook.h"

Rook::Rook(Player* player, int row, int col, Board* board)
    : Piece(player, 'R', row, col, board)
{
}

bool Rook::isLegalMove(int row, int col) const
{
    // Implement Rook-specific move logic here
    return false;
}