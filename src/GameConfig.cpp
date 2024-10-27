#include "GameConfig.hpp"
#include <vector>

const sf::Color WHITE = sf::Color(255, 255, 255);
const sf::Color MAGENTA = sf::Color(255, 0, 255);
const sf::Color GRAY = sf::Color(128, 128, 128);

const std::string GameAssets::FONT = GetResourceDir() + "/font.ttf";

const std::string AssetSettings::EXPLOSION::TEXTURE_PATH = GetResourceDir() + "explosion.png";
const std::string AssetSettings::EARTH::TEXTURE_PATH = GetResourceDir() + "earth.png";
const std::string AssetSettings::HEART::TEXTURE_PATH = GetResourceDir() + "heart.png";
const std::string AssetSettings::TIME_TEXT::TEXTURE_PATH = GetResourceDir() + "clock.png";
const std::string AssetSettings::COIN::TEXTURE_PATH = GetResourceDir() + "coin.png";
const std::string AssetSettings::METEOR::SMALL::TEXTURE_PATH = GetResourceDir() + "meteor_small.png";
const std::string AssetSettings::METEOR::MEDIUM::TEXTURE_PATH = GetResourceDir() + "meteor_medium.png";
const std::string AssetSettings::METEOR::LARGE::TEXTURE_PATH = GetResourceDir() + "meteor_large.png";

const sf::Color MenuConfig::TITLE_COLOR = WHITE;
const sf::Color MenuConfig::OPTION_COLOR = WHITE;
const sf::Color MenuConfig::OPTION_HIGHLIGHT_COLOR = MAGENTA;

const sf::Color GamePlayHUDConfig::TEXT_COLOR = WHITE;
const sf::Color GamePlayHUDConfig::BACKGROUND_COLOR = GRAY;

const std::vector<MeteorData> AssetSettings::METEOR::METEOR_TYPES = {
	{AssetSettings::METEOR::SMALL::TEXTURE_PATH, AssetSettings::METEOR::SMALL::HEALTH, AssetSettings::METEOR::SMALL::SPEED,AssetSettings::METEOR::SMALL::DAMAGE, AssetSettings::METEOR::SMALL::SCORE},
	{AssetSettings::METEOR::MEDIUM::TEXTURE_PATH, AssetSettings::METEOR::MEDIUM::HEALTH, AssetSettings::METEOR::MEDIUM::SPEED,AssetSettings::METEOR::SMALL::DAMAGE, AssetSettings::METEOR::MEDIUM::SCORE},
	{AssetSettings::METEOR::LARGE::TEXTURE_PATH, AssetSettings::METEOR::LARGE::HEALTH, AssetSettings::METEOR::LARGE::SPEED, AssetSettings::METEOR::SMALL::DAMAGE, AssetSettings::METEOR::LARGE::SCORE},
};