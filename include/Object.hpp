#pragma once

#include <SFML/Graphics.hpp>

class Object
{
public:
	Object(const std::string& texturePath, float scale, float x, float y);
	virtual ~Object() = default;

	void SetObjectPosition(float x, float y);
	void SetObjectTexture(const std::string& texturePath);
	void SetObjectScale(float x, float y);
	void CenterObjectHorizontal(float windowWidth);
	void SetObjectPositionBottom(float windowHeight, float yOffset);
	void SetObjectTextureRect(int x, int y, int width, int height);
	void SetObjectOrigin(float x, float y);
	float GetObjectRadius() const;
	sf::FloatRect GetObjectBound() const;
	sf::Vector2f GetObjectPosition() const;
	virtual void Update(float deltaTime);
	virtual void Draw(sf::RenderWindow& window) const;

private:
	sf::Sprite m_Sprite;
	sf::Vector2f m_Position;
};