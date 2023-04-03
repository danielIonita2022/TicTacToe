#pragma once
#include "IStrategy.h"

class MediumStrategy : public IStrategy
{
public:
	MediumStrategy();
	
	void NextMove();
	int MakeBadMove(const Board& board);
	int GetWinPosition(const Board& board);
	int MakeGoodMove(const Board& board);
	int CanOpponentWin(const Board& board);
	
	int MakeMove(const Board& board) override;
	
	~MediumStrategy() = default;
	
private:
	int m_moveNumber;
};