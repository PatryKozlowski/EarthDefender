#include "ui/StatElement.hpp"
#include "GameConfig.hpp"

StatElement::StatElement(std::shared_ptr<Object> icon)
	: m_Icon{ std::move(icon) },
	m_Text{ std::make_unique<Text>() }
{
	auto bounds = m_Icon->GetObjectBound();
	m_Icon->SetObjectOrigin(bounds.width / 2.0f, bounds.height / 2.0f);

	m_Text->SetSize(TopBarHUDConfig::TEXT_SIZE);
	m_Text->SetColor(TopBarHUDConfig::TEXT_COLOR);
	m_Text->SetOrigin(sf::Vector2f(m_Text->GetBound().width / 2.0f, m_Text->GetBound().height / 2.0f));

}

void StatElement::Draw(sf::RenderWindow& window) const
{
	m_Icon->Draw(window);
	m_Text->Draw(window);
}

void StatElement::InitStatElement(StatElementID statElementID)
{
	const auto iconWidth = m_Icon->GetObjectBound().width;
	const auto iconHeight = m_Icon->GetObjectBound().height;

	switch (statElementID)
	{
	case StatElementID::PLAYER_SCORE_BAR:
		SetElementPosition(
			{ WindowConfig::WIDTH - iconWidth - 90.0f,  TopBarHUDConfig::BACKGROUND_Y_OFFSET / 2 },
			{ WindowConfig::WIDTH - iconWidth / 2 - 75.0f, 2.25f });
		break;

	case StatElementID::GAME_TIME_BAR:
		SetElementPosition(
			{ WindowConfig::WIDTH / 2,  TopBarHUDConfig::BACKGROUND_Y_OFFSET / 2 },
			{ WindowConfig::WIDTH / 2 + iconWidth, 2.25f });
		break;

	default:
		break;
	}
}

void StatElement::SetElementPosition(const sf::Vector2f& iconPosition, const sf::Vector2f& textOffset)
{
	m_Icon->SetObjectPosition(iconPosition.x, iconPosition.y);
	m_Text->SetPosition(textOffset);
}

