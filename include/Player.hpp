#pragma once

#include "ui/Earth.hpp"

class Player
{
public:
	Player();

	void SpawnPlayer(sf::RenderWindow& window) const;
	inline unsigned int GetHealth() const { return m_Stats.health; }
	inline unsigned int GetScore() const { return m_Stats.score; }
	inline void SetHealth(unsigned int health) { m_Stats.health = health; }
	inline void SetScore(unsigned int score) { m_Stats.score = score; }
	inline void DecreaseHealth(unsigned int damage) { m_Stats.health -= damage; }
	void IncrementScore(unsigned int score);
	unsigned int GetDamage() const;
	inline Earth& GetPlayerObject() { return *m_Earth; }

	//bufss
	inline void SetDoubleScore(bool isDoubleScore) { m_Buffs.doubleScore = isDoubleScore; }
	inline bool IsDoubleScore() const { return m_Buffs.doubleScore; }

	inline void SetDoubleDamage(bool isDoubleDamage) { m_Buffs.doubleDamage = isDoubleDamage; }
	inline bool IsDoubleDamage() const { return m_Buffs.doubleDamage; }

	inline void SetInvincible() { m_Buffs.invincible = true; }
	inline bool IsInvincible() const { return m_Buffs.invincible; }

private:
	std::unique_ptr<Earth> m_Earth;
	struct Stats
	{
		unsigned int health;
		unsigned int score;
		unsigned int damage;
	} m_Stats;
	struct Buffs
	{
		bool doubleScore = false;
		bool doubleDamage = false;
		bool invincible = false;
	} m_Buffs;
};


