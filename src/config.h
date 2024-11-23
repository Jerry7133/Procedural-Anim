#pragma once
#include <SFML/Graphics.hpp>

namespace conf
{
	//window config
	sf::Vector2u const WINDOW_SIZE = { 1920, 1080 };
	sf::Vector2f const WINDOW_SIZE_F = static_cast<sf::Vector2f>(WINDOW_SIZE);

	unsigned int MAX_FRAMERATE = 144;
	float const DELTATIME = 1.0f / static_cast<float>(MAX_FRAMERATE);

	

}