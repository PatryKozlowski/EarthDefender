#include "ui/Heart.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"

Heart::Heart(float x, float y)
{
    AssetManager::GetInstance().LoadTexture(AssetSettings::HEART::TEXTURE_PATH);
    const auto &texture = AssetManager::GetInstance().LoadTexture(AssetSettings::HEART::TEXTURE_PATH);

    SetObjectTexture(texture);
    sf::Vector2u windowSize = sf::Vector2u(WindowConfig::WIDTH, WindowConfig::HEIGHT);

    SetObjectPosition(x, y);

    SetObjectScale(AssetSettings::HEART::SCALE, AssetSettings::HEART::SCALE);
}

void Heart::Draw(sf::RenderWindow &window) const
{
    Object::Draw(window);
}

void Heart::Update(const float deltaTime) const
{
    Object::Update(deltaTime);
}