#include "ConsoleView.h"

int main()
{
	IGamePtr game = IGame::Produce();
	IGameListenerPtr consoleViewPtr = std::make_shared<ConsoleView>(game);
	game->AddListener(consoleViewPtr);
	game->StartGame();
	game->RemoveListener(consoleViewPtr);

	return 0;
}