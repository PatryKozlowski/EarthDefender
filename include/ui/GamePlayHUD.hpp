#pragma once

#include <SFML/Graphics.hpp>
#include "Text.hpp"

class GamePlayHUD
{
public:
    GamePlayHUD(sf::RenderWindow &window);

    void Draw() const;
    void SetTime(const float &ime);

private:
    int m_Time{};
    sf::RenderWindow &m_Window;
    std::unique_ptr<Text> m_TimeText;

    void InitTimeText() const;
};
