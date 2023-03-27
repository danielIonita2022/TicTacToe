#include "GUIStartGame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	GUIStartGame* startGame = new GUIStartGame();
	startGame->show();
    return a.exec();
}
