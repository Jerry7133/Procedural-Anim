#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

const double PI = 3.14159;
const double TWO_PI = 6.28319;


float heading(const sf::Vector2f v)
{
    return atan2(v.y, v.x);
}

//angle changes to be in [0, 2PI)
float simplifyAngle(float angle)
{
    while (angle >= TWO_PI)
    {
        angle -= TWO_PI;
    }
    while (angle < 0)
    {
        angle += TWO_PI;
    }
    return angle;
}

float relativeAngleDiff(float angle, float anchor)
{
	//add pi to keep anchor in [0, 2PI) with pi as center
    angle = simplifyAngle(angle + PI - anchor);
    anchor = PI;

    return anchor - angle;
}


float constrainAngle(float angle, float anchor, float constraint)
{
    if (abs(relativeAngleDiff(angle, anchor)) <= constraint)
		return simplifyAngle(angle);
    if (relativeAngleDiff(angle, anchor) > constraint)
        return simplifyAngle(anchor - constraint);
	return simplifyAngle(anchor + constraint);
}

sf::Vector2f fromAngle(float angle)
{
	return sf::Vector2f(cosf(angle), sinf(angle));
}
float mag(sf::Vector2f vec)
{
	return sqrt(vec.x * vec.x + vec.y * vec.y);
}
sf::Vector2f normalize(sf::Vector2f target)
{
	float m = sqrt(target.x * target.x + target.y * target.y);
	if (m != 0 && m != 1)
	{
		target /= m;
	}
	return target;
}
sf::Vector2f setMag(sf::Vector2f vec, float newMag)
{
	vec = normalize(vec);
	vec *= newMag;
	return vec;
}

sf::Color rainbow()
{
	static float hue = 0;
	hue += 0.01;
	if (hue > TWO_PI)
		hue = 0;
	return sf::Color(255 * (1 + cos(hue)) / 2, 255 * (1 + cos(hue + 2 * PI / 3)) / 2, 255 * (1 + cos(hue + 4 * PI / 3)) / 2);
}
