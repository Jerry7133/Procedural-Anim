#include <array>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "chain.h"





int main()
{
    //init vars
    int radius = 50;
    sf::Vector2f radiusVec(radius, radius);
    int linkCount = 5;
    //set up chain
    sf::Vector2f start(100, 100);
    Chain guy(start, linkCount, radius);
    sf::Vector2f mousePos;

    //create window
    auto window = sf::RenderWindow({ 1920, 1080}, "CMake SFML Project");
    window.setFramerateLimit(60);
  
    while (window.isOpen())
    {
        window.clear();
        for (auto event = sf::Event(); window.pollEvent(event);)
        {
            switch (event.type)
            {
                //window closed
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                case sf::Keyboard::D:
                    linkCount += 1;
                    break;
                case::sf::Keyboard::S:
                    linkCount -= 1;
                    break;
                default:
                    break;
                }
                break;
            case sf::Event::MouseMoved:
                mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
                guy.resolve(mousePos, radiusVec);
                break;
            case sf::Event::MouseButtonPressed:
                radius += 40;
                break;
            case sf::Event::MouseButtonReleased:
                radius -= 40;
                break;

            default:
                break;
            }
        }
		guy.draw(window, radius);

        window.display();
    }
}
