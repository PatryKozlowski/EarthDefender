#include "ui/Coin.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"

Coin::Coin() : m_ScoreText(std::make_unique<Text>())
{
    AssetManager::GetInstance().LoadTexture(AssetSettings::COIN::TEXTURE_PATH);
    const auto &texture = AssetManager::GetInstance().LoadTexture(AssetSettings::COIN::TEXTURE_PATH);

    SetObjectTexture(texture);

    SetObjectPosition(WindowConfig::WIDTH - texture.getSize().x - 90.0f, AssetSettings::COIN::Y_OFFSET);

    SetObjectScale(AssetSettings::COIN::SCALE, AssetSettings::COIN::SCALE);

    InitCoin();
}

void Coin::Draw(sf::RenderWindow &window) const
{
    Object::Draw(window);

    if (m_ScoreText)
    {
        m_ScoreText->Draw(window);
    }
}

void Coin::ShowScore(const unsigned int score)
{
    m_ScoreText->SetText(std::to_string(score));
}

void Coin::InitCoin() const
{
    m_ScoreText->SetSize(GamePlayHUDConfig::TEXT_SIZE);
    m_ScoreText->SetColor(GamePlayHUDConfig::TEXT_COLOR);
    const float scoreIconWidth = m_Sprite.getGlobalBounds().width;
    const float textYOffset = m_Sprite.getPosition().y / 2;
    m_ScoreText->SetPosition(sf::Vector2f(WindowConfig::WIDTH - scoreIconWidth / 2 - 65, textYOffset));
}