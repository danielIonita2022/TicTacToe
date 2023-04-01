#include "ConsoleView.h"

int main()
{
	IGamePtr game = IGame::Produce();
	IGameListener* consoleViewPtr = new ConsoleView(game);
	game->AddListener(consoleViewPtr);
	ConsoleView* consoleView = dynamic_cast<ConsoleView*>(consoleViewPtr);
	consoleView->RunGame();
	game->RemoveListener(consoleViewPtr);
	delete consoleViewPtr;
	return 0;
}