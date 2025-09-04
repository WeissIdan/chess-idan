#include "Pawn.h"

Pawn::Pawn(Player* player, int row, int col, Board* board)
    : Piece(player, 'P', row, col, board)
{
}

bool Pawn::isLegalMove(int row, int col) const
{
	//normal move
    if(row == _row + (_player->isGoingUp() ? 1 : -1) && col == _col) {
        return isWayFree(row, col);
	}
	//first move - 2 cells
    else if((_player->isGoingUp() && _row == 6) || (!_player->isGoingUp() && _row == 1)) {
        if(row == _row + (_player->isGoingUp() ? 2 : -2) && col == _col) {
            return isWayFree(row, col);
        }
	}
	//capture move
    else if (row == _row + (_player->isGoingUp() ? 1 : -1) && abs(col - _col) == 1) {
        Piece** matBoard = _brd->getBoard();
        Piece* targetPiece = *(matBoard + row * BOARD_SIZE + col);
        if (targetPiece->getPlayer() != nullptr && targetPiece->getPlayer() != _player &&
            targetPiece->getSign() != '#') {
            return true;
        }
    }

    return false;
}