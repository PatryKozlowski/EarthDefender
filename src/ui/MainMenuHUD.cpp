#include "ui/MainMenuHUD.hpp"

MainMenuHUD::MainMenuHUD(sf::RenderWindow &window)
    : MenuHUD(window)
{
    InitMainMenu();
}

void MainMenuHUD::HandleInput(const sf::Event &event)
{
    MenuHUD::HandleInput(event);
}

bool MainMenuHUD::IsStartGame() const
{
    return m_StartGame;
}

bool MainMenuHUD::IsExitGame() const
{
    return m_ExitGame;
}

void MainMenuHUD::InitMainMenu()
{
    InitOptions({m_Config.START_GAME, m_Config.EXIT});
}

void MainMenuHUD::DrawMenuTitle(sf::RenderWindow &window)
{
    m_Title->SetText(m_Config.TITLE);
    m_Title->SetSize(m_Config.TITLE_SIZE);
    m_Title->SetColor(m_Config.TITLE_COLOR);
    m_Title->SetPosition(sf::Vector2f(window.getSize().x / 2 - m_Title->GetBound().width / 2, m_Config.TITLE_Y));
    m_Title->Draw(window);
}

void MainMenuHUD::OnOptionClick(const std::string &label)
{
    if (label == m_Config.START_GAME)
    {
        m_StartGame = true;
    }

    if (label == m_Config.EXIT)
    {
        m_ExitGame = true;
    }
}
