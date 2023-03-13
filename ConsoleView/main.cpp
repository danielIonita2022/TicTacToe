#include "ConsoleView.h"

int main()
{
	IGamePtr game = IGame::Produce();
	ConsoleView consoleView(game);
	std::shared_ptr<ConsoleView> consoleViewPtr = std::make_shared<ConsoleView>(consoleView);
	game->AddListener(consoleViewPtr);
	game->StartGame();
	return 0;
}