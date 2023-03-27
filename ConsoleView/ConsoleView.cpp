#include "ConsoleView.h"
#include <iostream>

ConsoleView::ConsoleView(IGamePtr game) : m_game(game)
{
	std::cout << "Welcome to Tic Tac Toe!\n";
	std::cout << "Enter your name first player: ";
	std::string name;
	std::cin >> name;
	m_game->CreatePlayer(1, name);
	std::cout << "Enter your name second player: ";
	std::cin >> name;
	m_game->CreatePlayer(2, name);
}

void ConsoleView::StartGame()
{
	IPlayerPtr player1 = m_game->GetPlayer1();
	IPlayerPtr player2 = m_game->GetPlayer2();
	int position = -1;

	while (m_game->GetGameState() == EGameState::Ongoing)
	{
		std::cout << "It's your turn, " << player1->GetName() << "!\n";
		PlayerTurn(player1);
		
		if (m_game->GetGameState() == EGameState::Ongoing)
		{
			std::cout << "It's your turn, " << player2->GetName() << "!\n";
			PlayerTurn(player2);
		}
	}
}

void ConsoleView::PlayerTurn(IPlayerPtr& player)
{
	int position = -1;
	position = ChoosePosition(player);
	while (!m_game->HasMadeMove(player, position))
	{
		std::cout << "Invalid move! Try again.\n";
		position = ChoosePosition(player);
	}
}

int ConsoleView::ChoosePosition(IPlayerPtr& player)
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
	auto gameBoard = m_game->GetBoard().GetMatrixBoard();
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

void ConsoleView::OnGameOver(IPlayerPtr& player)
{
	if (m_game->GetGameState() == EGameState::Draw)
	{
		std::cout << "It's a draw!\n";
	}
	else
	{
		std::cout << "Congratulations, " << player->GetName() << "! You won!\n";
	}
}

