#pragma once

#include "ui/Text.hpp"
#include "Object.hpp"
#include "GameConfig.hpp"

class StatElement
{
public:
	StatElement(std::shared_ptr<Object> icon);

	virtual void Draw(sf::RenderWindow& window) const;
	void InitStatElement(StatElementID statElementID);
	void SetElementPosition(const sf::Vector2f& iconPosition, const sf::Vector2f& textOffset);
	std::shared_ptr<Object> GetIcon() const { return m_Icon; }

	template <typename T>
	void SetText(T& text) const;

private:
	std::shared_ptr<Object> m_Icon;
	std::unique_ptr<Text> m_Text;
};

template<typename T>
inline void StatElement::SetText(T& text) const
{
	m_Text->SetText(std::to_string(text));
}
