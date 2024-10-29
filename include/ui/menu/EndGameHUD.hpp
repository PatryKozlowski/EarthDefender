#pragma once

#include <SFML/Graphics.hpp>

#include "MenuHUD.hpp"

class EndGameHUD : public MenuHUD
{
public:
    EndGameHUD(sf::RenderWindow &window);

    void HandleInput(const sf::Event &event) override;
    bool IsRestartGame() const;
    bool IsExitGame() const;
    void ResetFlags();

protected:
    void InitEndGameHUD();
    void DrawMenuTitle(sf::RenderWindow &window) override;
    void OnOptionClick(const std::string &label) override;

private:
    bool m_RestartGame = false;
    bool m_ExitGame = false;
};