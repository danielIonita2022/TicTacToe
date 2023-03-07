#include "IPlayer.h"
#include "IBoard.h"
#include "IGame.h"
#include <iostream>

int main()
{
	auto game = IGame::Produce(EGameType::Impl1);
	game->startScreen();
	return 0;
}