#pragma once

#include <SFML/Graphics.hpp>

class Hud
{
public:
    Hud(sf::RenderWindow &window);
    virtual ~Hud() = default;

    virtual void HandleInput(const sf::Event &event) = 0;
    virtual void Draw() = 0;

protected:
    sf::RenderWindow &m_Window;
    sf::Font m_Font;
};