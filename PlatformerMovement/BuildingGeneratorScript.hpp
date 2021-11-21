#pragma once
#include "GameScript.hpp"

class BuildingGeneratorScript : public GameScript
{
  public:
    BuildingGeneratorScript(sf::RenderWindow &window) : GameScript(window)
    {
        // EMPTY
    }

    void update() override;
    void draw() override;

    void generateBuildings(const unsigned int building_count, const float groundPositionY);

  private:
    std::vector<sf::RectangleShape> m_buildings;
    sf::RectangleShape m_ground;
};
