#include "events.hpp"
#include "config.h"
#include <array>
#include <iostream>
#include <vector>


int main()
{
    //create window
    auto window = sf::RenderWindow({ conf::WINDOW_SIZE.x , conf::WINDOW_SIZE.y}, "CMake SFML Project");
    window.setFramerateLimit(conf::MAX_FRAMERATE);
    float x, y = 0;

    //define circle
    sf::CircleShape circle(40.f);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineColor(sf::Color::White);
    circle.setOutlineThickness(5);

    while (window.isOpen())
    {
        
        processEvents(window);
        window.clear();
        updateObjectLocation(circle, window);
        window.draw(circle);
        window.display();
    }
}
