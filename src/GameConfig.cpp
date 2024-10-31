#include "GameConfig.hpp"
#include <vector>

const sf::Color WHITE = sf::Color(255, 255, 255);
const sf::Color MAGENTA = sf::Color(255, 0, 255);
const sf::Color GRAY = sf::Color(128, 128, 128);

const std::string GameAssets::FONT = GetResourceDir() + "font.ttf";

const std::string AssetSettings::EXPLOSION::TEXTURE_PATH = GetResourceDir() + "explosion.png";
const std::string AssetSettings::EARTH::TEXTURE_PATH = GetResourceDir() + "earth.png";
const std::string AssetSettings::HEART::TEXTURE_PATH = GetResourceDir() + "heart.png";
const std::string AssetSettings::CLOCK::TEXTURE_PATH = GetResourceDir() + "clock.png";
const std::string AssetSettings::COIN::TEXTURE_PATH = GetResourceDir() + "coin.png";
const std::string AssetSettings::SHIELD::TEXTURE_PATH = GetResourceDir() + "shield.png";
const std::string AssetSettings::METEOR::SMALL::TEXTURE_PATH = GetResourceDir() + "meteor_small.png";
const std::string AssetSettings::METEOR::MEDIUM::TEXTURE_PATH = GetResourceDir() + "meteor_medium.png";
const std::string AssetSettings::METEOR::LARGE::TEXTURE_PATH = GetResourceDir() + "meteor_large.png";

const std::string AssetSettings::BUFF::DOUBLE_DAMAGE::TEXTURE_PATH = GetResourceDir() + "buffs/double_damage.png";
const std::string AssetSettings::BUFF::DOUBLE_SCORE::TEXTURE_PATH = GetResourceDir() + "buffs/double_score.png";
const std::string AssetSettings::BUFF::INVINCIBILITY::TEXTURE_PATH = GetResourceDir() + "buffs/shield_buff.png";
const std::string AssetSettings::BUFF::SLOW_METEOR_SPEED::TEXTURE_PATH = GetResourceDir() + "buffs/slow_clock.png";

const sf::Color MenuConfig::TITLE_COLOR = WHITE;
const sf::Color MenuConfig::OPTION_COLOR = WHITE;
const sf::Color MenuConfig::OPTION_HIGHLIGHT_COLOR = MAGENTA;

const sf::Color TopBarHUDConfig::TEXT_COLOR = WHITE;
const sf::Color TopBarHUDConfig::BACKGROUND_COLOR = GRAY;

const std::vector<MeteorData> AssetSettings::METEOR::METEOR_TYPES = {
	{AssetSettings::METEOR::SMALL::TEXTURE_PATH, AssetSettings::METEOR::SMALL::HEALTH, AssetSettings::METEOR::SMALL::SPEED,AssetSettings::METEOR::SMALL::DAMAGE, AssetSettings::METEOR::SMALL::SCORE},
	{AssetSettings::METEOR::MEDIUM::TEXTURE_PATH, AssetSettings::METEOR::MEDIUM::HEALTH, AssetSettings::METEOR::MEDIUM::SPEED,AssetSettings::METEOR::SMALL::DAMAGE, AssetSettings::METEOR::MEDIUM::SCORE},
	{AssetSettings::METEOR::LARGE::TEXTURE_PATH, AssetSettings::METEOR::LARGE::HEALTH, AssetSettings::METEOR::LARGE::SPEED, AssetSettings::METEOR::SMALL::DAMAGE, AssetSettings::METEOR::LARGE::SCORE},
};

const std::vector<BuffData> AssetSettings::BUFF::BUFF_TYPES = {
	{AssetSettings::BUFF::DOUBLE_DAMAGE::TEXTURE_PATH, BuffTypeID::DOUBLE_DAMAGE, AssetSettings::BUFF::DOUBLE_DAMAGE::DURATION},
	{AssetSettings::BUFF::DOUBLE_SCORE::TEXTURE_PATH, BuffTypeID::DOUBLE_SCORE, AssetSettings::BUFF::DOUBLE_SCORE::DURATION},
	{AssetSettings::BUFF::INVINCIBILITY::TEXTURE_PATH, BuffTypeID::INVINCIBILITY, AssetSettings::BUFF::INVINCIBILITY::DURATION},
	{AssetSettings::BUFF::SLOW_METEOR_SPEED::TEXTURE_PATH, BuffTypeID::SLOW_METEOR_SPEED, AssetSettings::BUFF::SLOW_METEOR_SPEED::DURATION},
};