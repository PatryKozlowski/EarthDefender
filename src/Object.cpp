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

bool Object::IsClicked(const sf::Event& event) const
{
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{

		auto objectPossition = GetObjectPosition();
		float objectRadius = GetObjectRadius();
		float objectPositionX = objectPossition.x;
		float objectPositionY = objectPossition.y;
		float objectCenterX = objectPositionX + objectRadius;
		float objectCenterY = objectPositionY + objectRadius;
		float mousePositionX = event.mouseButton.x;
		float mousePositionY = event.mouseButton.y;


		float distance = std::sqrt(std::pow(mousePositionX - objectCenterX, 2) + std::pow(mousePositionY - objectCenterY, 2));

		return distance <= objectRadius;
	}

	return false;
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