#pragma once

#include "Timer.hpp"
#include "ui/GamePlayHUD.hpp"
#include "Earth.hpp"
#include "GameConfig.hpp"

class Game
{
public:
    Game(sf::RenderWindow &window);
    void StartGame(const float &deltaTime);
    GameState GetCurrentGameState() const;
    void RestartGame();

private:
    sf::RenderWindow &m_Window;
    Timer m_Timer;
    GameState m_CurrentGameState = GameState::PLAYING;
    std::unique_ptr<GamePlayHUD> m_GamePlayHUD;
    Earth m_PlayerEarth;
    // unsigned int m_PlayerLife = GameConfig::INIT_PLAYER_LIFE;
};