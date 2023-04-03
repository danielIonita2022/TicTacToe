#include "EasyStrategy.h"
#include <random>

int EasyStrategy::MakeMove(const Board& board)
{
	std::random_device rd; 
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(0, 8);
	int random = distr(gen);
	if (board.IsValidPosition(random))
	{
		return random;
	}
	else
	{
		return MakeMove(board);
	}
}
