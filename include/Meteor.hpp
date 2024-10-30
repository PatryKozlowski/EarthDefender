#pragma once

#include "Object.hpp"
#include "ui/Text.hpp"
#include "ui/MeteorHealthHUD.hpp"
#include "ui/Explosion.hpp"

class Meteor : public Object
{
public:
	Meteor(const std::string& pathNmae, float speed, unsigned int health, unsigned int damage, unsigned int score);

	void Update(float deltaTime) override;
	void Draw(sf::RenderWindow& window) const override;
	void Destroy();
	void Hit(unsigned int damage);
	void UpdateHealthText(const unsigned int& health);
	void Explode(bool isMeteorExplosionByPlayer);
	unsigned int GetHealth() const;
	unsigned int GetDamage() const;
	unsigned int GetScore() const;
	bool IsDestroyed() const;
	bool HasExploded() const;

private:
	float m_Speed;
	unsigned int m_Health;
	unsigned int m_Damage;
	unsigned int m_Score;
	bool m_Destroyed;
	bool m_HasExploded;
	std::unique_ptr<MeteorHealthHUD> m_HealthHUD;
	std::unique_ptr<Explosion> m_Explosion;

	void SetRandomPosition();
	void Move(float deltaTime);
};
