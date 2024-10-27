#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "ui/Text.hpp"
#include "ConfigAssetPath.hpp"

struct WindowConfig
{
	static constexpr unsigned int WIDTH = 800;
	static constexpr unsigned int HEIGHT = 960;
	static constexpr const char* TITLE = "Earth Defender";
	static constexpr sf::Uint32 STYLE = sf::Style::Titlebar | sf::Style::Close;
	static constexpr float TARGET_FPS = 60.0f;
};

struct GameConfig
{
	static constexpr float GAME_TIME = 61.0f;
	static constexpr float METEOR_SPAWN_INTERVAL = 1.0f;
	static constexpr unsigned int INIT_HEALTH = 3;
	static constexpr unsigned int INIT_SCORE = 0;
};

struct GameAssets
{
	static const std::string FONT;
};

struct MeteorData
{
	std::string texturePath;
	int health;
	float speed;
	unsigned int damage;
	unsigned int score;
};

struct AssetSettings
{
	struct EXPLOSION
	{
		static const std::string TEXTURE_PATH;
		static constexpr float SCALE = 1.0f;
		static constexpr float FRAME_DURATION = 0.1f;
	};

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

	struct METEOR
	{
		static constexpr float SCALE = 0.1f;
		static const std::vector<MeteorData> METEOR_TYPES;

		struct SMALL
		{
			static const std::string TEXTURE_PATH;
			static constexpr int HEALTH = 1;
			static constexpr float SPEED = 70.0f;
			static const unsigned int DAMAGE = 1;
			static constexpr unsigned int SCORE = 1;
		};

		struct MEDIUM
		{
			static const std::string TEXTURE_PATH;
			static constexpr int HEALTH = 2;
			static constexpr float SPEED = 100.0f;
			static const unsigned int DAMAGE = 2;
			static constexpr unsigned int SCORE = 2;
		};

		struct LARGE
		{
			static const std::string TEXTURE_PATH;
			static constexpr int HEALTH = 3;
			static constexpr float SPEED = 150.0f;
			static const unsigned int DAMAGE = 3;
			static constexpr unsigned int SCORE = 3;
		};
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
	static constexpr const char* TITLE = "> Earth Defender <";
	static constexpr const char* TITLE_END_GAME = "> End Game <";
	static constexpr const char* TITLE_GAME_OVER = "> Game Over <";
	static constexpr unsigned int TITLE_SIZE = 50;
	static const sf::Color TITLE_COLOR;
	static constexpr float TITLE_Y = 200.0f;

	static constexpr const char* START_GAME = "Start Game";
	static constexpr const char* PLAY_AGAIN = "Play Again";
	static constexpr const char* EXIT = "Exit";
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
