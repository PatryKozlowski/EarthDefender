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

private:
	std::vector<std::unique_ptr<Heart>> m_Hearts;
	float m_ScaleFactor;
	float m_AnimationSpeed;
	bool m_IsAnimating;

	void StartAnimation();
};