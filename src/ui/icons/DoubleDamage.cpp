#include "ui/icons/DoubleDamage.hpp"

#include "GameConfig.hpp"	

DoubleDamage::DoubleDamage()
	:Object(AssetSettings::BUFF::DOUBLE_DAMAGE::TEXTURE_PATH, AssetSettings::BUFF::SCALE, 0.0f, 0.0f)
{
}

void DoubleDamage::Draw(sf::RenderWindow& window) const
{
	Object::Draw(window);
}
