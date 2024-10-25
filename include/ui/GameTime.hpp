#pragma once

#include "Object.hpp"
#include "Text.hpp"

class GameTime : public Object
{
public:
    GameTime();
    void Draw(sf::RenderWindow &window) const override;
    void ShowTime(const unsigned int time);

private:
    std::unique_ptr<Text> m_TimeText;

    void InitTimeText() const;
};