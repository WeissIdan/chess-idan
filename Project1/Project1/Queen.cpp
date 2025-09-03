#include "Queen.h"

Queen::Queen(Player* player, int row, int col, Board* board)
    : Piece(player, 'Q', row, col, board)
{
}

bool Queen::isLegalMove(int row, int col) const
{
    if ((row == _row && col != _col) || (col == _col && row != _row)) {
        return isWayFree(row, col);
    }
    else if (abs(row - _row) == abs(col - _col)) {
        return isWayFree(row, col);
    }
    return false;
}