#include "ui/EndGameHUD.hpp"

EndGameHUD::EndGameHUD(sf::RenderWindow &window)
    : MenuHUD(window)
{
    InitEndGameHUD();
}

void EndGameHUD::HandleInput(const sf::Event &event)
{
    MenuHUD::HandleInput(event);
}

bool EndGameHUD::IsRestartGame() const
{
    return m_RestartGame;
}

bool EndGameHUD::IsExitGame() const
{
    return m_ExitGame;
}

void EndGameHUD::ResetFlags()
{
    m_RestartGame = false;
    m_ExitGame = false;
}
void EndGameHUD::InitEndGameHUD()
{
    InitOptions({m_Config.PLAY_AGAIN, m_Config.EXIT});
}

void EndGameHUD::DrawMenuTitle(sf::RenderWindow &window)
{
    m_Title->SetText(m_Config.TITLE_END_GAME);
    m_Title->SetSize(m_Config.TITLE_SIZE);
    m_Title->SetColor(m_Config.TITLE_COLOR);
    m_Title->SetPosition(sf::Vector2f(window.getSize().x / 2 - m_Title->GetBound().width / 2, m_Config.TITLE_Y));
    m_Title->Draw(window);
}

void EndGameHUD::OnOptionClick(const std::string &label)
{
    if (label == m_Config.PLAY_AGAIN)
    {
        m_RestartGame = true;
    }

    if (label == m_Config.EXIT)
    {
        m_ExitGame = true;
    }
}