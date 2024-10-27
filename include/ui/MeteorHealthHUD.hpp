#pragma once

#include "Text.hpp"
#include "Heart.hpp"
#include "Object.hpp"

class MeteorHealthHUD : public Object
{
public:
	MeteorHealthHUD();
	void Draw(sf::RenderWindow& window);
	void Update(float deltaTime);
	void UpdateHealthText(const unsigned int& health);
	void InitMeteorHealthHUD(sf::Vector2f position, const unsigned int& health);
	void StartAnimation();

private:
	std::unique_ptr<Text> m_HealthText;
	std::unique_ptr<Heart> m_Heart;
	float m_ScaleFactor;
	float m_AnimatonSpeed;
	bool m_IsAnimating;
};