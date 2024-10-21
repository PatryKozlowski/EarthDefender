#include "ui/MainMenuHUD.hpp"

MainMenuHUD::MainMenuHUD(sf::RenderWindow &window)
    : Hud(window)
{
    InitMenu();
}

void MainMenuHUD::HandleInput(const sf::Event &event)
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
                if (option.label == m_Config.START_GAME)
                {
                    m_StartGame = true;
                }

                if (option.label == m_Config.EXIT)
                {
                    m_ExitGame = true;
                }
            }
        }
    }
}

void MainMenuHUD::InitMenu()
{
    m_Title.setFont(m_Font);
    m_Title.setString(m_Config.TITLE);
    m_Title.setCharacterSize(m_Config.TITLE_SIZE);
    m_Title.setFillColor(m_Config.TITLE_COLOR);
    m_Title.setPosition(m_Window.getSize().x / 2 - m_Title.getGlobalBounds().width / 2, m_Config.TITLE_Y);

    m_Options.push_back({m_Config.START_GAME, sf::Text()});
    m_Options.push_back({m_Config.EXIT, sf::Text()});

    float yOffset = m_Config.OPTION_Y;

    for (auto &option : m_Options)
    {
        option.text.setFont(m_Font);
        option.text.setString(option.label);
        option.text.setCharacterSize(m_Config.OPTION_SIZE);
        option.text.setFillColor(m_Config.OPTION_COLOR);
        option.text.setPosition(m_Window.getSize().x / 2 - option.text.getGlobalBounds().width / 2, yOffset);
        yOffset += m_Config.OPTION_Y_OFFSET;
    }
}

void MainMenuHUD::Draw()
{
    m_Window.draw(m_Title);

    for (const auto &option : m_Options)
    {
        m_Window.draw(option.text);
    }
}

bool MainMenuHUD::IsStartGame() const
{
    return m_StartGame;
}

bool MainMenuHUD::IsExitGame() const
{
    return m_ExitGame;
}
