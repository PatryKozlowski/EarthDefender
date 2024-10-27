#include "Object.hpp"
#include "AssetManager.hpp"

Object::Object(const std::string& texturePath, float scale = 1.0f, float x = 0.0f, float y = 0.0f)
{
	AssetManager::GetInstance().LoadTexture(texturePath);
	SetObjectTexture(texturePath);

	SetObjectScale(scale, scale);

	SetObjectPosition(x, y);
}

void Object::SetObjectPosition(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Sprite.setPosition(m_Position);
}

void Object::SetObjectTexture(const std::string& texturePath)
{
	const auto& texture = AssetManager::GetInstance().GetTexture(texturePath);
	m_Sprite.setTexture(texture);
}

void Object::Update(float deltaTime)
{
}

void Object::Draw(sf::RenderWindow& window) const
{
	window.draw(m_Sprite);
}

void Object::SetObjectScale(float x, float y)
{
	m_Sprite.setScale(x, y);
}

void Object::CenterObjectHorizontal(float windowWidth)
{
	sf::FloatRect spiritBound = GetObjectBound();
	float xPosition = (windowWidth / 2.0f) - (spiritBound.width / 2.0f);
	SetObjectPosition(xPosition, m_Position.y);
}

void Object::SetObjectPositionBottom(float windowHeight, float yOffset)
{
	sf::FloatRect spiritBound = GetObjectBound();
	float yPosition = windowHeight - spiritBound.height - yOffset;
	SetObjectPosition(m_Position.x, yPosition);
}

void Object::SetObjectTextureRect(int x, int y, int width, int height)
{
	m_Sprite.setTextureRect(sf::IntRect(x, y, width, height));
}

float Object::GetObjectRadius() const
{
	return GetObjectBound().width / 2.0f;
}

sf::FloatRect Object::GetObjectBound() const
{
	return m_Sprite.getGlobalBounds();
}

sf::Vector2f Object::GetObjectPosition() const
{
	return m_Position;
}