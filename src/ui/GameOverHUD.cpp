#include "ui/GameOverHUD.hpp"

GameOverHUD::GameOverHUD(sf::RenderWindow &window)
    : Hud(window)
{
    InitGameOverHUD();
}

bool GameOverHUD::IsRestartGame() const
{
    return m_RestartGame;
}

bool GameOverHUD::IsExitGame() const
{
    return m_ExitGame;
}

void GameOverHUD::HandleInput(const sf::Event &event)
{
    if (event.type == sf::Event::MouseMoved)
    {
        for (auto &option : m_Options)
        {
            if (option.text.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
            {
                option.text.setFillColor(m_Config.OPTION_HIGHLIGHT_COLOR);
            }
            else
            {
                option.text.setFillColor(m_Config.OPTION_COLOR);
            }
        }
    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        for (const auto &option : m_Options)
        {
            if (option.text.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
            {
                if (option.label == m_Config.RESTART_GAME)
                {
                    m_RestartGame = true;
                }

                if (option.label == m_Config.EXIT)
                {
                    m_ExitGame = true;
                }
            }
        }
    }
}

void GameOverHUD::InitGameOverHUD()
{
    m_GameOverText.setFont(m_Font);
    m_GameOverText.setCharacterSize(m_Config.GAME_OVER_TEXT_SIZE);
    m_GameOverText.setFillColor(m_Config.GAME_OVER_TEXT_COLOR);
    m_GameOverText.setString(m_Config.GAME_OVER_TEXT);
    m_GameOverText.setPosition(m_Window.getSize().x / 2 - m_GameOverText.getGlobalBounds().width / 2, m_Config.GAME_OVER_TEXT_Y);

    GameOverOption restartGameOption;
    restartGameOption.label = m_Config.RESTART_GAME;
    restartGameOption.text.setFont(m_Font);
    restartGameOption.text.setCharacterSize(m_Config.OPTION_SIZE);
    restartGameOption.text.setFillColor(m_Config.OPTION_COLOR);
    restartGameOption.text.setString(restartGameOption.label);
    restartGameOption.text.setPosition(m_Window.getSize().x / 2 - restartGameOption.text.getGlobalBounds().width / 2, m_Config.OPTION_Y);

    GameOverOption exitOption;
    exitOption.label = m_Config.EXIT;
    exitOption.text.setFont(m_Font);
    exitOption.text.setCharacterSize(m_Config.OPTION_SIZE);
    exitOption.text.setFillColor(m_Config.OPTION_COLOR);
    exitOption.text.setString(exitOption.label);
    exitOption.text.setPosition(m_Window.getSize().x / 2 - exitOption.text.getGlobalBounds().width / 2, m_Config.OPTION_Y + m_Config.OPTION_Y_OFFSET);

    m_Options.push_back(restartGameOption);
    m_Options.push_back(exitOption);
}

void GameOverHUD::Draw()
{
    m_Window.draw(m_GameOverText);

    for (const auto &option : m_Options)
    {
        m_Window.draw(option.text);
    }
}