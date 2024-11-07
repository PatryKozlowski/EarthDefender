#include "Player.hpp"
#include "GameConfig.hpp"

Player::Player(Affect& affect)
	: m_Stats{ GameConfig::INIT_HEALTH, GameConfig::INIT_SCORE, GameConfig::INIT_PLAYER_DMG },
	m_Affect{ affect }
{
}

void Player::DecreaseHealth(unsigned int damage)
{
	if (m_Affect.IsInvincible())
	{
		return;
	}

	if (damage >= GetHealth())
	{
		SetHealth(0);
	}
	else
	{
		SetHealth(GetHealth() - damage);
	}
}

void Player::IncrementScore(unsigned int score)
{
	if (m_Affect.IsDoubleScore())
	{
		score *= 2;
	}

	SetScore(GetScore() + score);
}

unsigned int Player::GetDamage() const
{
	if (m_Affect.IsDoubleDamage())
	{
		return m_Stats.damage * 2;
	}

	return m_Stats.damage;
}
