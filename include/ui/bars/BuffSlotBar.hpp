#pragma once

#include "ui/StatElement.hpp"
#include "ui/icons/Coin.hpp"

class BuffSlotBar
{
public:
	BuffSlotBar();

	void Draw(sf::RenderWindow& window) const;
	void InitSlot();
	void Update(float deltaTime);
	void SetBuffSlot(const BuffTypeID& buffType);
	void RemoveBuffIcon();

	template <typename T>
	void SetBuffIcon(std::unique_ptr<T> icon);

private:
	sf::CircleShape m_Slot;
	std::unique_ptr<Object> m_Icon;
};

template <typename T>
inline void BuffSlotBar::SetBuffIcon(std::unique_ptr<T> icon)
{
	m_Icon = std::move(icon);

	m_Icon->SetObjectOrigin(m_Icon->GetObjectBound().width / 2, m_Icon->GetObjectBound().height / 2);
	m_Icon->SetObjectPosition(250.0f, TopBarHUDConfig::BACKGROUND_Y_OFFSET / 2);
	m_Icon->SetObjectScale(0.75f, 0.75f);
}