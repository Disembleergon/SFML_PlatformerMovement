#include "CameraScript.hpp"
#include "Time.hpp"

void CameraScript::update()
{
    const auto playerPos = m_player.getPosition();
    const auto playerSize = m_player.getSize().x;
    const auto camPos = m_gameCamera.getCenter();

    const auto distance = std::hypotf(playerPos.x - camPos.x, (playerPos.y - playerSize) - camPos.y);
    const auto angle = std::atan2((playerPos.y - playerSize) - camPos.y, playerPos.x - camPos.x);
    const auto dx = std::cos(angle);
    const auto dy = std::sin(angle);

    constexpr int camMoveFactor = 2;

    m_gameCamera.move({ dx * camMoveFactor * distance * Time::deltaTime, dy * camMoveFactor * distance * Time::deltaTime });
}
