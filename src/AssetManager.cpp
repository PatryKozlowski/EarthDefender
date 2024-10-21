#include "AssetManager.hpp"

AssetManager &AssetManager::GetInstance()
{
    static AssetManager instance;
    return instance;
}

const sf::Texture &AssetManager::LoadTexture(const std::string &pathName)
{
    auto it = m_Textures.find(pathName);

    if (it != m_Textures.end())
    {
        return *it->second;
    }

    auto texture = std::make_unique<sf::Texture>();

    if (!texture->loadFromFile(pathName))
    {
        throw std::runtime_error("Failed to load texture: " + pathName);
    }

    m_Textures[pathName] = std::move(texture);

    return *m_Textures[pathName];
}

const sf::Texture &AssetManager::GetTexture(const std::string &pathName) const
{
    auto it = m_Textures.find(pathName);

    if (it == m_Textures.end())
    {
        throw std::runtime_error("Texture not found: " + pathName);
    }

    return *it->second;
}

const sf::Font &AssetManager::LoadFont(const std::string &pathName)
{
    auto it = m_Fonts.find(pathName);

    if (it != m_Fonts.end())
    {
        return *it->second;
    }

    auto font = std::make_unique<sf::Font>();

    if (!font->loadFromFile(pathName))
    {
        throw std::runtime_error("Failed to load font: " + pathName);
    }

    m_Fonts[pathName] = std::move(font);

    return *m_Fonts[pathName];
}

const sf::Font &AssetManager::GetFont(const std::string &pathName) const
{
    auto it = m_Fonts.find(pathName);

    if (it == m_Fonts.end())
    {
        throw std::runtime_error("Font not found: " + pathName);
    }

    return *it->second;
}

// const sf::Sprite &AssetManager::GetSpriteFromSheet(const std::string &pathName, const sf::IntRect rect) const
// {
//     const sf::Texture &texture = GetTexture(pathName);
//     sf::Sprite sprite;

//     sprite.setTexture(texture);
//     sprite.setTextureRect(rect);

//     return sprite;
// }