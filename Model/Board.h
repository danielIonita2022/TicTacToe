#pragma once
#include "IBoard.h"


class Board : public IBoard
{

public:

	Board();
	std::array <Symbol, 9> GetMatrixBoard() const override;
	void SetMatrixBoard(const std::array <Symbol, 9>& board) override;
	bool IsValidPosition(const int position) const override;
	void PlaceSymbol(const int position, const Symbol& symbol) override;
	BoardState GetBoardState() const override;
	void SetBoardState() override;

private:

	BoardState CheckBoardState() const override;
	Symbol CheckRows() const override;
	Symbol CheckColumns() const override;
	Symbol CheckDiagonals() const override;

private:

	std::array <Symbol, 9> m_board;
	BoardState m_boardState;

};

