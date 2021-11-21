#include "PlayerMovementScript.hpp"
#include "Time.hpp"

PlayerMovementScript::keymap_t PlayerMovementScript::keyActions{
    {sf::Keyboard::Space, {0, 0}}, {sf::Keyboard::A, {-1, 0}}, {sf::Keyboard::D, {1, 0}}};

PlayerMovementScript::PlayerMovementScript(sf::RenderWindow &window, const sf::Vector2f &pos, const sf::Vector2f &size,
                                           const sf::Color &clr, const float groundY)
    : GameScript(window), m_groundY(groundY)
{
    m_player.setSize(size);
    m_player.setOrigin({0, size.y});
    m_player.setPosition(pos);
    m_player.setFillColor(clr);
}

void PlayerMovementScript::update()
{
    constexpr float speed = 900;

    // move player on key press
    for (const auto &keyEvent : keyActions)
    {
        // check if key is pressed
        if (!sf::Keyboard::isKeyPressed(keyEvent.first))
            continue;

        if (keyEvent.first == sf::Keyboard::Space && !m_isJumping)
        {
            // start jump
            m_jumpForce = -1000;
            m_isJumping = true;
        }

        // get mapped directions for key
        const auto [directionX, directionY] = keyActions.at(keyEvent.first);
        m_player.moveRect(speed, directionX, directionY);
    }

    if (m_isJumping)
        processJump();
}

void PlayerMovementScript::processJump()
{
    constexpr int gravityStrength = 1600;

    // apply force
    m_player.moveRect(1, 0, m_jumpForce);

    // apply gravity to force
    m_jumpForce += gravityStrength * Time::deltaTime;

    // if player is jumping and hitting the ground, reset and set is_jumping to false
    if (m_player.getPosition().y >= m_groundY)
    {
        // set player pos to ground, fixing bug
        m_player.setPosition({m_player.getPosition().x, m_groundY});

        m_jumpForce = 0;
        m_isJumping = false;
        return;
    }
}

void PlayerMovementScript::draw()
{
    m_window.draw(m_player);
}
