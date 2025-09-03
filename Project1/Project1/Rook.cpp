#include "Rook.h"

Rook::Rook(Player* player, int row, int col, Board* board)
    : Piece(player, 'R', row, col, board)
{
}

bool Rook::isLegalMove(int row, int col) const
{
    if ((row == _row && col != _col) || (col == _col && row != _row)) {
        return isWayFree(row, col);
    }
    return false;
}