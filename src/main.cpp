#include <array>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "chain.h"
#include "config.h"



int main()
{
    //init vars
    int linkSize = 40;
    sf::Vector2f radiusVector(linkSize, linkSize);
    int linkCount = 15;
    sf::Vector2f mousePos;
    sf::Vector2f anchorPos(500, 500);
	//set up chain, start pos doesn't particularly matter so just use radiusVector
    Chain guy(radiusVector, linkCount, 40, PI/6);
    

    //create window
    auto window = sf::RenderWindow({conf::WINDOW_SIZE.x, conf::WINDOW_SIZE.y}, "Procedural Anim project");
    window.setFramerateLimit(conf::MAX_FRAMERATE);
  
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
                    guy.addJoint(window);
                    guy.resolve(mousePos);
                    break;
                case::sf::Keyboard::S:
                    guy.deleteJoint();
					guy.resolve(mousePos);
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
                guy.linkSize += 40;
                guy.resolve(mousePos);
                break;
            case sf::Event::MouseButtonReleased:
				guy.linkSize -= 40;
                guy.resolve(mousePos);
                break;
            default:
                break;
            }
        }
        guy.draw(window, rainbow());
        window.display();
    }
}
