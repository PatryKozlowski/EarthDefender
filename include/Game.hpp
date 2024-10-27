#pragma once

#include "ui/GamePlayHUD.hpp"
#include "Earth.hpp"
#include "GameConfig.hpp"
#include <Timer.hpp>
#include "MeteorManager.hpp"

class Game
{
public:
	Game(sf::RenderWindow& window);
	void StartGame();
	void Update(float deltaTime);
	void RestartGame();
	void HandleClick(sf::Vector2i& mousePosition);
	GameState GetCurrentGameState() const;

private:
	sf::RenderWindow& m_Window;
	std::unique_ptr<Timer> m_GameTimer;
	std::unique_ptr<Timer> m_MeteorsSpawnTimer;
	GameState m_CurrentGameState;
	std::unique_ptr<GamePlayHUD> m_GamePlayHUD;
	std::unique_ptr<Earth> m_PlayerEarth;
	std::unique_ptr<MeteorManager> m_MeteorManager;
	unsigned int m_PlayerHealth;
	unsigned int m_PlayerScore;

	void DrawGameHUD();
	void StartTimers();
	void StopTimers();
	void UpdateMeteorSpawning();
	void EndGame();
	void GameOver();
};