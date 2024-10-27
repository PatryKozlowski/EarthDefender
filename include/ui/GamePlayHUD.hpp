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
	void Update(const unsigned int& playersLives, const unsigned int& score, const float& time);

private:
	sf::RenderWindow& m_Window;
	std::vector<Heart> m_Hearts;
	GameTime m_GameTime;
	Coin m_Coin;

	void InitHeart();
	void SetTime(const float& time);
	void SetScore(const unsigned int& score);
	void UpdateHearts(const unsigned int& playerLives);

};
