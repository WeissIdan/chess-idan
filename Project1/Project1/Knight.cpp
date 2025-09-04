#include "Knight.h"
#include "Player.h"
#include "Board.h"

Knight::Knight(Player* player, int row, int col, Board* board)
    : Piece(player, 'N', row, col, board)
{
}

bool Knight::isLegalMove(int row, int col) const
{
    int dRow = abs(row - _row);
    int dCol = abs(col - _col);

    // Check for L-shape move
    bool isLShape = (dRow == 2 && dCol == 1) || (dRow == 1 && dCol == 2);

    // Check if destination is not occupied by own piece
    bool notOwnPiece = !_brd->isPieceOfPlayer(row, col, _player);

    return isLShape && notOwnPiece;
}