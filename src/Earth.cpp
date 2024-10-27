#include "Earth.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"

Earth::Earth()
{
	AssetManager::GetInstance().LoadTexture(AssetSettings::EARTH::TEXTURE_PATH);
	const auto& texture = AssetManager::GetInstance().LoadTexture(AssetSettings::EARTH::TEXTURE_PATH);

	SetObjectTexture(texture);
	sf::Vector2u windowSize = sf::Vector2u(WindowConfig::WIDTH, WindowConfig::HEIGHT);

	SetObjectScale(AssetSettings::EARTH::SCALE, AssetSettings::EARTH::SCALE);

	sf::FloatRect spriteBounds = m_Sprite.getGlobalBounds();
	float xPosition = (windowSize.x / 2.0f) - (spriteBounds.width / 2.0f);
	float yPosition = windowSize.y - spriteBounds.height - AssetSettings::EARTH::Y_OFFSET;

	SetObjectPosition(xPosition, yPosition);

	m_Radius = GetObjectBound().width / 2.0f;
}

void Earth::Draw(sf::RenderWindow& window) const
{
	Object::Draw(window);
}

void Earth::Update(const float deltaTime)
{
	Object::Update(deltaTime);
}

float Earth::GetRadius() const
{
	return m_Radius;
}
