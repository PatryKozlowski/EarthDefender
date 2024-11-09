#include "ui/menu/MenuHUD.hpp"

MenuHUD::MenuHUD(ApplicationState& applicationState)
	: m_ApplicationState{ applicationState }
{
	InitTitle();
	InitOptions();
}

void MenuHUD::Draw(sf::RenderWindow& window)
{
	DrawTitle(window);

	DrawOptions(window);

	DrawContainer(window);
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

void MenuHUD::InitOptions()
{
	auto currentState = m_ApplicationState.GetCurrentState();
	auto mainOption = currentState == GameStateID::MENU ? MenuConfig::START_GAME : MenuConfig::PLAY_AGAIN;
	auto options = std::vector<std::string>{ mainOption, MenuConfig::EXIT };

	float yOffset = 300.0f;

	for (const auto& label : options)
	{
		m_Options.push_back({ label, Text() });

		auto& option = m_Options.back();

		option.text.SetText(option.label);
		option.text.SetSize(MenuConfig::OPTION_SIZE);
		option.text.SetColor(MenuConfig::OPTION_COLOR);
		option.text.SetPosition(sf::Vector2f(m_Container.GetContainerPosition().x + (m_Container.GetContainerGlobalBounds().width - option.text.GetBound().width) / 2, yOffset));
		yOffset += 50.0f;
	}
}

void MenuHUD::InitTitle()
{
	switch (m_ApplicationState.GetCurrentState())
	{
	case GameStateID::MENU:
		m_Text.SetText(MenuConfig::TITLE);
		break;

	case GameStateID::END_GAME:
		m_Text.SetText(MenuConfig::TITLE_END_GAME);
		break;

	case GameStateID::GAME_OVER:
		m_Text.SetText(MenuConfig::TITLE_GAME_OVER);
		break;

	default:
		break;
	}

	m_Text.SetSize(42);
	m_Text.SetPosition(sf::Vector2f(m_Container.GetContainerPosition().x + (m_Container.GetContainerGlobalBounds().width - m_Text.GetBound().width) / 2, 200.0f));
}

void MenuHUD::DrawOptions(sf::RenderWindow& window)
{
	for (const auto& option : m_Options)
	{
		option.text.Draw(window);
	}
}

void MenuHUD::DrawContainer(sf::RenderWindow& window)
{
	m_Container.Draw(window);
}

void MenuHUD::DrawTitle(sf::RenderWindow& window)
{
	m_Text.Draw(window);
}

void MenuHUD::HandleMouseMove(float x, float y)
{
	for (auto& option : m_Options)
	{
		if (option.text.GetBound().contains(x, y))
		{
			option.text.SetColor(MenuConfig::OPTION_HIGHLIGHT_COLOR);
		}
		else
		{
			option.text.SetColor(MenuConfig::OPTION_COLOR);
		}
	}
}

void MenuHUD::HandleMouseClick(float x, float y)
{
	for (const auto& option : m_Options)
	{
		if (option.text.GetBound().contains(x, y))
		{
			OnOptionClick(option.label);
		}
	}
}

void MenuHUD::OnOptionClick(const std::string& label)
{
	if (label == MenuConfig::START_GAME)
	{
		m_ApplicationState.SetCurrentState(GameStateID::PLAYING);
	}

	if (label == MenuConfig::PLAY_AGAIN)
	{
		m_ApplicationState.SetCurrentState(GameStateID::RESTART);
	}

	if (label == MenuConfig::EXIT)
	{
		m_ApplicationState.SetCurrentState(GameStateID::EXIT);
	}
}
