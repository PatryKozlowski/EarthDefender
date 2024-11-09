#pragma once

#include <SFML/Graphics.hpp>
#include "AssetManager.hpp"

class Object
{
public:
	Object(const std::string& texturePath, float scale, float x, float y);
	virtual ~Object() = default;

	virtual void Update(float deltaTime);
	virtual void Draw(sf::RenderWindow& window) const;
	void SetObjectPosition(float x, float y);
	void SetObjectTexture(const std::string& texturePath);
	void CenterObjectHorizontal(float windowWidth);
	void SetObjectPositionBottom(float windowHeight, float yOffset);
	bool IsClicked(const sf::Event& event) const;
	inline void SetObjectScale(float x, float y) { m_Sprite.setScale(x, y); };
	inline void SetObjectTextureRect(int x, int y, int width, int height) { m_Sprite.setTextureRect(sf::IntRect(x, y, width, height)); };
	inline void SetObjectOrigin(float x, float y) { m_Sprite.setOrigin(x, y); };
	inline float GetObjectRadius() const { return GetObjectBound().width / 2.0f; };
	inline sf::FloatRect GetObjectBound() const { return m_Sprite.getGlobalBounds(); };
	inline sf::Vector2f GetObjectPosition() const { return m_Position; };

private:
	sf::Sprite m_Sprite;
	sf::Vector2f m_Position;
};