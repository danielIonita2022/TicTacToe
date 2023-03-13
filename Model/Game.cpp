#include "Game.h"
#include <iostream>

IGamePtr IGame::Produce()
{
	return std::make_shared<Game>();
}

Game::Game()
{
	m_board = IBoard::Produce();
}

void Game::StartGame()
{
	auto listener = m_listeners[0];
	if (auto listenerPtr = listener.lock())
	{
		std::string player1 = listenerPtr->OnEnterPlayer(true);
		std::string player2 = listenerPtr->OnEnterPlayer(false);
		m_player1 = IPlayer::Produce(player1);
		m_player2 = IPlayer::Produce(player2);
		m_isOver = false;
		EndGame();
	}
}

IPlayerPtr Game::BeginGameLoop()
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

void Game::EndGame()
{
	IPlayerPtr winner = BeginGameLoop();
	for (const auto& listener : m_listeners)
	{
		if(auto listenerPtr = listener.lock())
		{
			listenerPtr->OnGameOver(winner);
		}
	}
}

void Game::AddListener(IGameListenerPtr listener)
{
	m_listeners.push_back(listener);
}

void Game::RemoveListener(IGameListenerPtr listener)
{

}

IBoardPtr Game::GetBoard() const
{
	return m_board;
}

void Game::MakeMove(const IPlayerPtr player)
{
	auto listener = m_listeners[0];
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
		listenerPtr->OnMakeMove(m_board);
	}
	m_board->SetBoardState();
	if (m_board->GetBoardState() != BoardState::Ongoing)
	{
		m_isOver = true;
	}
}
