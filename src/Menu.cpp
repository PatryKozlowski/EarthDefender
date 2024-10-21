#include "Menu.hpp"
#include "AssetManager.hpp"

Menu::Menu(sf::RenderWindow &window) : m_Window(window)
{
    AssetManager::GetInstance().LoadFont("/Users/patrykkozlowski/Desktop/Projekty/EarthDefender/assets/font.ttf");

    const sf::Font &font = AssetManager::GetInstance().GetFont("/Users/patrykkozlowski/Desktop/Projekty/EarthDefender/assets/font.ttf");

    m_Font = font;

    InitMenu();
}

void Menu::HandleInput(const sf::Event &event, bool &startGame, bool &exitGame)
{
    if (event.type == sf::Event::MouseMoved)
    {
        for (auto &option : m_Options)
        {
            if (option.text.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
            {
                option.text.setFillColor(sf::Color::Magenta);
            }
            else
            {
                option.text.setFillColor(sf::Color::White);
            }
        }
    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        for (const auto &option : m_Options)
        {
            if (option.text.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
            {
                if (option.label == "Start Game")
                {
                    startGame = true;
                }

                if (option.label == "Exit")
                {
                    exitGame = true;
                }
            }
        }
    }
}

void Menu::InitMenu()
{
    m_Title.setFont(m_Font);
    m_Title.setString("> Earth Defender <");
    m_Title.setCharacterSize(50);
    m_Title.setFillColor(sf::Color::White);
    m_Title.setPosition(m_Window.getSize().x / 2 - m_Title.getGlobalBounds().width / 2, 200);

    m_Options.push_back({"Start Game", sf::Text()});
    m_Options.push_back({"Exit", sf::Text()});

    float yOffset = 300.0f;

    for (auto &option : m_Options)
    {
        option.text.setFont(m_Font);
        option.text.setString(option.label);
        option.text.setCharacterSize(30);
        option.text.setFillColor(sf::Color::White);
        option.text.setPosition(m_Window.getSize().x / 2 - option.text.getGlobalBounds().width / 2, yOffset);
        yOffset += 50.0f;
    }
}

void Menu::Draw()
{
    m_Window.draw(m_Title);

    for (const auto &option : m_Options)
    {
        m_Window.draw(option.text);
    }
}
