#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "chain.h"

class snake {
public:
	Chain spine;

	snake(sf::Vector2f origin) : spine(origin, 48, 40, PI/8) {}

	void resolve(sf::RenderWindow& window)
	{
		sf::Vector2f headPos = spine.joints[0];
		sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
		spine.resolve(mousePos);
	}
	
	float bodywith = 60;

	float getPosX(int i, float angleOffset, float distanceOffset)
	{
		return spine.joints[i].x + cosf(spine.joints[i].x * angleOffset)  * distanceOffset;
	}

	float getPosY(int i, float angleOffset, float distanceOffset)
	{
		return spine.joints[i].y + sinf(spine.joints[i].y * angleOffset) * distanceOffset;
	}
};