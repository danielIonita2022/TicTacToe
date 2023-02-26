#include "ConsoleGame.h"

ConsoleGame::ConsoleGame()
{
	std::cout << "Welcome to Tic Tac Toe!\n";
	m_firstPlayer = enterPlayer(true);
	m_secondPlayer = enterPlayer(false);
	beginGame();
}

Player ConsoleGame::enterPlayer(const bool firstPlayer)
{
	std::cout << "Enter your name ";
	if (firstPlayer)
	{
		std::cout << "first player: ";
	}
	else
	{
		std::cout << "second player: ";
	}
	std::string name;
	std::cin >> name;

	Player player(name);
	return player;
}

void ConsoleGame::beginGame()
{
	printBoard();

	while (m_gameBoard.getBoardState() == BoardState::Ongoing)
	{
		printPlayerTurn(m_firstPlayer);
		printBoard();
		m_gameBoard.setBoardState();
		if (m_gameBoard.getBoardState() == BoardState::Ongoing)
		{
			printPlayerTurn(m_secondPlayer);
			printBoard();
			m_gameBoard.setBoardState();
		}
	}

	endGame();
}

void ConsoleGame::endGame()
{
	BoardState boardState = m_gameBoard.getBoardState();
	if (boardState == BoardState::XWon)
	{
		printWinner(m_firstPlayer);
	}
	else if (boardState == BoardState::OWon)
	{
		printWinner(m_secondPlayer);
	}
	else
	{
		std::cout << "Draw!\n";
	}
}

void ConsoleGame::printPlayerTurn(const Player& player)
{
	std::cout << "It's your turn, " << player.getName() << "! Choose an empty space\n";
	int position;
	std::cin >> position;
	while (!m_gameBoard.isValidPosition(position))
	{
		std::cout << "Invalid position! Try again\n";
		std::cin >> position;
	}
	m_gameBoard.placeSymbol(position, player.getSymbol());
	std::cout << "\n";
}

void ConsoleGame::printWinner(const Player& player)
{
	std::cout << "Congratulations, " << player.getName() << "! You won!\n";
}

void ConsoleGame::printBoard()
{
	int newlineCount = 0;
	for (const auto& square : m_gameBoard.getBoard())
	{
		std::cout << " |";
		++newlineCount;
		std::cout << symbolToStr(square);
		if (newlineCount % 3 == 0)
			std::cout << " |\n";
	}
	std::cout << "\n";
}

ConsoleGame::~ConsoleGame()
{
}