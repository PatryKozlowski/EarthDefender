#include "ui/MenuHUD.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"
#include <iostream>

MenuHUD::MenuHUD(sf::RenderWindow& window)
	: m_Window{ window },
	m_Title{ std::make_unique<Text>() }
{
}

void MenuHUD::HandleInput(const sf::Event& event)
{
	if (event.type == sf::Event::MouseMoved)
	{
		HandleMouseMove(event.mouseMove.x, event.mouseMove.y);
	}

	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		HandleMouseClick(event.mouseButton.x, event.mouseButton.y);
	}
}

void MenuHUD::HandleMouseMove(float x, float y) const
{
	for (auto& option : m_Options)
	{
		if (option.text->GetBound().contains(x, y))
		{
			option.text->SetColor(MenuConfig::OPTION_HIGHLIGHT_COLOR);
		}
		else
		{
			option.text->SetColor(MenuConfig::OPTION_COLOR);
		}
	}
}

void MenuHUD::HandleMouseClick(float x, float y)
{
	for (const auto& option : m_Options)
	{
		if (option.text->GetBound().contains(x, y))
		{
			OnOptionClick(option.label);
		}
	}
}

void MenuHUD::AddOption(const std::string& label)
{
	m_Options.push_back({ label, std::make_unique<Text>() });
}

void MenuHUD::Draw()
{
	DrawMenuTitle(m_Window);

	for (const auto& option : m_Options)
	{
		option.text->Draw(m_Window);
	}
}

void MenuHUD::InitOptions(const std::vector<std::string>& options)
{
	float yOffset = MenuConfig::OPTION_Y;

	for (const auto& label : options)
	{
		AddOption(label);

		auto& option = m_Options.back();
		option.text->SetText(option.label);
		option.text->SetSize(MenuConfig::OPTION_SIZE);
		option.text->SetColor(MenuConfig::OPTION_COLOR);
		option.text->SetPosition(sf::Vector2f(m_Window.getSize().x / 2 - option.text->GetBound().width / 2, yOffset));
		yOffset += MenuConfig::OPTION_Y_OFFSET;
	}
}

void MenuHUD::DrawMenuTitle(sf::RenderWindow& window)
{
	m_Title->SetText(MenuConfig::TITLE);
	m_Title->SetSize(MenuConfig::TITLE_SIZE);
	m_Title->SetColor(MenuConfig::TITLE_COLOR);
	m_Title->SetPosition(sf::Vector2f(window.getSize().x / 2 - m_Title->GetBound().width / 2, MenuConfig::TITLE_Y));
	m_Title->Draw(window);
}

void MenuHUD::OnOptionClick([[maybe_unused]] const std::string& label)
{
}