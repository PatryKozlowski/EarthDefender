#pragma once

#include "Object.hpp"
#include "ui/Text.hpp"
#include "ui/Heart.hpp"
#include "ui/MeteorHealthHUD.hpp"
#include "ui/Explosion.hpp"

class Meteor : public Object
{
public:
	Meteor(const sf::Texture& texture, float speed, unsigned int health, unsigned int damage, unsigned int score);

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void Destroy();
	void TakeDamage(const unsigned int& damage);
	void UpdateHealthText(const unsigned int& health);
	void Explode(bool isMeteorExplosionByPlayer);
	unsigned int GetHealth() const;
	unsigned int GetDamage() const;
	unsigned int GetScore() const;
	float GetRadius() const;
	bool IsDestroyed() const;
	bool IsClicked(const sf::Vector2i& mousePosition) const;
	bool HasExploded() const;

private:
	float m_Speed;
	unsigned int m_Health;
	unsigned int m_Damage;
	unsigned int m_Score;
	float m_Radius;
	bool m_Destroyed;
	bool m_HasExploded;
	std::unique_ptr<MeteorHealthHUD> m_HealthHUD;
	std::unique_ptr<Explosion> m_Explosion;

	void SetRandomPosition();
	void Move(float deltaTime);
};
