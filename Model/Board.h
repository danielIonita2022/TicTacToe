#pragma once
#include "IBoard.h"


class Board : public IBoard
{

public:

	Board();
	std::array <Symbol, 9> getBoard() const override;
	void setBoard(const std::array <Symbol, 9>& board) override;
	bool isValidPosition(const int position) const override;
	void placeSymbol(const int position, const Symbol& symbol) override;
	BoardState getBoardState() const override;
	void setBoardState() override;

private:

	BoardState checkBoardState() const override;
	Symbol checkRows() const override;
	Symbol checkColumns() const override;
	Symbol checkDiagonals() const override;

private:

	std::array <Symbol, 9> m_board;
	BoardState m_boardState;

};

