#pragma once
#include <memory>
#include <string>
#include <array>

#include "IPlayer.h"
#include "EBoardState.h"

using IBoardPtr = std::shared_ptr<class IBoard>;

class IBoard
{
public:

	static IBoardPtr Produce();

	virtual std::array <ESymbol, 9> GetMatrixBoard() const = 0;
	virtual void SetMatrixBoard(const std::array <ESymbol, 9>& board) = 0;

	virtual bool IsValidPosition(const int position) const = 0;
	virtual void PlaceSymbol(const int position, const ESymbol& symbol) = 0;

	virtual EBoardState GetBoardState() const = 0;
	virtual void UpdateBoardState() = 0;

	virtual ~IBoard() = default;

protected:
	 
	virtual EBoardState ReturnBoardState() const = 0;
	virtual ESymbol CheckRows() const = 0;
	virtual ESymbol CheckColumns() const = 0;
	virtual ESymbol CheckDiagonals() const = 0;

};
