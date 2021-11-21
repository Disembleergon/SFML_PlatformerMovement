#include "GameWindow.hpp"
#include "BuildingGeneratorScript.hpp"
#include "PlayerMovementScript.hpp"
#include "CameraScript.hpp"
#include "Time.hpp"

GameWindow::GameWindow(unsigned int w, unsigned int h, const sf::String &title)
    : m_window{sf::VideoMode{w, h}, title}, clearColor{245, 245, 245}
{
    m_window.setFramerateLimit(60);
    m_window.setVerticalSyncEnabled(true);
}

void GameWindow::handleEvents()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_window.close();
    }
}

void GameWindow::run()
{
    sf::View gameCam{sf::FloatRect{0, 0, static_cast<float>(m_window.getSize().x), static_cast<float>(m_window.getSize().y)}};
    m_window.setView(gameCam);

    const float groundPosY = m_window.getSize().y / 2.0f + 100;
    constexpr int playerSize = 100;

    // generate buildings
    BuildingGeneratorScript buildingGenerator{m_window};
    buildingGenerator.generateBuildings(500, groundPosY);

    PlayerMovementScript playerMovement{m_window,
                                        {m_window.getSize().x / 2.0f, groundPosY},
                                        {playerSize, playerSize},
                                        sf::Color::Color(230, 41, 55),
                                        groundPosY};

    CameraScript cameraScript{ m_window, gameCam, playerMovement.getPlayer() };

    while (m_window.isOpen())
    {
        Time::updateDeltaTime();
        handleEvents();

        playerMovement.update();
        cameraScript.update();

        m_window.setView(gameCam);

        // draw everything
        m_window.clear(clearColor);
        buildingGenerator.draw();
        playerMovement.draw();

        m_window.display();
    }
}
