#pragma once

#include "Timer.hpp"
#include "GameConfig.hpp"
#include "ui/GamePlayHUD.hpp"

class Game
{
public:
    Game(sf::RenderWindow &window);
    void StartGame(const float &deltaTime);
    GameState GetCurrentGameState() const;
    void RestartGame();

private:
    Timer m_Timer;
    GameState m_CurrentGameState = GameState::PLAYING;
    GamePlayHUD m_GamePlayHUD;
};