#include "ui/bars/BuffSlotBar.hpp"

BuffSlotBar::BuffSlotBar()
{
	InitSlot();
}

void BuffSlotBar::Draw(sf::RenderWindow& window) const
{
	window.draw(m_Slot);

	if (m_Icon)
	{
		m_Icon->Draw(window);
	}
}

void BuffSlotBar::InitSlot()
{
	m_Slot.setRadius(16);
	m_Slot.setFillColor(sf::Color::Black);
	m_Slot.setOutlineThickness(1);
	m_Slot.setOutlineColor(sf::Color::Yellow);
	m_Slot.setOrigin(m_Slot.getRadius(), m_Slot.getRadius());
	m_Slot.setPosition(250.0f, TopBarHUDConfig::BACKGROUND_Y_OFFSET / 2);
}

void BuffSlotBar::SetBuffSlot(const BuffTypeID& buffType)
{
	switch (buffType)
	{
	case BuffTypeID::DOUBLE_DAMAGE:
		SetBuffIcon(std::make_unique<DoubleDamage>());
		break;

	case BuffTypeID::DOUBLE_SCORE:
		SetBuffIcon(std::make_unique<DoubleScore>());
		break;

	case BuffTypeID::INVINCIBILITY:
		SetBuffIcon(std::make_unique<ShieldBuff>());
		break;

	case BuffTypeID::SLOW_METEOR_SPEED:
		SetBuffIcon(std::make_unique<SlowClock>());
		break;

	default:
		RemoveBuffIcon();
		break;
	}
}

void BuffSlotBar::RemoveBuffIcon()
{
	if (m_Icon)
	{
		m_Icon.reset();
	}
}

