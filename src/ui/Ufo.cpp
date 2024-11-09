#include "ui/Ufo.hpp"

Ufo::Ufo()
	: Object(AssetSettings::UFO::TEXTURE_PATH, AssetSettings::UFO::SCALE, 0.0f, 0.0f)
{
	float xPosition = WindowConfig::WIDTH / 2.0f - GetObjectBound().width / 2.0f;
	float yPosition = GetObjectBound().height - AssetSettings::EARTH::Y_OFFSET;

	SetObjectPosition(xPosition, yPosition);

	m_Radius = GetObjectRadius();
}

void Ufo::Draw(sf::RenderWindow& window) const
{
	Object::Draw(window);
}