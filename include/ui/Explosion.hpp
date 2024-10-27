#pragma once

#include "Object.hpp"

class Explosion : public Object
{
public:
	Explosion(bool isMeteorExplosion);

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	bool IsFinished() const;
	void SetPosition(const sf::Vector2f& position);

private:
	sf::Sprite m_Sprite;
	bool m_IsMeteorExplosion;
	bool m_IsFinished;
	float m_ElapsedTime;
	float m_FrameDuration;
	int m_CurrentFrame;
};