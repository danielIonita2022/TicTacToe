#pragma once
#include "IStrategy.h"

class EasyStrategy : public IStrategy
{
public:
	
	int MakeMove(const Board& board) override;
	
	~EasyStrategy() = default;
};