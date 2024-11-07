#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "GameTimeBar.hpp"
#include "PlayerScoreBar.hpp"
#include "PlayerLivesBar.hpp"
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
	GameTimeBar m_GameTimeBar;
	PlayerScoreBar m_PlayerScoreBar;
	PlayerLivesBar m_PlayerLivesBar;
	std::unique_ptr <BuffSlotBar> m_BuffSlotBar;

	void InitTopBarHUD();
};
