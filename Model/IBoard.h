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
	virtual std::array <Symbol, 9> getBoard() const = 0;
	virtual void setBoard(const std::array <Symbol, 9>& board) = 0;
	virtual bool isValidPosition(const int position) const = 0;
	virtual void placeSymbol(const int position, const Symbol& symbol) = 0;
	virtual BoardState getBoardState() const = 0;
	virtual void setBoardState() = 0;
	virtual ~IBoard() = default;

protected:
	 
	virtual BoardState checkBoardState() const = 0;
	virtual Symbol checkRows() const = 0;
	virtual Symbol checkColumns() const = 0;
	virtual Symbol checkDiagonals() const = 0;

};
