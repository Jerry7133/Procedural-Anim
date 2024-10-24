#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>



void processEvents(sf::Window& window);
void updateObjectLocation(sf::CircleShape& circle, sf::Window& window);
sf::Vector2f constrainDistance(sf::Vector2f origin, sf::Vector2f point, float constraint	);
float heading(const sf::Vector2f& v);
float constrainAngle(float angle, float constraint);

void circleDefine(sf::RenderWindow& window, int radius = 40,
	sf::Color fill = sf::Color::Transparent, sf::Color outlineColor = sf::Color::White,
	int outlineThickness = 5)
{
	sf::CircleShape circle(radius);
	circle.setFillColor(fill);
	circle.setOutlineColor(outlineColor);
	circle.setOutlineThickness(outlineThickness);
}