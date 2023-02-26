#pragma once
#include <array>
#include "BoardState.h"

class Board
{
private:

	std::array <Symbol, 9> m_board;
	BoardState m_boardState;

public:

	Board();
	std::array <Symbol, 9> getBoard() const;
	void setBoard(const std::array <Symbol, 9>& board);
	bool isValidPosition(const int position);
	void placeSymbol(const int position, const Symbol& symbol);
	BoardState getBoardState() const;
	void setBoardState();
	BoardState checkBoardState();
	Symbol checkRows();
	Symbol checkColumns();
	Symbol checkDiagonals();
};

