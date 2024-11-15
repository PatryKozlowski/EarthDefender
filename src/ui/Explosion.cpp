#include "ui/Explosion.hpp"

Explosion::Explosion(bool isExplosionByPlayer)
	: Object(AssetSettings::EXPLOSION::TEXTURE_PATH, AssetSettings::EXPLOSION::SCALE, 0.0f, 0.0f),
	m_IsExplosionByPlayer{ isExplosionByPlayer },
	m_Animation{ false, 0.0f, AssetSettings::EXPLOSION::FRAME_DURATION, 0 }
{
	if (IsExplosionByPlayer())
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
	SetElapsedTime(GetElapsedTime() + deltaTime);

	if (GetElapsedTime() >= GetFrameDuration())
	{
		SetElapsedTime(0.0f);

		SetCurrentFrame(GetCurrentFrame() + 1);

		if (GetCurrentFrame() >= AssetSettings::EXPLOSION::FRAME_COUNT)
		{
			SetFinished(true);
		}
		else
		{
			UpdateTextureRect();
		}
	}
}

void Explosion::UpdateTextureRect()
{
	int x = GetCurrentFrame() * AssetSettings::EXPLOSION::FRAME_WIDTH;

	if (IsExplosionByPlayer())
	{
		SetObjectTextureRect(x, AssetSettings::EXPLOSION::DESTROYED::FRAME_END_Y, AssetSettings::EXPLOSION::FRAME_WIDTH, AssetSettings::EXPLOSION::FRAME_HEIGHT);
	}
	else
	{
		SetObjectTextureRect(x, AssetSettings::EXPLOSION::COLLISION::FRAME_END_Y, AssetSettings::EXPLOSION::FRAME_WIDTH, AssetSettings::EXPLOSION::FRAME_HEIGHT);
	}
}