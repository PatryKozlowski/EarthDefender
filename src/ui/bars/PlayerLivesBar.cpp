#include "ui/bars/PlayerLivesBar.hpp"

PlayerLivesBar::PlayerLivesBar()
	: m_Animation{ 1.0f, 0.1f, false }
{
}

void PlayerLivesBar::Draw(sf::RenderWindow& window) const
{
	for (const auto& heart : m_Hearts)
	{
		auto bounds = heart->GetObjectBound();
		heart->SetObjectOrigin(bounds.width / 2, bounds.height / 2);
		heart->Draw(window);
	}
}

void PlayerLivesBar::Update(float deltaTime)
{
	if (IsAnimating())
	{
		SetAnimationSpeed(GetAnimationSpeed() - deltaTime);

		SetScaleFactor(GetScaleFactor() + deltaTime * 1.20f);
		m_Hearts.back()->SetObjectScale(GetScaleFactor(), GetScaleFactor());

		if (GetScaleFactor() >= 1.35f)
		{
			SetAnimation(false);
			SetScaleFactor(1.0f);
			m_Hearts.pop_back();
		}
	}
}

void PlayerLivesBar::SetLife(unsigned int livesCount)
{
	const float heartSpacing = 20.0f;

	if (livesCount < m_Hearts.size())
	{
		StartAnimation();
	}
	else
	{
		m_Hearts.clear();

		for (unsigned int i = 0; i < livesCount; ++i)
		{
			auto heart = std::make_unique<Heart>();
			heart->SetObjectPosition(AssetSettings::HEART::X_OFFSET + 10 + i * 40, TopBarHUDConfig::BACKGROUND_Y_OFFSET / 2);
			m_Hearts.push_back(std::move(heart));
		}
	}
}

void PlayerLivesBar::StartAnimation()
{
	SetAnimation(true);
}