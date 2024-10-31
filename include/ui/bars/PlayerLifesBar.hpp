#pragma once

#include "ui/icons/Heart.hpp"
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

class PlayerLifesBar
{
public:
	PlayerLifesBar();

	void Draw(sf::RenderWindow& window) const;
	void Update(float deltaTime);
	void SetLife(unsigned int livesCount);
	inline void SetAnimation(bool isAnimating) { m_Animation.isAnimating = isAnimating; };
	inline void SetScaleFactor(float scaleFactor) { m_Animation.scaleFactor = scaleFactor; };
	inline void SetAnimationSpeed(float animationSpeed) { m_Animation.animationSpeed = animationSpeed; };
	inline bool IsAnimating() const { return m_Animation.isAnimating; };
	inline float GetScaleFactor() const { return m_Animation.scaleFactor; };
	inline float GetAnimationSpeed() const { return m_Animation.animationSpeed; };


private:
	std::vector<std::unique_ptr<Heart>> m_Hearts;

	struct Animation
	{
		float scaleFactor;
		float animationSpeed;
		bool isAnimating;
	} m_Animation;

	void StartAnimation();
};