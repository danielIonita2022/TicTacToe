#pragma once
#include "IBoard.h"


class Board : public IBoard
{

public:

	Board();

	std::array <ESymbol, 9> GetMatrixBoard() const override;
	void SetMatrixBoard(const std::array <ESymbol, 9>& board) override;

	bool IsValidPosition(const int position) const override;
	void PlaceSymbol(const int position, const ESymbol& symbol) override;

	EBoardState GetBoardState() const override;
	void UpdateBoardState() override;

private:

	EBoardState ReturnBoardState() const override;
	ESymbol CheckRows() const override;
	ESymbol CheckColumns() const override;
	ESymbol CheckDiagonals() const override;

private:

	std::array <ESymbol, 9> m_board;
	EBoardState m_boardState;

};

