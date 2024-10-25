#include "ui/GameTime.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"

GameTime::GameTime() : m_TimeText(std::make_unique<Text>())
{
    AssetManager::GetInstance().LoadTexture(AssetSettings::TIME_TEXT::TEXTURE_PATH);
    const auto &texture = AssetManager::GetInstance().LoadTexture(AssetSettings::TIME_TEXT::TEXTURE_PATH);

    SetObjectTexture(texture);
    sf::Vector2u windowSize = sf::Vector2u(WindowConfig::WIDTH, WindowConfig::HEIGHT);

    SetObjectPosition(WindowConfig::WIDTH / 2 - texture.getSize().x / 2, AssetSettings::TIME_TEXT::Y_OFFSET);

    SetObjectScale(AssetSettings::TIME_TEXT::SCALE, AssetSettings::TIME_TEXT::SCALE);

    InitTimeText();
}

void GameTime::Draw(sf::RenderWindow &window) const
{
    Object::Draw(window);

    if (m_TimeText)
    {
        m_TimeText->Draw(window);
    }
}

void GameTime::ShowTime(const unsigned int time)
{
    m_TimeText->SetText(std::to_string(time));
}

void GameTime::InitTimeText() const
{
    m_TimeText->SetSize(GamePlayHUDConfig::TEXT_SIZE);
    m_TimeText->SetColor(GamePlayHUDConfig::TEXT_COLOR);
    float clockIconWidth = m_Sprite.getGlobalBounds().width;
    float textYOffset = m_Sprite.getPosition().y / 2;
    m_TimeText->SetPosition(sf::Vector2f(WindowConfig::WIDTH / 2 + clockIconWidth / 2 + 10, textYOffset));
}