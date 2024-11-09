#pragma once

#include "Object.hpp"
#include "ui/Text.hpp"
#include "ui/EnemyHealthHUD.hpp"
#include "ui/Explosion.hpp"
#include "Affect.hpp"
#include "Boss.hpp"
#include "GameConfig.hpp"

class Meteor : public Object
{
public:
	Meteor(Affect& affect, Boss& boss, const std::string& pathNmae, float speed, unsigned int health, unsigned int damage, unsigned int score);

	void Update(float deltaTime) override;
	void Draw(sf::RenderWindow& window) const override;
	void Hit(unsigned int damage);
	void UpdateHealthText(const unsigned int& health);
	void Explode(bool isMeteorExplosionByPlayer);
	bool IsDestroyed() const;
	inline unsigned int GetHealth() const { return m_Stats.health; };
	unsigned int GetDamage();
	inline unsigned int GetScore() const { return m_Stats.score; };
	inline float GetSpeed() const { return m_Stats.speed; };
	inline bool HasExploded() const { return m_HasExploded; };
	inline bool GetDestroyedFlag() const { return m_Destroyed; };
	inline void SetHasExploded(bool hasExploded) { m_HasExploded = hasExploded; };
	inline void SetDestroyed(bool destroyed) { m_Destroyed = destroyed; };
	inline void SetHealth(unsigned int health) { m_Stats.health = health; };

private:
	struct Stats
	{
		float speed;
		unsigned int health;
		unsigned int damage;
		unsigned int score;
	} m_Stats;

	Affect& m_Affect;
	Boss& m_Boss;

	bool m_Destroyed;
	bool m_HasExploded;
	std::unique_ptr<EnemyHealthHUD> m_HealthHUD;
	std::unique_ptr<Explosion> m_Explosion;

	void Move(float deltaTime);
	void SetRandomPosition();
};
