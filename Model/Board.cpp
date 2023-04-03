#include "Board.h"

Board::Board()
{
	std::fill_n(m_board.begin(), m_board.size(), ESymbol::None);
}

Board::Board(const Board& other):
	m_board(other.m_board)
{
}

std::array <ESymbol, 9> Board::GetMatrixBoard() const
{
	return m_board;
}

void Board::SetMatrixBoard(const std::array<ESymbol, 9>& board)
{
	m_board = board;
}

bool Board::IsValidPosition(const int position) const
{
	if (position < 0 || position > 8)
		return false;
	if (m_board[position] != ESymbol::None)
		return false;
	return true;
}

void Board::PlaceSymbol(const int position, const ESymbol& symbol)
{
	m_board[position] = symbol;
}

ESymbol Board::CheckRows() const
{
	for (int i = 0; i < 3; ++i)
	{
		if (m_board[i * 3] != ESymbol::None)
		{
			if ((m_board[i * 3] == m_board[i * 3 + 1]) && (m_board[i * 3 + 1] == m_board[i * 3 + 2]))
				return m_board[i * 3];
		}
	}
	return ESymbol::None;
}

ESymbol Board::CheckColumns() const
{
	for (int i = 0; i < 3; ++i)
	{
		if (m_board[i] != ESymbol::None)
		{
			if ((m_board[i] == m_board[i + 3]) && (m_board[i + 3] == m_board[i + 6]))
				return m_board[i];
		}
	}
	return ESymbol::None;
}

ESymbol Board::CheckDiagonals() const
{
	if (m_board[0] != ESymbol::None)
	{
		if ((m_board[0] == m_board[4]) && (m_board[4] == m_board[8]))
			return m_board[0];
	}
	if (m_board[2] != ESymbol::None)
	{
		if ((m_board[2] == m_board[4]) && (m_board[4] == m_board[6]))
			return m_board[2];
	}
	return ESymbol::None;
}
