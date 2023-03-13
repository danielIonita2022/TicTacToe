#include "Board.h"

IBoardPtr IBoard::Produce()
{
	return std::make_shared<Board>();
}

Board::Board() : m_boardState(BoardState::Ongoing)
{
	std::fill_n(m_board.begin(), m_board.size(), Symbol::None);
}

std::array <Symbol, 9> Board::GetMatrixBoard() const
{
	return m_board;
}

void Board::SetMatrixBoard(const std::array<Symbol, 9>& board)
{
	m_board = board;
}

bool Board::IsValidPosition(const int position) const
{
	if (position < 0 || position > 8)
		return false;
	if (m_board[position] != Symbol::None)
		return false;
	return true;
}

void Board::PlaceSymbol(const int position, const Symbol& symbol)
{
	m_board[position] = symbol;
}

BoardState Board::GetBoardState() const
{
	return m_boardState;
}

void Board::SetBoardState()
{
	m_boardState = CheckBoardState();
}

BoardState Board::CheckBoardState() const
{
	Symbol row = CheckRows();
	if (row != Symbol::None)
	{
		return SymbolToState(row);
	}
	Symbol column = CheckColumns();
	if (column != Symbol::None)
	{
		return SymbolToState(column);
	}
	Symbol diagonal = CheckDiagonals();
	if (diagonal != Symbol::None)
	{
		return SymbolToState(diagonal);
	}

	for (int i = 0; i < 9; ++i)
	{
		if (m_board[i] == Symbol::None)
			return BoardState::Ongoing;
	}
	return BoardState::Draw;
}

Symbol Board::CheckRows() const
{
	for (int i = 0; i < 3; ++i)
	{
		if (m_board[i * 3] != Symbol::None)
		{
			if ((m_board[i * 3] == m_board[i * 3 + 1]) && (m_board[i * 3 + 1] == m_board[i * 3 + 2]))
				return m_board[i * 3];
		}
	}
	return Symbol::None;
}

Symbol Board::CheckColumns() const
{
	for (int i = 0; i < 3; ++i)
	{
		if (m_board[i] != Symbol::None)
		{
			if ((m_board[i] == m_board[i + 3]) && (m_board[i + 3] == m_board[i + 6]))
				return m_board[i];
		}
	}
	return Symbol::None;
}

Symbol Board::CheckDiagonals() const
{
	if (m_board[0] != Symbol::None)
	{
		if ((m_board[0] == m_board[4]) && (m_board[4] == m_board[8]))
			return m_board[0];
	}
	if (m_board[2] != Symbol::None)
	{
		if ((m_board[2] == m_board[4]) && (m_board[4] == m_board[6]))
			return m_board[2];
	}
	return Symbol::None;
}
