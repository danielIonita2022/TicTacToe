#include "Player.h"

bool Player::m_isFirstPlayer = true;

IPlayerPtr IPlayer::Produce(const std::string& playerName)
{
	return std::make_shared<Player>(playerName);
}

Player::Player() : m_playerSymbol(ESymbol::None)
{
}

Player::Player(const std::string& playerName) : m_playerName(playerName)
{
	if (m_isFirstPlayer)
	{
		m_playerSymbol = ESymbol::X;
		m_isFirstPlayer = false;
	}
	else
	{
		m_playerSymbol = ESymbol::O;
		m_isFirstPlayer = true;
	}
}

Player::Player(const Player& player)
{
	m_playerName = player.m_playerName;
	m_playerSymbol = player.m_playerSymbol;
}

Player& Player::operator=(const Player& player)
{
	m_playerName = player.m_playerName;
	m_playerSymbol = player.m_playerSymbol;
	return *this;
}

std::string Player::GetName() const
{
	return m_playerName;
}

ESymbol Player::GetSymbol() const
{
	return m_playerSymbol;
}

void Player::SetName(const std::string& name)
{
	m_playerName = name;
}
Player::~Player()
{
}