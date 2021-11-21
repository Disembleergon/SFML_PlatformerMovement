#pragma once
#include <SFML/System.hpp>

class Time
{
  public:
    static void updateDeltaTime()
    {
        deltaTime = m_dtClock.restart().asSeconds();
    }

    static float deltaTime;

  private:
    static sf::Clock m_dtClock;
};