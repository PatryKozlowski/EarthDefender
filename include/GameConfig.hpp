#pragma once

#include <string>
#include <SFML/Graphics.hpp>

struct WindowConfig
{
    const unsigned int WIDTH = 800;
    const unsigned int HEIGHT = 960;
    const std::string TITLE = "Earth Defender";
    const sf::Uint32 STYLE = sf::Style::Titlebar | sf::Style::Close;
    const float TARGET_FPS = 60.0f;
};

inline WindowConfig g_WindowConfig;

enum class GameState
{
    MENU,
    PLAYING,
    GAME_OVER,
    EXIT
};

struct GameConfig
{
    const float GAME_TIME = 11.0f;
};

inline GameConfig g_GameConfig;

struct GameAssets
{
    const std::string FONT = "/Users/patrykkozlowski/Desktop/Projekty/EarthDefender/assets/font.ttf";
};

inline GameAssets g_GameAssets;