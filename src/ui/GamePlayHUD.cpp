#include "ui/GamePlayHUD.hpp"
#include "GameConfig.hpp"
#include "AssetManager.hpp"
#include <iostream>

GamePlayHUD::GamePlayHUD(sf::RenderWindow &window)
    : m_Window(window)
{
    InitHeart();
}

void GamePlayHUD::SetTime(const float &time)
{
    m_GameTime.ShowTime(static_cast<unsigned int>(time));
}

void GamePlayHUD::SetScore(const unsigned int score)
{
    m_Coin.ShowScore(score);
}

void GamePlayHUD::UpdateHearts(unsigned int playerLives)
{
    m_Hearts.clear();

    for (unsigned int i = 0; i < playerLives; ++i)
    {
        m_Hearts.emplace_back(AssetSettings::HEART::X_OFFSET + i * 40, 10);
    }

    for (const auto &heart : m_Hearts)
    {
        heart.Draw(m_Window);
    }
}

void GamePlayHUD::InitHeart()
{
    for (unsigned int i = 0; i < GameConfig::INIT_PLAYER_LIFE; i++)
    {
        m_Hearts.emplace_back(AssetSettings::HEART::X_OFFSET + i * AssetSettings::HEART::SPACE_BETWEEN, AssetSettings::HEART::Y_OFFSET);
    }
}

void GamePlayHUD::Draw() const
{
    sf::RectangleShape background(sf::Vector2f(WindowConfig::WIDTH, GamePlayHUDConfig::BACKGROUND_Y_OFFSET));
    background.setFillColor(GamePlayHUDConfig::BACKGROUND_COLOR);
    m_Window.draw(background);

    for (const auto &heart : m_Hearts)
    {
        heart.Draw(m_Window);
    }

    m_GameTime.Draw(m_Window);
    m_Coin.Draw(m_Window);
}
