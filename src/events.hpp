#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>



void processEvents(sf::Window& window);
void updateObjectLocation(sf::CircleShape& circle, sf::Window& window);
sf::Vector2f constrainDistance(sf::Vector2f origin, sf::Vector2f point, float constraint	);
float heading(const sf::Vector2f& v);
float constrainAngle(float angle, float constraint);

