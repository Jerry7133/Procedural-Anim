#include "events.hpp"
#include "chain.h"




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

sf::Vector2f constrainDistance(sf::Vector2f origin, sf::Vector2f point, float constraint = 50)
{
    sf::Vector2 diff = origin - point;
    float length = sqrt(diff.x * diff.x + diff.y * diff.y);

    if (length > constraint)
    {
        diff /= length;
        diff *= constraint;
        point = origin - diff;
    }
    return point;
}

float heading(const sf::Vector2f& v)
{
    return atan2(v.y, v.x);
}

float constrainAngle(float angle, float constraint)
{
    if (angle > constraint)
        angle = constraint;
    else if (angle < -constraint)
        angle = -constraint;
    return angle;
}