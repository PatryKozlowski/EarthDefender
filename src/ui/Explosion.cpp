#include "ui/Explosion.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"
#include <iostream>

Explosion::Explosion(bool isMeteorExplosion)
	: m_IsMeteorExplosion(isMeteorExplosion),
	m_IsFinished{ false },
	m_ElapsedTime{ 0.0f },
	m_FrameDuration(AssetSettings::EXPLOSION::FRAME_DURATION),
	m_CurrentFrame{ 0 }
{
	const sf::Texture& texture = AssetManager::GetInstance().GetTexture(AssetSettings::EXPLOSION::TEXTURE_PATH);
	m_Sprite.setTexture(texture);

	if (m_IsMeteorExplosion)
	{
		m_Sprite.setTextureRect(sf::IntRect(0, 64, 64, 64));
	}
	else
	{
		m_Sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	}
}

void Explosion::Update(float deltaTime)
{
	m_ElapsedTime += deltaTime;

	if (m_ElapsedTime >= m_FrameDuration)
	{
		m_ElapsedTime = 0.0f;
		m_CurrentFrame++;

		if (m_IsMeteorExplosion)
		{
			if (m_CurrentFrame < 3)
			{
				int x = m_CurrentFrame * 64;
				m_Sprite.setTextureRect(sf::IntRect(x, 64, 64, 64));
			}
			else
			{
				m_IsFinished = true;
			}
		}
		else {
			if (m_CurrentFrame < 3)
			{
				int x = m_CurrentFrame * 64;

				m_Sprite.setTextureRect(sf::IntRect(x, 0, 64, 64));
			}
			else
			{
				m_IsFinished = true;
			}
		}
	}
}

void Explosion::Draw(sf::RenderWindow& window)
{

	window.draw(m_Sprite);
}

bool Explosion::IsFinished() const
{
	return m_IsFinished;
}

void Explosion::SetPosition(const sf::Vector2f& position)
{
	m_Sprite.setPosition(position);
}
