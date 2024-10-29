#include "Player.hpp"
#include "GameConfig.hpp"

Player::Player()
	: m_Earth{ std::make_unique<Earth>() },
	m_Health{ GameConfig::INIT_HEALTH },
	m_Score{ GameConfig::INIT_SCORE }
{
}

void Player::SpawnPlayer(sf::RenderWindow& window)
{
	m_Earth->Draw(window);
}
