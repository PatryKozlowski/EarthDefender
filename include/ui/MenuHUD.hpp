#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "GameConfig.hpp"
#include "ui/Text.hpp"

class MenuHUD
{
public:
    MenuHUD(sf::RenderWindow &window);
    virtual ~MenuHUD() = default;

    virtual void HandleInput(const sf::Event &event);
    void AddOption(const std::string &label);
    void Draw();

protected:
    void InitOptions(const std::vector<std::string> &options);
    virtual void DrawMenuTitle(sf::RenderWindow &window);
    virtual void OnOptionClick(const std::string &label);
    void HandleMouseMove(float x, float y) const;
    void HandleMouseClick(float x, float y);

    sf::RenderWindow &m_Window;
    std::unique_ptr<Text> m_Title;
    std::vector<MenuOption> m_Options;
    MenuConfig m_Config;
};