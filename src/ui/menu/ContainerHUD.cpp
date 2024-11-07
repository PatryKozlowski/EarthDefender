#include "ui/menu/ContainerHUD.hpp"

ContainerHUD::ContainerHUD()
{
	InitContainer();
}

void ContainerHUD::Draw(sf::RenderWindow& window)
{
	window.draw(m_Container);
}

void ContainerHUD::InitContainer()
{
	m_Container.setSize(sf::Vector2f(Container::WIDTH, Container::HEIGHT));
	m_Container.setFillColor(sf::Color::Transparent);
	m_Container.setPosition(sf::Vector2f((WindowConfig::WIDTH - GetContainerGlobalBounds().width) / 2, (WindowConfig::HEIGHT - GetContainerGlobalBounds().height) / 2));
}
