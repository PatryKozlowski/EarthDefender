#pragma once

#include <SFML/Graphics.hpp>
#include "GameConfig.hpp"
#include "ui/MainMenuHUD.hpp"
#include "Game.hpp"
#include "ui/EndGameHUD.hpp"

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
    MainMenuHUD m_MainMenuHUD;
    EndGameHUD m_EndGameHUD;
    Game m_Game;

    void HandleGameStateInput(const sf::Event &event);
    void UpdateGameStates(const float &deltaTime);
};
