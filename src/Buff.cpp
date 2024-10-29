#include "Buff.hpp"

Buff::Buff(BuffTypeID type, float duration)
	: Object("sad", 0, 0, 0),
	m_Type{ type },
	m_Duration{ duration },
	m_Destroyed{ false },
	m_IsActive{ false }
{
}

void Buff::Update(float deltaTime)
{
	if (m_IsActive)
	{
		m_Duration -= deltaTime;
		if (m_Duration <= 0.0f)
		{
			m_IsActive = false;
		}
	}
}

void Buff::Draw(sf::RenderWindow& window) const
{
}

//void Buff::ApplyEffect(Game& game)
//{
//	switch (m_Type)
//	{
//	case BuffTypeID::DOUBLE_DAMAGE:
//		// to do
//		break;
//
//	default:
//		break;
//	}
//}

bool Buff::IsClicked(const sf::Vector2i& mousePosition) const
{
	return false;
}

void Buff::SetRandomPosition()
{
	unsigned int buffIconRadius = static_cast<unsigned int>(GetObjectBound().width / 2);
	unsigned int xPosition = static_cast<unsigned int>(rand()) % (WindowConfig::WIDTH - buffIconRadius * 2);
	unsigned int yPosition = static_cast<unsigned int>(rand()) % (WindowConfig::HEIGHT - buffIconRadius * 2);

	float yPossitionOffset = (TopBarHUDConfig::BACKGROUND_Y_OFFSET + 5.0f);

	SetObjectPosition(static_cast<float>(xPosition), static_cast<float>(yPosition - yPossitionOffset));
}
