#include "Buff.hpp"

Buff::Buff(const std::string& pathName, BuffTypeID type, float duration)
	: Object(pathName, AssetSettings::BUFF::SCALE, 0.0f, 0.0f),
	m_Type{ type },
	m_Duration{ duration },
	m_TimeToCollect{ AssetSettings::BUFF::TIME_TO_COLLECT },
	m_Destroyed{ false },
	m_IsActive{ false },
	m_IsCollected{ false },
	m_Animation{ AssetSettings::BUFF::SCALE, 0.1f, true }
{
	SetRandomPosition();
}

void Buff::Update(float deltaTime)
{
	SetTimeToCollect(GetTimeToCollect() - deltaTime);

	if (IsAnimating())
	{
		UpdateAnimation(deltaTime);

		if (GetTimeToCollect() <= 0.0f && !IsActive())
		{
			SetAnimating(false);
			SetToDestroy();
		}
	}

	if (IsActive())
	{
		SetDuration(GetDuration() - deltaTime);

		if (GetDuration() <= 0.0f)
		{
			SetActive(false);
			SetToDestroy();
		}
	}
}

void Buff::Draw(sf::RenderWindow& window) const
{
	if (!IsCollected())
	{
		Object::Draw(window);
	}
}

void Buff::UpdateAnimation(float deltaTime)
{
	SetAnimationScale(GetAnimationScale() + GetAnimationSpeed() * deltaTime * 2.0f);

	if (GetAnimationScale() >= 1.25f || GetAnimationScale() <= AssetSettings::BUFF::SCALE)
	{
		SetAnimationSpeed(-GetAnimationSpeed());
	}

	SetObjectScale(GetAnimationScale(), GetAnimationScale());
}

void Buff::SetRandomPosition()
{
	unsigned int buffIconRadius = static_cast<unsigned int>(GetObjectBound().width / 2);

	unsigned int xPosition = static_cast<unsigned int>(rand()) % (WindowConfig::WIDTH - buffIconRadius * 2);

	float minYPosition = TopBarHUDConfig::BACKGROUND_Y_OFFSET + 25.0f;
	float maxYPosition = 630.0f;

	float yPosition = static_cast<unsigned int>(rand()) % static_cast<unsigned int>(maxYPosition - minYPosition) + minYPosition;

	SetObjectPosition(static_cast<float>(xPosition), static_cast<float>(yPosition));
}
