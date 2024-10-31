#include "Buff.hpp"
#include "GameConfig.hpp"

Buff::Buff(const std::string& pathName, BuffTypeID type, float duration)
	: Object(pathName, 1.5f, 0.0f, 0.0f),
	m_Type{ type },
	m_Duration{ duration },
	m_TimeToCollect{ 5.0f },
	m_Destroyed{ false },
	m_IsActive{ false },
	m_IsCollected{ false },
	m_AnimationScale{ AssetSettings::BUFF::SCALE },
	m_AnimationSpeed{ 0.1f },
	m_IsAnimating{ true }
{
	SetRandomPosition();
}

void Buff::Update(float deltaTime)
{
	m_TimeToCollect -= deltaTime;

	if (IsAnimating())
	{
		UpdateAnimation(deltaTime);

		if (m_TimeToCollect <= 0.0f && !IsActive())
		{
			SetAnimating(false);
			SetToDestroy();
		}
	}

	if (IsActive())
	{
		m_Duration -= deltaTime;

		if (m_Duration <= 0.0f)
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
	m_AnimationScale += m_AnimationSpeed * deltaTime * 2.0f;

	if (m_AnimationScale >= 1.25f || m_AnimationScale <= 1.0f)
	{
		m_AnimationSpeed = -m_AnimationSpeed;
	}

	SetObjectScale(m_AnimationScale, m_AnimationScale);
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
