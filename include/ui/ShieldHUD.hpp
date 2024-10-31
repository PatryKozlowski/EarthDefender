#pragma once

#include <SFML/Graphics.hpp>
#include "ui/Shield.hpp"
#include "Earth.hpp"
#include "Affect.hpp"
#include "Text.hpp"

class ShieldHUD
{
public:
	ShieldHUD(Earth& earth, Affect& affcet);

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window) const;
	inline void SetShieldTime(float time) { m_ShieldTime = time; }
	inline float GetShieldTime() const { return m_ShieldTime; }

private:
	std::unique_ptr<Shield> m_Shield;
	Earth& m_Earth;
	Affect& m_Affect;
	std::unique_ptr<Text> m_Text;
	float m_ShieldTime;

	void SetShieldObject() const;
	void SetTextObject() const;
	void SetTextContent(float deltaTime);
};