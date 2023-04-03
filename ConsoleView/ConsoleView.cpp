#include "ConsoleView.h"
#include <iostream>

ConsoleView::ConsoleView(IGamePtr game) : m_game(game), m_isComputerPlaying(false)
{
	std::cout << "Welcome to Tic Tac Toe!\n";
	std::cout << "Do you want to play with the computer or with a friend?\n";
	std::cout << "1. Computer\n";
	std::cout << "2. Friend\n";
	int choice = 0;
	std::cin >> choice;
	if (choice == 1)
	{
		std::cout << "What difficulty do you want to play on?\n";
		std::cout << "1. Easy\n";
		std::cout << "2. Medium\n";
		std::cout << "3. Hard\n";
		int difficulty = 0;
		std::cin >> difficulty;
		if (difficulty == 1)
		{
			m_game->SetStrategy(EGameDifficulty::Easy);
		}
		else if (difficulty == 2)
		{
			m_game->SetStrategy(EGameDifficulty::Medium);
		}
		else if (difficulty == 3)
		{
			m_game->SetStrategy(EGameDifficulty::Hard);
		}
		std::cout << "Enter your name: ";
		std::string name;
		std::cin >> name;
		m_game->CreatePlayer(1, name);
		m_game->CreatePlayer(2, "Computer");
		m_isComputerPlaying = true;
	}
	else if (choice == 2)
	{
		std::cout << "Enter your name first player: ";
		std::string name;
		std::cin >> name;
		m_game->CreatePlayer(1, name);
		std::cout << "Enter your name second player: ";
		std::cin >> name;
		m_game->CreatePlayer(2, name);
		m_isComputerPlaying = false;
	}
	else
	{
		std::cout << "Wrong choice!\n";
	}
}

void ConsoleView::RunGame()
{
	while (m_game->GetGameState() == EGameState::Ongoing)
	{
		auto currentPlayer = m_game->GetCurrentPlayer();
		
		if (currentPlayer->GetName() != "Computer")
		{
			std::cout << "It's your turn, " << currentPlayer->GetName() << "!\n";
			int position = ChoosePosition(currentPlayer);
			while (!m_game->MakeMove(position))
			{
				std::cout << "Invalid move! Try again.\n";
				position = ChoosePosition(currentPlayer);
			}
		}
		else
		{
			m_game->MakeComputerMove();
		}
	}
}

int ConsoleView::ChoosePosition(IPlayerPtr player)
{
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

void ConsoleView::OnMakeMove()
{
	int newlineCount = 0;
	auto gameBoard = m_game->GetBoardArray();
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
	if (player == nullptr)
	{
		std::cout << "It's a draw!\n";
	}
	else
	{
		std::cout << "Congratulations, " << player->GetName() << "! You won!\n";
	}
}

