#include <array>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "events.hpp"
#include "config.h"
#include "chain.h"

sf::Vector2f start(100, 100);

Chain guy(start, 50, 50);



int main()
{
    //create window
    auto window = sf::RenderWindow({ conf::WINDOW_SIZE.x , conf::WINDOW_SIZE.y}, "CMake SFML Project");
    window.setFramerateLimit(conf::MAX_FRAMERATE);
    float x, y = 0;

    

    while (window.isOpen())
    {
        
        window.clear();
        processEvents(window);
        guy.draw(window);
        window.display();
    }
}
