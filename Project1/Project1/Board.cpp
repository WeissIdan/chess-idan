#include "Board.h"
#include <iostream>
#include <cstring>
#include "Piece.h"
#include "Player.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "NullPiece.h"

Board::Board(Player* p1, Player* p2)
    : _lastSrcRow(-1), _lastSrcCol(-1), _lastDstRow(-1), _lastDstCol(-1), _lastPiece(nullptr)
{
    // Initialize the board with nullptrs or pieces as needed
    for (int i = 0; i < BOARD_SIZE; ++i)
        for (int j = 0; j < BOARD_SIZE; ++j)
            _brd[i][j] = nullptr;
    // You may want to initialize pieces here if needed
	//initialize a normal chess board:
    // Pawns
    for (int j = 0; j < BOARD_SIZE; ++j) {
        _brd[1][j] = new Pawn(p2, 1, j, this);
        _brd[6][j] = new Pawn(p1, 6, j, this);
    }
    // Rooks
    _brd[0][0] = new Rook(p2, 0, 0, this);
    _brd[0][7] = new Rook(p2, 0, 7, this);
    _brd[7][0] = new Rook(p1, 7, 0, this);
    _brd[7][7] = new Rook(p1, 7, 7, this);
    // Knights
    _brd[0][1] = new Knight(p2, 0, 1, this);
    _brd[0][6] = new Knight(p2, 0, 6, this);
    _brd[7][1] = new Knight(p1, 7, 1, this);
    _brd[7][6] = new Knight(p1, 7, 6, this);
    // Bishops
    _brd[0][2] = new Bishop(p2, 0, 2, this);
    _brd[0][5] = new Bishop(p2, 0, 5, this);
    _brd[7][2] = new Bishop(p1, 7, 2, this);
    _brd[7][5] = new Bishop(p1, 7, 5, this);
    // Queens
    _brd[0][3] = new Queen(p2, 0, 3, this);
    _brd[7][3] = new Queen(p1, 7, 3, this);
    // Kings
    _brd[0][4] = new King(p2, 0, 4, this);
	p2->setKing((King*)_brd[0][4]);
	_brd[7][4] = new King(p1, 7, 4, this);
    p1->setKing((King*)_brd[7][4]);
}

Board::~Board()
{
    for (int i = 0; i < BOARD_SIZE; ++i)
        for (int j = 0; j < BOARD_SIZE; ++j)
            delete _brd[i][j];
}

void Board::print() const
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            if (_brd[i][j])
                std::cout << _brd[i][j]->getSign() << ' ';
            else
                std::cout << ". ";
        }
        std::cout << std::endl;
    }
}

void Board::getString(char res[]) const
{
    int idx = 0;
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            if (_brd[i][j])
                res[idx++] = _brd[i][j]->getSign();
            else
                res[idx++] = '.';
        }
    }
    res[idx] = '\0';
}

bool Board::isPieceOfPlayer(int row, int col, Player* pl) const
{
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE)
        return false;
    if (_brd[row][col] && _brd[row][col]->getPlayer() == pl)
        return true;
    return false;
}

bool Board::tryMove(int srcRow, int srcCol, int dstRow, int dstCol) const
{
    if (srcRow < 0 || srcRow >= BOARD_SIZE || srcCol < 0 || srcCol >= BOARD_SIZE)
        return false;
    if (dstRow < 0 || dstRow >= BOARD_SIZE || dstCol < 0 || dstCol >= BOARD_SIZE)
        return false;
    Piece* piece = _brd[srcRow][srcCol];
    if (!piece)
        return false;
    if (!piece->isLegalMove(dstRow, dstCol))
        return false;
    return true;
}

Piece** Board::getBoard() const
{
    // Return pointer to the first element of the board array
    return (Piece**)_brd;
}

void Board::Move(int srcRow, int srcCol, int dstRow, int dstCol)
{
    if (!tryMove(srcRow, srcCol, dstRow, dstCol))
        return;
    _lastSrcRow = srcRow;
    _lastSrcCol = srcCol;
    _lastDstRow = dstRow;
    _lastDstCol = dstCol;
    _lastPiece = _brd[dstRow][dstCol];

    _brd[dstRow][dstCol] = _brd[srcRow][srcCol];
    _brd[srcRow][srcCol] = nullptr;
    if (_brd[dstRow][dstCol])
        _brd[dstRow][dstCol]->setPosition(dstRow, dstCol);
}

void Board::undoLastMove()
{
    if (_lastSrcRow == -1 || _lastSrcCol == -1 || _lastDstRow == -1 || _lastDstCol == -1)
        return;
    _brd[_lastSrcRow][_lastSrcCol] = _brd[_lastDstRow][_lastDstCol];
    if (_brd[_lastSrcRow][_lastSrcCol])
        _brd[_lastSrcRow][_lastSrcCol]->setPosition(_lastSrcRow, _lastSrcCol);
    _brd[_lastDstRow][_lastDstCol] = _lastPiece;
    _lastSrcRow = _lastSrcCol = _lastDstRow = _lastDstCol = -1;
    _lastPiece = nullptr;
}
