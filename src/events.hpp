#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void processEvents(sf::Window& window);
void updateObjectLocation(sf::CircleShape& circle, sf::Window& window);