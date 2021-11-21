#include "PhysicsRect.hpp"
#include "Time.hpp"

void PhysicsRect::moveRect(const float speed, const int horizontalDirection, const int verticalDirection)
{
    move(speed * Time::deltaTime * horizontalDirection, speed * Time::deltaTime * verticalDirection);
}
