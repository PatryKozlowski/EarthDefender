#pragma once

#include "Hud.hpp"

struct MenuOption
{
    std::string label;
    sf::Text text;
};

struct MainMenuConfig
{
    const std::string TITLE = "> Earth Defender <";
    const unsigned int TITLE_SIZE = 50;
    const sf::Color TITLE_COLOR = sf::Color::White;
    const float TITLE_Y = 200.0f;

    const std::string START_GAME = "Start Game";
    const std::string EXIT = "Exit";
    const unsigned int OPTION_SIZE = 30;
    const sf::Color OPTION_COLOR = sf::Color::White;
    const sf::Color OPTION_HIGHLIGHT_COLOR = sf::Color::Magenta;
    const float OPTION_Y = 300.0f;
    const float OPTION_Y_OFFSET = 50.0f;
};

class MainMenuHUD : public Hud
{
public:
    MainMenuHUD(sf::RenderWindow &window);
    virtual ~MainMenuHUD() = default;
    bool IsStartGame() const;
    bool IsExitGame() const;

    void HandleInput(const sf::Event &event) override;
    void Draw() override;

private:
    std::vector<MenuOption> m_Options;
    MainMenuConfig m_Config;
    sf::Text m_Title;
    bool m_StartGame = false;
    bool m_ExitGame = false;

    void InitMenu();
};