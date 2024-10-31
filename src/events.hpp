#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>




void updateObjectLocation(sf::CircleShape& circle, sf::Window& window);
sf::Vector2f constrainDistance(sf::Vector2f origin, sf::Vector2f point, float constraint	);