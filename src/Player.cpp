#include "Player.hpp"
#include "GameConfig.hpp"

Player::Player()
	: m_Earth{ std::make_unique<Earth>() },
	m_ShieldHUD{ std::make_unique<ShieldHUD>(*m_Earth) },
	m_Stats{ GameConfig::INIT_HEALTH, GameConfig::INIT_SCORE, GameConfig::INIT_PLAYER_DMG }
{
}

void Player::SpawnPlayer(sf::RenderWindow& window) const
{
	m_Earth->Draw(window);

	if (IsInvincible())
	{
		m_ShieldHUD->Draw(window);
	}
}

void Player::DecreaseHealth(unsigned int damage)
{
	if (IsInvincible())
	{
		return;
	}

	m_Stats.health -= damage;
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

BuffTypeID Player::GetActiveBuff() const
{
	if (IsDoubleScore())
	{
		return BuffTypeID::DOUBLE_SCORE;
	}
	else if (IsDoubleDamage())
	{
		return BuffTypeID::DOUBLE_DAMAGE;
	}
	else if (IsInvincible())
	{
		return BuffTypeID::INVINCIBILITY;
	}

	return BuffTypeID::NONE;
}
