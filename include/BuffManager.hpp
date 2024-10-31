#pragma once

#include "Buff.hpp"
#include "Affect.hpp"
#include "GameConfig.hpp"
#include <memory>

class BuffManager
{
public:
	BuffManager(sf::RenderWindow& window, Player& player, Affect& affect);

	void Update(float deltaTime);
	void DrawBuffs(sf::RenderWindow& window) const;
	void SpawnBuff();
	void SetBuffTypes(const std::vector<BuffData>& buffTypes);
	void HandleClick(sf::Vector2i& mousePosition);
	void ClearBuffs();

private:
	sf::RenderWindow& m_Window;
	std::vector<std::unique_ptr<Buff>> m_Buffs;
	std::vector<BuffData> m_BuffTypes;
	Player& m_Player;
	Affect& m_Affect;
};