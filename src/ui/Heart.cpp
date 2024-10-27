#include "ui/Heart.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"

Heart::Heart(float x, float y)
	: Object(AssetSettings::HEART::TEXTURE_PATH, AssetSettings::HEART::SCALE, x, y)
{
}

void Heart::Draw(sf::RenderWindow& window) const
{
	Object::Draw(window);
}
