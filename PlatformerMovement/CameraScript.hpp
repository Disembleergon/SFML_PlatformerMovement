#pragma once
#include "GameScript.hpp"
#include "PhysicsRect.hpp"

class CameraScript : public GameScript
{
  public:
    CameraScript(sf::RenderWindow &window, sf::View &cam, PhysicsRect &player)
        : GameScript(window), m_gameCamera(cam), m_player(player)
    {
        // EMPTY
    }

    void update() override;
    void draw() override{
        // EMPTY
    };

  private:
    sf::View &m_gameCamera;
    PhysicsRect &m_player;
};
