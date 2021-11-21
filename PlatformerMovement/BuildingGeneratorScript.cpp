#include "BuildingGeneratorScript.hpp"
#include "Random.hpp"
#include <iostream>

void BuildingGeneratorScript::update()
{
    // nothing to update
}

void BuildingGeneratorScript::draw()
{
    // draw every building
    for (const auto &building : m_buildings)
        m_window.draw(building);

    // draw ground
    m_window.draw(m_ground);
}

void BuildingGeneratorScript::generateBuildings(const unsigned int building_count, const float groundPositionY)
{
    m_buildings.clear();

    constexpr float buildingWidth = 50;
    const float buildingRangeStart = m_window.getSize().x / 2 - (building_count * buildingWidth * 0.5f);

    for (unsigned int i = 0; i < building_count; i++)
    {
        const float buildingHeight = Random::generate_floating_point(100.0f, 550.0f);
        const float buildingX = buildingRangeStart + buildingWidth * i;

        const sf::Uint8 r = Random::generate_integral(200, 240);
        const sf::Uint8 g = Random::generate_integral(200, 240);
        const sf::Uint8 b = Random::generate_integral(200, 240);

        // configure building
        sf::RectangleShape new_building;
        new_building.setSize(sf::Vector2f{buildingWidth, buildingHeight});
        new_building.setOrigin(sf::Vector2f{0, buildingHeight});
        new_building.setFillColor(sf::Color::Color(r, g, b));
        new_building.setPosition(sf::Vector2f{buildingRangeStart + buildingWidth * i, groundPositionY});

        m_buildings.push_back(new_building);
    }

    // configure ground
    m_ground.setPosition(sf::Vector2f{m_buildings.front().getPosition().x, groundPositionY});
    m_ground.setSize(
        sf::Vector2f{m_buildings.back().getPosition().x * 2 + buildingWidth, static_cast<float>(m_window.getSize().y)});
    m_ground.setFillColor(sf::Color::Color(80, 80, 80));
}
