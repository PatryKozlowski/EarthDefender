#pragma once

#include "Timer.hpp"
#include "GameConfig.hpp"
#include "ui/GamePlayHUD.hpp"

class Game
{
public:
    Game(float gameTime, sf::RenderWindow &window);
    void StartGame(float deltaTime);
    // void Update(float deltaTime);
    // void Render();
    GameState GetCurrentGameState() const;

private:
    Timer m_Timer;
    GameState m_CurrentGameState = GameState::PLAYING;
    GamePlayHUD m_GamePlayHUD;
};