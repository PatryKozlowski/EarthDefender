#pragma once

#include "SFML/Graphics.hpp"
#include "Player.hpp"
#include "Affect.hpp"
#include "ui/Ufo.hpp"
#include "ui/EnemyHealthHUD.hpp"
#include "ui/Explosion.hpp"

class Boss
{
public:
	Boss(Player& player, Affect& affect);
	void SpawnBoss(sf::RenderWindow& window);
	void HandleClick(const sf::Event& event);
	void Update(float deltaTime);
	void ResetBoss();
	inline bool GetIsSpawned() const { return m_IsSpawned; };
	inline bool HasExploded() const { return m_HasExploded; };
	inline bool ShouldAppear() const { return m_ShouldAppear; }
	inline unsigned int GetHealth() const { return m_Stats.helath; };
	inline unsigned int GetScore() const { return m_Stats.score; };
	inline bool SetIsSpawned(bool isSpawned) { return m_IsSpawned = isSpawned; };
	inline unsigned int SetHealth(unsigned int health) { return m_Stats.helath = health; };
	inline sf::FloatRect GetBossBound() const { return m_Ufo.GetObjectBound(); };
	inline void SetHasExploded(bool hasExploded) { m_HasExploded = hasExploded; };
	inline void SetShouldAppear(bool shouldAppear) { m_ShouldAppear = shouldAppear; };


private:
	Ufo m_Ufo;
	Player& m_Player;
	Affect& m_Affect;
	bool m_IsSpawned;
	bool m_HasExploded;
	bool m_ShouldAppear;
	std::unique_ptr<EnemyHealthHUD> m_HealthHUD;
	std::unique_ptr<Explosion> m_Explosion;

	struct Stats
	{
		unsigned int helath;
		unsigned int score;
	} m_Stats;

	void Hit(unsigned int damage);
	void UpdateHealthText(const unsigned int& health);
	void Explode();
};