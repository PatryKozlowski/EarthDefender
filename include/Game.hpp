#pragma once

#include "GameConfig.hpp"
#include "Timer.hpp"
#include "MeteorManager.hpp"
#include "BuffManager.hpp"
#include "ui/bars/TopBarHUD.hpp"
#include "Affect.hpp"
#include "ui/EarthEntityHUD.hpp"
#include "ui/menu/EndGameScoreHUD.hpp"
#include "ApplicationState.hpp"

class Game
{
public:
	Game(sf::RenderWindow& window, ApplicationState& applicationState);
	void StartGame();
	void Update(float deltaTime);
	void RestartGame();
	void HandleInput(const sf::Event& event);
	void ShowScoreBoard();

private:
	sf::RenderWindow& m_Window;
	Timer m_GameTimer;
	Timer m_MeteorsSpawnTimer;
	Timer m_BuffsSpawnTimer;
	TopBarHUD m_TopBarHUD;
	Affect m_Affect;
	Player m_Player;
	EarthEntityHUD m_EarthEntityHUD;
	MeteorManager m_MeteorManager;
	BuffManager m_BuffManager;
	ApplicationState& m_ApplicationState;
	std::unique_ptr<EndGameScoreHUD> m_EndGameScore;

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