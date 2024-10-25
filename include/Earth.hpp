#pragma once

#include "Object.hpp"

class Earth : public Object
{
public:
    Earth();
    void Draw(sf::RenderWindow &window) const override;
    virtual void Update(const float deltaTime) const override;
};