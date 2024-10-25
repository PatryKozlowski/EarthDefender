#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "ui/Text.hpp"
#include "ConfigAssetPath.hpp"

struct WindowConfig
{
    static constexpr unsigned int WIDTH = 800;
    static constexpr unsigned int HEIGHT = 960;
    static constexpr const std::string TITLE = "Earth Defender";
    static constexpr sf::Uint32 STYLE = sf::Style::Titlebar | sf::Style::Close;
    static constexpr float TARGET_FPS = 60.0f;
};

struct GameConfig
{
    static constexpr float GAME_TIME = 11.0f;
    static constexpr unsigned int INIT_PLAYER_LIFE = 3;
};

struct GameAssets
{
    static const std::string FONT;
};

struct AssetSettings
{
    struct EARTH
    {
        static const std::string TEXTURE_PATH;
        static constexpr float SCALE = 1.05f;
        static constexpr float Y_OFFSET = 50.0f;
    };

    struct HEART
    {
        static const std::string TEXTURE_PATH;
        static constexpr float SCALE = 1.05f;
        static constexpr unsigned int SPACE_BETWEEN = 40;
        static constexpr float X_OFFSET = 10.0f;
        static constexpr float Y_OFFSET = 10.0f;
    };

    struct TIME_TEXT
    {
        static const std::string TEXTURE_PATH;
        static constexpr float SCALE = 1.05f;
        static constexpr float X_OFFSET = 10.0f;
        static constexpr float Y_OFFSET = 10.0f;
    };

    struct COIN
    {
        static const std::string TEXTURE_PATH;
        static constexpr float SCALE = 1.0f;
        static constexpr float X_OFFSET = 10.0f;
        static constexpr float Y_OFFSET = 10.0f;
    };
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
    static constexpr const std::string TITLE = "> Earth Defender <";
    static constexpr const std::string TITLE_END_GAME = "> End Game <";
    static constexpr const std::string TITLE_GAME_OVER = "> Game Over <";
    static constexpr unsigned int TITLE_SIZE = 50;
    static const sf::Color TITLE_COLOR;
    static constexpr float TITLE_Y = 200.0f;

    static constexpr const std::string START_GAME = "Start Game";
    static constexpr const std::string PLAY_AGAIN = "Play Again";
    static constexpr const std::string EXIT = "Exit";
    static constexpr unsigned int OPTION_SIZE = 30;
    static const sf::Color OPTION_COLOR;
    static const sf::Color OPTION_HIGHLIGHT_COLOR;
    static constexpr float OPTION_Y = 300.0f;
    static constexpr float OPTION_Y_OFFSET = 50.0f;
};

struct GamePlayHUDConfig
{
    static const sf::Color TEXT_COLOR;
    static constexpr unsigned int TEXT_SIZE = 36;
    static const sf::Color BACKGROUND_COLOR;
    static constexpr float BACKGROUND_Y_OFFSET = 50.0f;
};
