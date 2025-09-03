#include "Knight.h"
#include "Player.h"
#include "Board.h"

Knight::Knight(Player* player, int row, int col, Board* board)
    : Piece(player, 'N', row, col, board)
{
}

bool Knight::isLegalMove(int row, int col) const
{
    // Implement Knight-specific move logic here
    return false;
}