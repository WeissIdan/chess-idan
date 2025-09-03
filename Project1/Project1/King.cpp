#include "King.h"
#include "Player.h"
#include "Board.h"
#include "Piece.h"

King::King(Player* player, int row, int col, Board* board)
    : Piece(player, 'K', row, col, board)
{
}

bool King::isLegalMove(int row, int col) const
{
    int rowDist = abs(row - _row);
    int colDist = abs(col - _col);
    if ((rowDist <= 1 && colDist <= 1) && !(rowDist == 0 && colDist == 0)) {
        return isWayFree(row, col);
    }
    return false;
}

bool King::isChess()
{
    Piece** matBoard = _brd->getBoard();
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            Piece* piece = *(matBoard + i * BOARD_SIZE + j);
            if (piece && piece->getPlayer() != nullptr && piece->getPlayer() != _player)
            {
                if (piece->isLegalMove(_row, _col))
                {
                    return true;
                }
            }
        }
    }
    return false;
}