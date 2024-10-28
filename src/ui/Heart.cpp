#include "ui/Heart.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"

Heart::Heart()
	: Object(AssetSettings::HEART::TEXTURE_PATH, AssetSettings::HEART::SCALE, 0.0f, 0.0f)
{
}

void Heart::Draw(sf::RenderWindow& window) const
{
	Object::Draw(window);
}
