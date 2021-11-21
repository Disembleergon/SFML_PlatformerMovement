#pragma once
#include <SFML/Graphics.hpp>

// abstract class for game scripts
class GameScript
{
  public:
    GameScript(sf::RenderWindow &window)
        : m_window(window){
              // EMPTY
          };

    GameScript() = delete;

    virtual ~GameScript() = default;
    virtual void draw() = 0;
    virtual void update() = 0;

  protected:
    sf::RenderWindow &m_window;
};
