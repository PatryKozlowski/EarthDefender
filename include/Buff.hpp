#pragma once

#include "Object.hpp"
#include "GameConfig.hpp"
#include "Game.hpp"

class Buff : public Object
{
	Buff(BuffTypeID type, float duration);

	void Update(float deltaTime) override;
	void Draw(sf::RenderWindow& window) const override;
	//void ApplyEffect(Game& game);
	bool IsClicked(const sf::Vector2i& mousePosition) const;
	bool IsDestroyed() const { return m_Destroyed; };
	bool IsAcitve() const { return m_IsActive; };

private:
	BuffTypeID m_Type;
	float m_Duration;
	bool m_Destroyed;
	bool m_IsActive;

	void SetRandomPosition();
};