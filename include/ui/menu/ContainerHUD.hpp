#pragma once

#include <SFML/Graphics.hpp>
#include "GameConfig.hpp"

class ContainerHUD
{
public:
	ContainerHUD();

	void Draw(sf::RenderWindow& window);
	void InitContainer();
	inline sf::Vector2f GetContainerPosition() const { return m_Container.getPosition(); };
	sf::FloatRect GetContainerGlobalBounds() const { return m_Container.getGlobalBounds(); };

private:
	sf::RectangleShape m_Container;
};