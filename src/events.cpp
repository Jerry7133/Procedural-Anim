#include "events.hpp"




void processEvents(sf::Window& window)
{

    for (auto event = sf::Event(); window.pollEvent(event);)
    {
        switch (event.type)
        {
            //window closed
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            switch (event.key.scancode)
            {
            case sf::Keyboard::Scan::Escape:
                window.close();
                break;

            default:
                break;
            }
            break;
        default:
            break;
        }
        

    }
}

void updateObjectLocation(sf::CircleShape& circle, sf::Window& window)
{
    //get mouse pos
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    // convert to vector float
    sf::Vector2f objectCenter = sf::Vector2f(mousePos.x, mousePos.y);
    
    // adjust obj to center on mouse
    objectCenter.x -= circle.getGlobalBounds().width/ 2.f;
    objectCenter.y -= circle.getGlobalBounds().height / 2.f;


    circle.setPosition(objectCenter);

}
