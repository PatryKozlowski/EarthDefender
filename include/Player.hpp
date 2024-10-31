#pragma once

#include "ui/Earth.hpp"
#include "ui/ShieldHUD.hpp"
#include "GameConfig.hpp"
#include "Affect.hpp"

class Player
{
public:
	Player(Affect& affect);

	inline unsigned int GetHealth() const { return m_Stats.health; }
	inline unsigned int GetScore() const { return m_Stats.score; }
	inline void SetHealth(unsigned int health) { m_Stats.health = health; }
	inline void SetScore(unsigned int score) { m_Stats.score = score; }
	void DecreaseHealth(unsigned int damage);
	void IncrementScore(unsigned int score);
	unsigned int GetDamage() const;

private:
	Affect& m_Affect;

	struct Stats
	{
		unsigned int health;
		unsigned int score;
		unsigned int damage;
	} m_Stats;
};


