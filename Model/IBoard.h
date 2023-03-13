#pragma once
#include <memory>
#include <string>
#include <array>
#include "Symbol.h"
#include "IPlayer.h"
#include "BoardState.h"

using IBoardPtr = std::shared_ptr<class IBoard>;

class IBoard
{
public:

	static IBoardPtr Produce();
	virtual std::array <Symbol, 9> GetMatrixBoard() const = 0;
	virtual void SetMatrixBoard(const std::array <Symbol, 9>& board) = 0;
	virtual bool IsValidPosition(const int position) const = 0;
	virtual void PlaceSymbol(const int position, const Symbol& symbol) = 0;
	virtual BoardState GetBoardState() const = 0;
	virtual void SetBoardState() = 0;
	virtual ~IBoard() = default;

protected:
	 
	virtual BoardState CheckBoardState() const = 0;
	virtual Symbol CheckRows() const = 0;
	virtual Symbol CheckColumns() const = 0;
	virtual Symbol CheckDiagonals() const = 0;

};
