#include "ConsoleView.h"
#include <iostream>

ConsoleView::ConsoleView(IGamePtr game) : m_game(game)
{
	std::cout << "Welcome to Tic Tac Toe!\n";
	std::cout << "Enter your name first player: ";
	std::string name;
	std::cin >> name;
	m_game->SetPlayerName(1, name);
	std::cout << "Enter your name second player: ";
	std::cin >> name;
	m_game->SetPlayerName(2, name);
}

int ConsoleView::OnPlayerTurn(IPlayerPtr player)
{
	std::cout << "It's your turn, " << player->GetName() << "!\n";
	std::cout << "Enter the position you want to place your symbol\n";
	int row, col;
	std::cout << "Row: ";
	std::cin >> row;
	std::cout << "Column: ";
	std::cin >> col;
	std::cout << "\n";
	int position = (row - 1) * 3 + col - 1;
	return position;
}

int ConsoleView::OnInvalidMove()
{
	std::cout << "Invalid move! Try again.\n";
	int row, col;
	std::cout << "Row: ";
	std::cin >> row;
	std::cout << "Column: ";
	std::cin >> col;
	std::cout << "\n";
	int position = (row - 1) * 3 + col - 1;
	return position;
}

void ConsoleView::OnMakeMove()
{
	int newlineCount = 0;
	auto gameBoard = m_game->GetBoard()->GetMatrixBoard();
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

void ConsoleView::OnGameOver(IPlayerPtr player, bool isDraw)
{
	if (isDraw)
	{
		std::cout << "It's a draw!\n";
	}
	else
	{
		std::cout << "Congratulations, " << player->GetName() << "! You won!\n";
	}
}

