#pragma once



class Chain
{
	std::vector<sf::Vector2f> joints;
	int linkSize;

	//Used in non-FABRIK resolution
	std::vector<float> angles;
	float angleConstraint; //max angle diff between adjacent joints

public:	Chain(sf::Vector2f origin, int jointCount, int linkSize) :
		
		Chain(origin, jointCount, linkSize, conf::TWO_PI){}

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
	sf::Vector2f resolve(sf::Vector2f& pos)
	{
		angles[0] = heading(pos - joints[0]);
		joints[0] = pos;
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

