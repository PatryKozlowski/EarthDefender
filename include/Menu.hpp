#pragma once

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

struct MenuOption
{
    std::string label;
    sf::Text text;
};

class Menu
{
public:
    Menu(sf::RenderWindow &window);
    ~Menu() = default;

    void HandleInput(const sf::Event &event, bool &startGame, bool &exitGame);
    void Draw();

private:
    sf::RenderWindow &m_Window;
    sf::Font m_Font;
    sf::Text m_Title;
    std::vector<MenuOption> m_Options;

    void InitMenu();
};