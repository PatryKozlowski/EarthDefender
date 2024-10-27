#pragma once

#include "Object.hpp"

class Explosion : public Object
{
public:
	Explosion(bool isMeteorExplosionByPlayer);

	void Update(float deltaTime) override;
	void Draw(sf::RenderWindow& window) const override;
	bool IsFinished() const;

private:
	bool m_IsExplosionByPlayer;
	bool m_IsFinished;
	float m_ElapsedTime;
	float m_FrameDuration;
	int m_CurrentFrame;

	void UpdateTextureRect();
};