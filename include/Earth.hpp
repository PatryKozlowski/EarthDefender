#pragma once

#include "Object.hpp"

class Earth : public Object
{
public:
	Earth();
	void Draw(sf::RenderWindow& window) const override;
	//float GetRadius() const;

private:
	float m_Radius;
};