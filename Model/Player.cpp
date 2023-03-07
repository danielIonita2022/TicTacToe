#include "Player.h"

bool Player::m_isFirstPlayer = true;

IPlayerPtr IPlayer::Produce(const std::string& playerName)
{
	return std::make_shared<Player>(playerName);
}

Player::Player() : m_playerSymbol(Symbol::None)
{
}

Player::Player(const std::string& playerName) : m_playerName(playerName)
{
	if (m_isFirstPlayer)
	{
		m_playerSymbol = Symbol::X;
		m_isFirstPlayer = false;
	}
	else
	{
		m_playerSymbol = Symbol::O;
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

std::string Player::getName() const
{
	return m_playerName;
}

Symbol Player::getSymbol() const
{
	return m_playerSymbol;
}

void Player::setName(const std::string& name)
{
	m_playerName = name;
}
Player::~Player()
{
}