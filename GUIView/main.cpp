#include "GUIStartGame.h"
#include "IGame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	IGamePtr game = IGame::Produce();
	GUIStartGame* startGame = new GUIStartGame(game);
	startGame->show();
    return a.exec();
}
