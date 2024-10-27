#include "ui/Explosion.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"

Explosion::Explosion(bool isExplosionByPlayer)
	: Object(AssetSettings::EXPLOSION::TEXTURE_PATH, AssetSettings::EXPLOSION::SCALE, 0.0f, 0.0f),
	m_IsExplosionByPlayer{ isExplosionByPlayer },
	m_IsFinished{ false },
	m_ElapsedTime{ 0.0f },
	m_FrameDuration{ AssetSettings::EXPLOSION::FRAME_DURATION },
	m_CurrentFrame{ 0 }
{
	if (m_IsExplosionByPlayer)
	{
		SetObjectTextureRect(AssetSettings::EXPLOSION::DESTROYED::FRAME_START_X, AssetSettings::EXPLOSION::DESTROYED::FRAME_END_Y, AssetSettings::EXPLOSION::FRAME_WIDTH, AssetSettings::EXPLOSION::FRAME_HEIGHT);
	}
	else
	{
		SetObjectTextureRect(AssetSettings::EXPLOSION::COLLISION::FRAME_START_X, AssetSettings::EXPLOSION::COLLISION::FRAME_END_Y, AssetSettings::EXPLOSION::FRAME_WIDTH, AssetSettings::EXPLOSION::FRAME_HEIGHT);
	}
}

void Explosion::Update(float deltaTime)
{
	m_ElapsedTime += deltaTime;

	if (m_ElapsedTime >= m_FrameDuration)
	{
		m_ElapsedTime = 0.0f;
		m_CurrentFrame++;

		if (m_CurrentFrame >= AssetSettings::EXPLOSION::FRAME_COUNT)
		{
			m_IsFinished = true;
		}
		else
		{
			UpdateTextureRect();
		}
	}
}


void Explosion::Draw(sf::RenderWindow& window) const
{
	Object::Draw(window);
}

bool Explosion::IsFinished() const
{
	return m_IsFinished;
}

void Explosion::UpdateTextureRect()
{
	int x = m_CurrentFrame * AssetSettings::EXPLOSION::FRAME_WIDTH;

	if (m_IsExplosionByPlayer)
	{
		SetObjectTextureRect(x, AssetSettings::EXPLOSION::DESTROYED::FRAME_END_Y, AssetSettings::EXPLOSION::FRAME_WIDTH, AssetSettings::EXPLOSION::FRAME_HEIGHT);
	}
	else
	{
		SetObjectTextureRect(x, AssetSettings::EXPLOSION::COLLISION::FRAME_END_Y, AssetSettings::EXPLOSION::FRAME_WIDTH, AssetSettings::EXPLOSION::FRAME_HEIGHT);
	}
}