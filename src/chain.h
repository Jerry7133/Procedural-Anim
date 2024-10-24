#pragma once
#include <vector>


const double TWO_PI = 6.28319;

class Chain
{
	std::vector<sf::Vector2f> joints;
	int linkSize;

	//Used in non-FABRIK resolution
	std::vector<float> angles;
	float angleConstraint; //max angle diff between adjacent joints

public:	Chain(sf::Vector2f origin, int jointCount, int linkSize) :
		
		Chain(origin, jointCount, linkSize, TWO_PI){}

public:	Chain(sf::Vector2f origin, int jointCount, int linkSize, float angleConstraint) 
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
	  
	  void resolve(sf::Vector2f target)
	  {
		  //Resolve from end to start
		  joints[joints.size() - 1] = target;
		  for (int i = joints.size() - 2; i >= 0; --i)
		  {
			  joints[i] = constrainDistance(joints[i + 1], joints[i]);
		  }

		  //Resolve from start to end
		  joints[0] = constrainDistance(joints[1], joints[0]);
		  for (int i = 1; i < joints.size(); ++i)
		  {
			  joints[i] = constrainDistance(joints[i - 1], joints[i]);
		  }
	  }
	  void draw(sf::RenderWindow& window, int radius = 40,
		  sf::Color fill = sf::Color::Transparent, sf::Color outlineColor = sf::Color::White,
		  int outlineThickness = 5)
	  {
		  for (const auto& joint : joints) {
			  sf::CircleShape circle(radius);
			  circle.setFillColor(fill);
			  circle.setOutlineColor(outlineColor);
			  circle.setOutlineThickness(outlineThickness);
			  circle.setPosition(joint);
			  window.draw(circle);
		  }

	  }
	  

	  

	
};

/*void draw(sf::RenderWindow& window, int radius = 40,
	sf::Color fill = sf::Color::Transparent, sf::Color outlineColor = sf::Color::White,
	int outlineThickness = 5)
{
	for (const auto& joint : joints) {
		sf::CircleShape circle(radius);
		circle.setFillColor(fill);
		circle.setOutlineColor(outlineColor);
		circle.setOutlineThickness(outlineThickness);
		circle.setPosition(joint);
		window.draw(circle);
	}

}*/

