#include "ui/GamePlayHUD.hpp"

#include <iostream>

GamePlayHUD::GamePlayHUD(sf::RenderWindow &window)
    : Hud(window)
{
    InitTimeText();
}

void GamePlayHUD::SetTime(float &time)
{
    m_Time = static_cast<int>(time);
    m_TimeText.setString(std::to_string(m_Time));
}

void GamePlayHUD::InitTimeText()
{
    m_TimeText.setFont(m_Font);
    m_TimeText.setCharacterSize(36);
    m_TimeText.setFillColor(sf::Color::White);
    m_TimeText.setPosition(m_Window.getSize().x / 2 - m_TimeText.getGlobalBounds().width / 2, 0.0f);
}

void GamePlayHUD::Draw()
{
    m_Window.draw(m_TimeText);
}

void GamePlayHUD::HandleInput(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Escape)
        {
            std::cout << "Escape key pressed" << std::endl;
        }
    }
}