#include "HardStrategy.h"

int HardStrategy::GetWinPosition(const Board& board)
{
	Board tempBoard = board;
	for (int i = 0; i < board.GetMatrixBoard().size(); i++)
	{
		if (tempBoard.IsValidPosition(i))
		{
			tempBoard.PlaceSymbol(i, ESymbol::O);
			if (tempBoard.CheckColumns() != ESymbol::None)
			{
				return i;
			}
			if (tempBoard.CheckRows() != ESymbol::None)
			{
				return i;
			}
			if (tempBoard.CheckDiagonals() != ESymbol::None)
			{
				return i;
			}
		}
		tempBoard = board;
	}
	return -1;
}

int HardStrategy::CanOpponentWin(const Board& board)
{
	Board tempBoard = board;
	for (int i = 0; i < board.GetMatrixBoard().size(); i++)
	{
		if (tempBoard.IsValidPosition(i))
		{
			tempBoard.PlaceSymbol(i, ESymbol::X);
			if (tempBoard.CheckColumns() != ESymbol::None)
			{
				return i;
			}
			if (tempBoard.CheckRows() != ESymbol::None)
			{
				return i;
			}
			if (tempBoard.CheckDiagonals() != ESymbol::None)
			{
				return i;
			}
		}
		tempBoard = board;
	}
	return -1;
}

int HardStrategy::MakeMove(const Board& board)
{
	if (GetWinPosition(board) != -1)
	{
		return GetWinPosition(board);
	}
	if (CanOpponentWin(board) != -1)
	{
		return CanOpponentWin(board);
	}
	if (board.IsValidPosition(4))
	{
		return 4;
	}
	if (board.IsValidPosition(0))
	{
		return 0;
	}
	if (board.IsValidPosition(2))
	{
		return 2;
	}
	if (board.IsValidPosition(6))
	{
		return 6;
	}
	if (board.IsValidPosition(8))
	{
		return 8;
	}
	for (int i = 0; i < board.GetMatrixBoard().size(); i++)
	{
		if (board.IsValidPosition(i))
		{
			return i;
		}
	}
}
