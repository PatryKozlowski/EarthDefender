#pragma once

#include <SFML/Graphics.hpp>
#include "Heart.hpp"
#include <vector>
#include "GameTime.hpp"
#include "Coin.hpp"

class GamePlayHUD
{
public:
	GamePlayHUD(sf::RenderWindow& window);

	void Draw() const;
	void Update(const float deltaTime);
	void SetGameTime(const float& time);
	void SetPlayerScore(const unsigned int& score);
	void SetPlayerLives(const unsigned int& playerLives);

private:
	sf::RenderWindow& m_Window;
	std::vector<Heart> m_Hearts;
	GameTime m_GameTime;
	Coin m_Coin;
};
