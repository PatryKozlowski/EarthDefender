#pragma once

#include "GameConfig.hpp"
#include "Timer.hpp"
#include "MeteorManager.hpp"
#include "BuffManager.hpp"
#include "ui/bars/TopBarHUD.hpp"
#include "Affect.hpp"
#include "ui/EarthEntityHUD.hpp"


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
	Timer m_GameTimer;
	Timer m_MeteorsSpawnTimer;
	Timer m_BuffsSpawnTimer;
	GameStateID m_CurrentGameState;
	TopBarHUD m_TopBarHUD;
	Affect m_Affect;
	Player m_Player;
	EarthEntityHUD m_EarthEntityHUD;
	MeteorManager m_MeteorManager;
	BuffManager m_BuffManager;

	void DrawTopBarHUD();
	void DrawEarthEntityHUD();
	void StartTimers();
	void StopTimers();
	void UpdateMeteorSpawning();
	void UpdateBuffSpawning();
	void ResetSpawners();
	void EndGame();
	void GameOver();
};