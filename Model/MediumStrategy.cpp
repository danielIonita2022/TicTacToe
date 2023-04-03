#include "MediumStrategy.h"
#include <random>

MediumStrategy::MediumStrategy():
	m_moveNumber(0)
{
}

void MediumStrategy::NextMove()
{
	m_moveNumber++;
}

int MediumStrategy::MakeBadMove(const Board& board)
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, 8);
	int random = distr(gen);
	if (board.IsValidPosition(random))
	{
		return random;
	}
	else
	{
		return MakeBadMove(board);
	}
}

int MediumStrategy::GetWinPosition(const Board& board)
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

int MediumStrategy::CanOpponentWin(const Board& board)
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

int MediumStrategy::MakeGoodMove(const Board& board)
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

int MediumStrategy::MakeMove(const Board& board)
{
	if (m_moveNumber % 2 == 0)
	{
		return MakeBadMove(board);
	}
	else
	{
		return MakeGoodMove(board);
	}
}
