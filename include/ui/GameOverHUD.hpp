#pragma once

#include "ui/Hud.hpp"

struct GameOverOption
{
    std::string label;
    sf::Text text;
};

struct GameOverConfig
{
    const std::string GAME_OVER_TEXT = "Game Over!";
    const unsigned int GAME_OVER_TEXT_SIZE = 50;
    const sf::Color GAME_OVER_TEXT_COLOR = sf::Color::White;
    const float GAME_OVER_TEXT_Y = 200.0f;

    const std::string RESTART_GAME = "Restart Game";
    const std::string EXIT = "Exit";
    const unsigned int OPTION_SIZE = 30;
    const sf::Color OPTION_COLOR = sf::Color::White;
    const sf::Color OPTION_HIGHLIGHT_COLOR = sf::Color::Magenta;
    const float OPTION_Y = 300.0f;
    const float OPTION_Y_OFFSET = 50.0f;
};

class GameOverHUD : public Hud
{
public:
    GameOverHUD(sf::RenderWindow &window);
    virtual ~GameOverHUD() = default;

    void Draw() override;
    void HandleInput(const sf::Event &event) override;
    bool IsRestartGame() const;
    bool IsExitGame() const;

private:
    sf::Text m_GameOverText;
    std::vector<GameOverOption> m_Options;
    GameOverConfig m_Config;
    bool m_RestartGame = false;
    bool m_ExitGame = false;

    void InitGameOverHUD();
};