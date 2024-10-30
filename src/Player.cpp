#include "Player.hpp"
#include "GameConfig.hpp"

Player::Player()
	: m_Earth{ std::make_unique<Earth>() },
	m_Stats{ GameConfig::INIT_HEALTH, GameConfig::INIT_SCORE, GameConfig::INIT_PLAYER_DMG }
{
}

void Player::SpawnPlayer(sf::RenderWindow& window) const
{
	m_Earth->Draw(window);
}

void Player::IncrementScore(unsigned int score)
{
	if (IsDoubleScore())
	{
		score *= 2;
	}

	m_Stats.score += score;
}

unsigned int Player::GetDamage() const
{
	if (IsDoubleDamage())
	{
		return m_Stats.damage * 2;
	}

	return m_Stats.damage;
}
