#pragma once

#include "ui/Hud.hpp"

#include <SFML/Graphics/Text.hpp>

class GamePlayHUD : public Hud
{
public:
    GamePlayHUD(sf::RenderWindow &window);
    virtual ~GamePlayHUD() = default;

    void Draw() override;
    void HandleInput(const sf::Event &event) override;
    void SetTime(float &ime);

private:
    int m_Time;
    sf::Text m_TimeText;

    void InitTimeText();
};
