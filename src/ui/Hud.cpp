#include "ui/Hud.hpp"

#include "AssetManager.hpp"
#include "GameConfig.hpp"

Hud::Hud(sf::RenderWindow &window) : m_Window(window)
{
    AssetManager::GetInstance().LoadFont(g_GameAssets.FONT);

    const sf::Font &font = AssetManager::GetInstance().GetFont(g_GameAssets.FONT);

    m_Font = font;
}
