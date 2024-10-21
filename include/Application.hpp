#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "GameConfig.hpp"
#include "Menu.hpp"

class Application
{
public:
    Application(unsigned int width, unsigned int height, const std::string &title, sf::Uint32 style, float fps);
    ~Application() = default;

    void Run();

private:
    sf::RenderWindow m_Window;
    sf::Clock m_Clock;
    float m_TargetFps;
    GameState m_CurrentGameState;
    std::unique_ptr<Menu> m_Menu;
};