#pragma once

#include "Text.hpp"
#include "ui/icons/Heart.hpp"

class MeteorHealthHUD
{
public:
	MeteorHealthHUD();
	void Draw(sf::RenderWindow& window);
	void Update(float deltaTime);
	void UpdateHealthText(const unsigned int& health);
	void InitMeteorHealthHUD(sf::Vector2f position, const unsigned int& health);
	void StartAnimation();
	inline void SetScaleFactor(float scaleFactor) { m_Animation.scaleFactor = scaleFactor; };
	inline void SetAnimationSpeed(float animationSpeed) { m_Animation.animatonSpeed = animationSpeed; };
	inline void SetIsAnimating(bool isAnimating) { m_Animation.isAnimating = isAnimating; };
	inline float GetScaleFactor() const { return m_Animation.scaleFactor; };
	inline float GetAnimationSpeed() const { return m_Animation.animatonSpeed; };
	inline bool IsAnimating() const { return m_Animation.isAnimating; };

private:
	std::unique_ptr<Text> m_HealthText;
	std::unique_ptr<Heart> m_Heart;

	struct Animation
	{
		float scaleFactor;
		float animatonSpeed;
		bool isAnimating;
	} m_Animation;
};