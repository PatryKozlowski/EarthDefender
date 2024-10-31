#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "GameTimeBar.hpp"
#include "PlayerScoreBar.hpp"
#include "PlayerLifesBar.hpp"
#include "BuffSlotBar.hpp"

class TopBarHUD
{
public:
	TopBarHUD(sf::RenderWindow& window);

	void Draw() const;
	void Update(const float deltaTime);
	void SetGameTime(const float& time) const;
	void SetPlayerScore(const unsigned int& score);
	void SetPlayerLife(const unsigned int& playerLives);
	void SetBuffSlot(const BuffTypeID& buffType) const;

private:
	sf::RenderWindow& m_Window;
	std::unique_ptr<GameTimeBar> m_GameTimeBar;
	std::unique_ptr<PlayerScoreBar> m_PlayerScoreBar;
	std::unique_ptr<PlayerLifesBar> m_PlayerLifesBar;
	std::unique_ptr<BuffSlotBar> m_BuffSlotBar;

	void InitTopBarHUD();
};
