#include "ui/Earth.hpp"

Earth::Earth()
	: Object(AssetSettings::EARTH::TEXTURE_PATH, AssetSettings::EARTH::SCALE, 0.0f, 0.0f)
{
	float xPosition = WindowConfig::WIDTH / 2.0f - GetObjectBound().width / 2.0f;
	float yPosition = WindowConfig::HEIGHT - GetObjectBound().height - AssetSettings::EARTH::Y_OFFSET;

	SetObjectPosition(xPosition, yPosition);

	m_Radius = GetObjectRadius();
}

void Earth::Draw(sf::RenderWindow& window) const
{
	Object::Draw(window);
}