#pragma once

#include <SFML/Graphics.hpp>

class Object
{
public:
	Object();
	virtual ~Object() = default;

	void SetObjectPosition(float x, float y);
	void SetObjectTexture(const sf::Texture& texture);
	void SetObjectScale(float x, float y);
	sf::FloatRect GetObjectBound() const;
	virtual void Update(const float deltaTime);
	virtual void Draw(sf::RenderWindow& window) const;
	sf::Vector2f GetObjectPosition() const;

protected:
	sf::Sprite m_Sprite;
	sf::Vector2f m_Position;
};