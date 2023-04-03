#pragma once
#include "EGameDifficulty.h"
#include "Board.h"
#include <memory>


using IStrategyPtr = std::shared_ptr<class IStrategy>;

class IStrategy
{
public:
	
	virtual int MakeMove(const Board& board) = 0;
	
	virtual ~IStrategy() = default;
};