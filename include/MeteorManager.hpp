#pragma once

#include "Meteor.hpp"
#include <vector>
#include "Player.hpp"
#include "GameConfig.hpp"
#include "ui/Earth.hpp"

class MeteorManager
{
public:
	MeteorManager(sf::RenderWindow& window, Player& m_Player);
	void SpawnMeteor();
	void Update(float deltaTime);
	void DrawMeteors(sf::RenderWindow& window) const;
	void HandleClick(sf::Vector2i& mousePosition);
	void SetMeteorTypes(const std::vector<MeteorData>& meteorTypes);
	void CheckCollisions();
	void ClearMeteors();
	void IncrementScore(unsigned int meteorScore);
	void DecreaseHealth(unsigned int meteorDamage);

private:
	sf::RenderWindow& m_Window;
	std::vector<std::unique_ptr<Meteor>> m_Meteors;
	std::vector<MeteorData> m_MeteorTypes;
	Player& m_Player;

	bool IsCollision(const Meteor& meteor, const Earth& earth);
};