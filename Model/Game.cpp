#include "Game.h"
#include <iostream>

IGamePtr IGame::Produce()
{
	return std::make_shared<Game>();
}

Game::Game()
{
	m_board = IBoard::Produce();
	m_isOver = false;
	m_isDraw = false;
}

IPlayerPtr Game::DecideWinner()
{
	while (!m_isOver)
	{
		MakeMove(m_player1);
		if (!m_isOver)
		{
			MakeMove(m_player2);
		}
		else return m_player1;
	}
	return m_player2;
	
}

void Game::StartGame()
{
	IPlayerPtr winner = DecideWinner();
	for (const auto& listener : m_listeners)
	{
		if(auto listenerPtr = listener.lock())
		{
			listenerPtr->OnGameOver(winner, m_isDraw);
		}
	}
}

void Game::AddListener(const IGameListenerPtr listener)
{
	m_listeners.push_back(listener);
}

void Game::RemoveListener(const IGameListenerPtr listener)
{
	for (auto it = m_listeners.begin(); it != m_listeners.end(); ++it)
	{
		if (auto listenerPtr = it->lock())
		{
			if (listenerPtr == listener)
			{
				m_listeners.erase(it);
				break;
			}
		}
	}
}

IBoardPtr Game::GetBoard() const
{
	return m_board;
}

void Game::MakeMove(const IPlayerPtr player)
{
	auto& listener = m_listeners[0];
	int position = -1;

	if (auto listenerPtr = listener.lock())
	{
		position = listenerPtr->OnPlayerTurn(player);
	}

	while (!m_board->IsValidPosition(position))
	{
		if (auto listenerPtr = listener.lock())
		{
			position = listenerPtr->OnInvalidMove();
		}
	}

	m_board->PlaceSymbol(position, player->GetSymbol());
	if (auto listenerPtr = listener.lock())
	{
		listenerPtr->OnMakeMove();
	}

	m_board->UpdateBoardState();
	if (m_board->GetBoardState() != EBoardState::Ongoing)
	{
		m_isOver = true;
	}
	if (m_board->GetBoardState() == EBoardState::Draw)
	{
		m_isDraw = true;
	}
}

void Game::SetPlayerName(int playerNo, const std::string& name)
{
	if (playerNo == 1)
	{
		m_player1 = IPlayer::Produce(name);
	}
	else if (playerNo == 2)
	{
		m_player2 = IPlayer::Produce(name);
	}
}
