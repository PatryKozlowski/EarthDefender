#include "ui/Text.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"

Text::Text()
{
	LoadFont();
}

void Text::LoadFont()
{
	AssetManager::GetInstance().LoadFont(GameAssets::FONT);

	const sf::Font& font = AssetManager::GetInstance().GetFont(GameAssets::FONT);

	m_Text.setFont(font);
}

void Text::SetText(const std::string& text)
{
	m_Text.setString(text);
}

void Text::SetPosition(const sf::Vector2f& position)
{
	m_Text.setPosition(position);
}

void Text::SetSize(unsigned int size)
{
	m_Text.setCharacterSize(size);
}

void Text::SetOrigin(const sf::Vector2f& origin)
{
	m_Text.setOrigin(origin);
}

void Text::SetColor(const sf::Color& color)
{
	m_Text.setFillColor(color);
}

void Text::Draw(sf::RenderWindow& window) const
{
	window.draw(m_Text);
}

sf::FloatRect Text::GetBound() const
{
	return m_Text.getGlobalBounds();
}