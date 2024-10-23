#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "ui/Text.hpp"
#include "ConfigAssetPath.hpp"

struct WindowConfig
{
    const unsigned int WIDTH = 800;
    const unsigned int HEIGHT = 960;
    const std::string TITLE = "Earth Defender";
    const sf::Uint32 STYLE = sf::Style::Titlebar | sf::Style::Close;
    const float TARGET_FPS = 60.0f;
};

struct GameConfig
{
    const float GAME_TIME = 11.0f;
};

struct GameAssets
{
    const std::string FONT = GetResourceDir() + "/font.ttf";
};

enum class GameState
{
    MENU,
    PLAYING,
    END_GAME,
    GAME_OVER,
    EXIT
};

struct MenuOption
{
    std::string label;
    std::unique_ptr<Text> text;
};

struct MenuConfig
{
    const std::string TITLE = "> Earth Defender <";
    const std::string TITLE_END_GAME = "> End Game <";
    const std::string TITLE_GAME_OVER = "> Game Over <";
    const unsigned int TITLE_SIZE = 50;
    const sf::Color TITLE_COLOR = sf::Color::White;
    const float TITLE_Y = 200.0f;

    const std::string START_GAME = "Start Game";
    const std::string PLAY_AGAIN = "Play Again";
    const std::string EXIT = "Exit";
    const unsigned int OPTION_SIZE = 30;
    const sf::Color OPTION_COLOR = sf::Color::White;
    const sf::Color OPTION_HIGHLIGHT_COLOR = sf::Color::Magenta;
    const float OPTION_Y = 300.0f;
    const float OPTION_Y_OFFSET = 50.0f;
};

inline WindowConfig g_WindowConfig;
inline GameConfig g_GameConfig;
inline GameAssets g_GameAssets;