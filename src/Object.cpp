#include "Object.hpp"

Object::Object()
{
}

void Object::SetObjectPosition(float x, float y)
{
    m_Position.x = x;
    m_Position.y = y;
    m_Sprite.setPosition(m_Position);
}

void Object::SetObjectTexture(const sf::Texture &texture)
{
    m_Sprite.setTexture(texture);
}

void Object::Update([[maybe_unused]] const float deltaTime) const
{
}

void Object::Draw(sf::RenderWindow &window) const
{
    window.draw(m_Sprite);
}

void Object::SetObjectScale(float x, float y)
{
    m_Sprite.setScale(x, y);
}

sf::FloatRect Object::GetObjectBound() const
{
    return m_Sprite.getGlobalBounds();
}