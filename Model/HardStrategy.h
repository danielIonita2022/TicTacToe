#pragma once
#include "IStrategy.h"

class HardStrategy : public IStrategy
{
public:
	
	int GetWinPosition(const Board& board);
	int CanOpponentWin(const Board& board);
	int MakeMove(const Board& board) override;
	
	~HardStrategy() = default;
};