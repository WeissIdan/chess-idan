#include "Pawn.h"

Pawn::Pawn(Player* player, int row, int col, Board* board)
    : Piece(player, 'P', row, col, board)
{
}

bool Pawn::isLegalMove(int row, int col) const
{
    // Implement Pawn-specific move logic here
    return false;
}