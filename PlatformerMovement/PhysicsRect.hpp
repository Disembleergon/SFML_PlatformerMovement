#pragma once
#include <SFML/Graphics.hpp>

class PhysicsRect : public sf::RectangleShape
{
  public:
    PhysicsRect() = default;
    void moveRect(const float speed, const int horizontalDirection, const int verticalDirection);
};
