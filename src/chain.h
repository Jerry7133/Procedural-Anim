#pragma once
#include <vector>
#include <iostream>
#include "animUtil.h"
#include <random>




class Chain
{
public:
	std::vector<sf::Vector2f> joints;
	int linkSize;

	//Used in non-FABRIK resolution
	std::vector<float> angles;
	float angleConstraint; //max angle diff between adjacent joints

	Chain(sf::Vector2f origin, int jointCount, int linkSize) :

		Chain(origin, jointCount, linkSize, TWO_PI) {}

	Chain(sf::Vector2f origin, int jointCount, int linkSize, float angleConstraint)
	{
		this->angleConstraint = angleConstraint;
		this->linkSize = linkSize;

		joints.reserve(jointCount); //Gonna be bigger than 2 to be a chain
		angles.reserve(jointCount);

		angles.push_back(0.f);
		joints.push_back(origin);

		for (int i = 1; i < jointCount; ++i)
		{
			sf::Vector2f newJoint = joints[i - 1];
			joints.push_back(newJoint);
			angles.push_back(0.f);
		}
	}

	sf::Vector2f const constrainDistance(sf::Vector2f origin, sf::Vector2f point)
	{
		sf::Vector2f diff = origin - point;
		float length = sqrt(diff.x * diff.x + diff.y * diff.y);

		if (length > linkSize)
		{
			diff /= length;
			diff *= static_cast<float>(linkSize);
			point = origin - diff;
			return point;
		}
		else return point;
	}
	void resolve(sf::Vector2f pos)
	{
		sf::Vector2f radiusVector(linkSize, linkSize);
		joints[0] = pos - radiusVector;
		angles[1] = heading(joints[0] - joints[1]);
		joints[1] = joints[0] - setMag(fromAngle(angles[1]), linkSize);

		for (int i = 2; i < joints.size(); i++)
		{
			float currentAngle = heading(joints[i - 1] - joints[i]);
			angles[i] = constrainAngle(currentAngle, angles[i - 1], angleConstraint);
			joints[i] = joints[i - 1] - setMag(fromAngle(angles[i]),linkSize);
			
		}
	}


	void fabrikResolve(sf::Vector2f target, sf::Vector2f anchor)
	{
		sf::Vector2f radiusVector = sf::Vector2f(linkSize, linkSize);
		//Resolve from start to end
		joints[0] = target - radiusVector;
		for (int i = 1; i < joints.size(); ++i)
		{
			joints[i] = constrainDistance(joints[i - 1], joints[i]);
		}
		//Resolve from end to start
		joints[joints.size() - 1] = anchor;
		for (int i = joints.size() - 2; i > 0; --i)
		{
			joints[i] = constrainDistance(joints[i + 1], joints[i]);
		}
	}
	void draw(sf::RenderWindow& window,	sf::Color fill = sf::Color::Transparent,
		sf::Color outlineColor = sf::Color::White, int outlineThickness = 5)
	{
		for (int i = joints.size() - 1; i >= 0; i--) {
			sf::CircleShape circle(linkSize);
			circle.setFillColor(fill);
			circle.setOutlineColor(outlineColor);
			circle.setOutlineThickness(outlineThickness);
			circle.setPosition(joints[i]);
			window.draw(circle);
		}


	}
	void addJoint(sf::RenderWindow& window, sf::Color fill = sf::Color::Transparent, 
		sf::Color outlineColor = sf::Color::White, int outlineThickness = 5)
	{
		int lastElement = joints.size() - 1;
		sf::Vector2f newJoint = this->joints[lastElement];
		joints.push_back(newJoint);
		angles.push_back(0.f);
		sf::CircleShape circle(linkSize);
		circle.setFillColor(fill);
		circle.setOutlineColor(outlineColor);
		circle.setOutlineThickness(outlineThickness);
		circle.setPosition(newJoint);
		window.draw(circle);
	}
	void deleteJoint()
	{
		if (joints.size() > 2)
		{
			joints.pop_back();
			angles.pop_back();
		}
	}
	
};
		  