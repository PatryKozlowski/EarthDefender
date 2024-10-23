#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <memory>
#include <string>

class AssetManager
{
public:
    AssetManager(const AssetManager &) = delete;
    AssetManager &operator=(const AssetManager &) = delete;

    static AssetManager &GetInstance();

    const sf::Texture &LoadTexture(const std::string &pathName);
    const sf::Texture &GetTexture(const std::string &pathName) const;
    const sf::Font &LoadFont(const std::string &pathName);
    const sf::Font &GetFont(const std::string &pathName) const;

private:
    AssetManager() = default;

    std::unordered_map<std::string, std::unique_ptr<sf::Texture>> m_Textures;
    std::unordered_map<std::string, std::unique_ptr<sf::Font>> m_Fonts;
};
