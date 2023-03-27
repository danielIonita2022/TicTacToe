#include "Game.h"
#include <iostream>

IGamePtr IGame::Produce()
{
	return std::make_shared<Game>();
}

Game::Game()
{
	m_gameState = EGameState::Ongoing;
}

void Game::AddListener(IGameListener* listener)
{
	m_listeners.push_back(listener);
}

void Game::RemoveListener(IGameListener* listener)
{
	for (auto it = m_listeners.begin(); it != m_listeners.end(); ++it)
	{
		if (*it == listener)
		{
			m_listeners.erase(it);
			break;
		}
	}
}

Board Game::GetBoard()
{
	return m_board;
}

void Game::UpdateGameState()
{
	ESymbol row = m_board.CheckRows();
	if (row != ESymbol::None)
	{
		m_gameState = SymbolToState(row);
		return;
	}
	ESymbol column = m_board.CheckColumns();
	if (column != ESymbol::None)
	{
		m_gameState = SymbolToState(column);
		return;
	}
	ESymbol diagonal = m_board.CheckDiagonals();
	if (diagonal != ESymbol::None)
	{
		m_gameState = SymbolToState(diagonal);
		return;
	}
	
	for (int i = 0; i < 9; ++i)
	{
		if (m_board.GetMatrixBoard()[i] == ESymbol::None)
		{
			m_gameState = EGameState::Ongoing;
			return;
		}
	}
	m_gameState = EGameState::Draw;

}

EGameState Game::GetGameState() const
{
	return m_gameState;
}

void Game::CreatePlayer(int playerNo, const std::string& name)
{
	if (playerNo == 1)
	{
		m_player1 = std::make_shared<Player>(name);
	}
	else if (playerNo == 2)
	{
		m_player2 = std::make_shared<Player>(name);
	}
}
IPlayerPtr Game::GetPlayer1() const
{
	return m_player1;
}

IPlayerPtr Game::GetPlayer2() const
{
	return m_player2;
}

bool Game::HasMadeMove(IPlayerPtr& player, int position)
{
	auto listener = m_listeners[0];

	if (!m_board.IsValidPosition(position))
	{
		return false;
	}

	m_board.PlaceSymbol(position, player->GetSymbol());

	listener->OnMakeMove();

	UpdateGameState();
	if (m_gameState != EGameState::Ongoing)
	{
		listener->OnGameOver(player);
	}
	return true;
}
