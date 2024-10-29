#pragma once

#include "GameConfig.hpp"
#include "Timer.hpp"
#include "MeteorManager.hpp"
#include "ui/bars/TopBarHUD.hpp"

class Game
{
public:
	Game(sf::RenderWindow& window);
	void StartGame();
	void Update(float deltaTime);
	void RestartGame();
	void HandleClick(sf::Vector2i& mousePosition);
	GameStateID GetCurrentGameState() const;

private:
	sf::RenderWindow& m_Window;
	std::unique_ptr<Timer> m_GameTimer;
	std::unique_ptr<Timer> m_MeteorsSpawnTimer;
	GameStateID m_CurrentGameState;
	std::unique_ptr<TopBarHUD> m_TopBarHUD;
	std::unique_ptr<Player> m_Player;
	std::unique_ptr<MeteorManager> m_MeteorManager;

	void DrawTopBarHUD();
	void StartTimers();
	void StopTimers();
	void UpdateMeteorSpawning();
	void EndGame();
	void GameOver();
};