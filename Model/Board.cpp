#include "Board.h"

IBoardPtr IBoard::Produce()
{
	return std::make_shared<Board>();
}

Board::Board() : m_boardState(BoardState::Ongoing)
{
	std::fill_n(m_board.begin(), m_board.size(), Symbol::None);
}

std::array <Symbol, 9> Board::getBoard() const
{
	return m_board;
}

void Board::setBoard(const std::array<Symbol, 9>& board)
{
	m_board = board;
}

bool Board::isValidPosition(const int position) const
{
	if (position < 0 || position > 8)
		return false;
	if (m_board[position] != Symbol::None)
		return false;
	return true;
}

void Board::placeSymbol(const int position, const Symbol& symbol)
{
	m_board[position] = symbol;
}

BoardState Board::getBoardState() const
{
	return m_boardState;
}

void Board::setBoardState()
{
	m_boardState = checkBoardState();
}

BoardState Board::checkBoardState() const
{
	Symbol row = checkRows();
	if (row != Symbol::None)
	{
		return symbolToState(row);
	}
	Symbol column = checkColumns();
	if (column != Symbol::None)
	{
		return symbolToState(column);
	}
	Symbol diagonal = checkDiagonals();
	if (diagonal != Symbol::None)
	{
		return symbolToState(diagonal);
	}

	for (int i = 0; i < 9; ++i)
	{
		if (m_board[i] == Symbol::None)
			return BoardState::Ongoing;
	}
	return BoardState::Draw;
}

Symbol Board::checkRows() const
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

Symbol Board::checkColumns() const
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

Symbol Board::checkDiagonals() const
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
