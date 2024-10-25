#pragma once

#include <SFML/Graphics.hpp>
#include "Heart.hpp"
#include <vector>
#include "GameTime.hpp"
#include "Coin.hpp"

class GamePlayHUD
{
public:
    GamePlayHUD(sf::RenderWindow &window);

    void Draw() const;
    void SetTime(const float &ime);
    void SetScore(const unsigned int score);
    void UpdateHearts(unsigned int playerLives);

private:
    sf::RenderWindow &m_Window;
    std::vector<Heart> m_Hearts;
    GameTime m_GameTime;
    Coin m_Coin;

    void InitHeart();
};
