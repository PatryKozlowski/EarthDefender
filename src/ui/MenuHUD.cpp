#include "ui/MenuHUD.hpp"
#include "AssetManager.hpp"

MenuHUD::MenuHUD(sf::RenderWindow &window)
    : m_Window(window), m_Title(std::make_unique<Text>())
{
}

void MenuHUD::HandleInput(const sf::Event &event)
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
    for (auto &option : m_Options)
    {
        if (option.text->GetBound().contains(x, y))
        {
            option.text->SetColor(m_Config.OPTION_HIGHLIGHT_COLOR);
        }
        else
        {
            option.text->SetColor(m_Config.OPTION_COLOR);
        }
    }
}

void MenuHUD::HandleMouseClick(float x, float y)
{
    for (const auto &option : m_Options)
    {
        if (option.text->GetBound().contains(x, y))
        {
            OnOptionClick(option.label);
        }
    }
}

void MenuHUD::AddOption(const std::string &label)
{
    m_Options.push_back({label, std::make_unique<Text>()});
}

void MenuHUD::Draw()
{
    DrawMenuTitle(m_Window);

    for (const auto &option : m_Options)
    {
        option.text->Draw(m_Window);
    }
}

void MenuHUD::InitOptions(const std::vector<std::string> &options)
{
    float yOffset = m_Config.OPTION_Y;

    for (const auto &label : options)
    {
        AddOption(label);

        auto &option = m_Options.back();
        option.text->SetText(option.label);
        option.text->SetSize(m_Config.OPTION_SIZE);
        option.text->SetColor(m_Config.OPTION_COLOR);
        option.text->SetPosition(sf::Vector2f(m_Window.getSize().x / 2 - option.text->GetBound().width / 2, yOffset));
        yOffset += m_Config.OPTION_Y_OFFSET;
    }
}

void MenuHUD::DrawMenuTitle(sf::RenderWindow &window)
{
    m_Title->SetText(m_Config.TITLE);
    m_Title->SetSize(m_Config.TITLE_SIZE);
    m_Title->SetColor(m_Config.TITLE_COLOR);
    m_Title->SetPosition(sf::Vector2f(window.getSize().x / 2 - m_Title->GetBound().width / 2, m_Config.TITLE_Y));
    m_Title->Draw(window);
}

void MenuHUD::OnOptionClick([[maybe_unused]] const std::string &label)
{
}