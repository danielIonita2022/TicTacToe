#pragma once
#include <array>
#include "IPlayer.h"


class Board
{

public:

	Board();
	Board(const Board& other);

	std::array <ESymbol, 9> GetMatrixBoard() const;
	void SetMatrixBoard(const std::array <ESymbol, 9>& board);

	bool IsValidPosition(const int position) const;
	void PlaceSymbol(const int position, const ESymbol& symbol);

	ESymbol CheckRows() const;
	ESymbol CheckColumns() const;
	ESymbol CheckDiagonals() const;

private:

	std::array <ESymbol, 9> m_board;

};

