#include "GameConfig.hpp"

const sf::Color WHITE = sf::Color(255, 255, 255);
const sf::Color MAGENTA = sf::Color(255, 0, 255);
const sf::Color GRAY = sf::Color(128, 128, 128);

const std::string GameAssets::FONT = GetResourceDir() + "/font.ttf";

const std::string AssetSettings::EARTH::TEXTURE_PATH = GetResourceDir() + "/earth.png";
const std::string AssetSettings::HEART::TEXTURE_PATH = GetResourceDir() + "/heart.png";
const std::string AssetSettings::TIME_TEXT::TEXTURE_PATH = GetResourceDir() + "/clock.png";
const std::string AssetSettings::COIN::TEXTURE_PATH = GetResourceDir() + "/coin.png";

const sf::Color MenuConfig::TITLE_COLOR = WHITE;
const sf::Color MenuConfig::OPTION_COLOR = WHITE;
const sf::Color MenuConfig::OPTION_HIGHLIGHT_COLOR = MAGENTA;

const sf::Color GamePlayHUDConfig::TEXT_COLOR = WHITE;
const sf::Color GamePlayHUDConfig::BACKGROUND_COLOR = GRAY;