#pragma once

#include <SFML/Graphics.hpp>
#include "AssetManager.hpp"

class Text
{
public:
	Text();
	void SetText(const std::string& text);
	void SetPosition(const sf::Vector2f& position);
	void SetColor(const sf::Color& color);
	void SetSize(unsigned int size);
	void SetOrigin(const sf::Vector2f& origin);
	void Draw(sf::RenderWindow& window) const;

	sf::FloatRect GetBound() const;

private:
	sf::Text m_Text;

	void LoadFont();
};