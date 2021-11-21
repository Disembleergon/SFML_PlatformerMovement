#pragma once
#include "GameScript.hpp"
#include "PhysicsRect.hpp"
#include <tuple>
#include <unordered_map>

class PlayerMovementScript : public GameScript
{
  public:
    PlayerMovementScript(sf::RenderWindow &window, const sf::Vector2f &pos, const sf::Vector2f &size,
                         const sf::Color &clr, const float groundY);

    void update() override;
    void draw() override;

    PhysicsRect &getPlayer()
    {
        return m_player;
    }

  private:
    PhysicsRect m_player;
    const float m_groundY;

    // unordered map containing directions for the player to go when a key is pressed
    using keymap_t = std::unordered_map<sf::Keyboard::Key, std::tuple<int, int>>;
    static keymap_t keyActions;

    void processJump();
    bool m_isJumping{false};
    float m_jumpForce{0};
};
