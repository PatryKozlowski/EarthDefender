#include "ui/GamePlayHUD.hpp"

GamePlayHUD::GamePlayHUD(sf::RenderWindow &window)
    : m_Window(window),
      m_TimeText(std::make_unique<Text>())
{
    InitTimeText();
}

void GamePlayHUD::SetTime(const float &time)
{
    m_Time = static_cast<int>(time);
    m_TimeText->SetText(std::to_string(m_Time));
}

void GamePlayHUD::InitTimeText() const
{
    m_TimeText->SetSize(36);
    m_TimeText->SetColor(sf::Color::White);
    m_TimeText->SetPosition(sf::Vector2f(m_Window.getSize().x / 2 - m_TimeText->GetBound().width / 2, 0.0f));
}

void GamePlayHUD::Draw() const
{
    m_TimeText->Draw(m_Window);
}
