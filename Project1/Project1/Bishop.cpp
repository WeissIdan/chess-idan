#include "Bishop.h"

Bishop::Bishop(Player* player, int row, int col, Board* board)
    : Piece(player, 'B', row, col, board)
{
}

bool Bishop::isLegalMove(int row, int col) const
{
    if( abs(row - _row) == abs(col - _col) ) {
        return isWayFree(row, col);
	}
    return false;
}
