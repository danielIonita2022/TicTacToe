#include "ConsoleView.h"
#include <iostream>

ConsoleView::ConsoleView(IGamePtr game) : m_game(game)
{
}

std::string ConsoleView::OnEnterPlayer(bool isFirstPlayer)
{
	std::cout << "Enter your name ";
	if (isFirstPlayer)
	{
		std::cout << "first player: ";
	}
	else
	{
		std::cout << "second player: ";
	}
	std::string name;
	std::cin >> name;
	return name;
}

int ConsoleView::OnPlayerTurn(IPlayerPtr player)
{
	std::cout << "It's your turn, " << player->GetName() << "!\n";
	std::cout << "Enter the position you want to place your symbol: ";
	int position;
	std::cin >> position;
	return position;
}

int ConsoleView::OnInvalidMove()
{
	std::cout << "Invalid move! Try again.\n";
	int position;
	std::cin >> position;
	return position;
}

void ConsoleView::OnMakeMove(const IBoardPtr board)
{
	int newlineCount = 0;
	auto gameBoard = board->GetMatrixBoard();
	for (const auto& square : gameBoard)
	{
		std::cout << " |";
		++newlineCount;
		std::cout << SymbolToStr(square);
		if (newlineCount % 3 == 0)
			std::cout << " |\n";
	}
	std::cout << "\n";
}

void ConsoleView::OnGameOver(IPlayerPtr player)
{
	std::cout << "Congratulations, " << player->GetName() << "! You won!\n";
}

