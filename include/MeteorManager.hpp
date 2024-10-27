#pragma once

#include "Meteor.hpp"
#include <vector>
#include "Earth.hpp"
#include "GameConfig.hpp"
#include "ui/GamePlayHUD.hpp"

class MeteorManager
{
public:
	MeteorManager(sf::RenderWindow& window);
	void SpawnMeteor();
	void Update(float deltaTime);
	void DrawMeteors(sf::RenderWindow& window) const;
	void HandleClick(sf::Vector2i& mousePosition, unsigned int& playerScore);
	void SetMeteorTypes(const std::vector<MeteorData>& meteorTypes);
	void CheckCollisions(const Earth& earth, unsigned int& playerLife);
	void ClearMeteors();


private:
	sf::RenderWindow& m_Window;
	std::vector<std::unique_ptr<Meteor>> m_Meteors;
	std::vector<MeteorData> m_MeteorTypes;

	bool IsCollision(const Meteor& meteor, const Earth& earth);
};