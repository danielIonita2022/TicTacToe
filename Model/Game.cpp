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
	auto listener = m_listenersRaw[0];
	listener->OnGameOver(winner, m_isDraw);
}

void Game::AddListenerRawPointer(IGameListener* listener)
{
	m_listenersRaw.push_back(listener);
}

void Game::RemoveListenerRawPointer(IGameListener* listener)
{
	for (auto it = m_listenersRaw.begin(); it != m_listenersRaw.end(); ++it)
	{
		if (*it == listener)
		{
			m_listenersRaw.erase(it);
			break;
		}
	}
}

IBoardPtr Game::GetBoard() const
{
	return m_board;
}

void Game::MakeMove(const IPlayerPtr player)
{
	auto listener = m_listenersRaw[0];
	int position = -1;

	position = listener->OnPlayerTurn(player);

	while (!m_board->IsValidPosition(position))
	{
		position = listener->OnInvalidMove();
	}

	m_board->PlaceSymbol(position, player->GetSymbol());
	
	listener->OnMakeMove();

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

void Game::CreatePlayer(int playerNo, const std::string& name)
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
