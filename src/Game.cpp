#include "Game.hpp"

#include <iostream>

Game::Game(float gameTime, sf::RenderWindow &window)
    : m_Timer(gameTime), m_GamePlayHUD(window)
{
}

void Game::StartGame(float deltaTime)
{
    m_GamePlayHUD.Draw();
    m_Timer.Start();
    float leftTime = g_GameConfig.GAME_TIME - m_Timer.GetElapsedTime();
    m_GamePlayHUD.SetTime(leftTime);
    m_Timer.Update(deltaTime);

    if (m_Timer.IsExpired())
    {
        m_Timer.Stop();
        m_CurrentGameState = GameState::GAME_OVER;
    }
}

GameState Game::GetCurrentGameState() const
{
    return m_CurrentGameState;
}