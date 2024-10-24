#include <array>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "chain.h"

//init vars
int radius = 40;
int linkSize = 50;
//set up chain
sf::Vector2f start(100, 100);
Chain guy(start, 5, linkSize);
sf::Vector2f mousePos;



int main()
{
    //create window
    auto window = sf::RenderWindow({ 1000, 1000}, "CMake SFML Project");
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
                    linkSize += 50;
                    break;
                case::sf::Keyboard::S:
                    linkSize -= 50;
                    break;
                default:
                    break;
                }
                break;
            case sf::Event::MouseMoved:
                mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
                guy.resolve(mousePos);
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
