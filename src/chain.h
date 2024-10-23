#pragma once
#include "config.h"
#include <SFML/Graphics.hpp>
#include <vector>


class Chain
{
	std::vector<int> joints;
	int linksize;

	//Used in non-FABRIK resolution
	std::vector<double> angles;
	double angleConstraint; //max angle diff between adjacent joints
public:
	Chain(const std::vector<double> origin, int jointCount, int linkSize) :
		
		Chain(origin, jointCount, linkSize, conf::TWO_PI){}
	

	Chain(std::vector<int> origin, int jointCount, int linkSize, double angleConstraint)
	{
		this->linksize = linkSize;
		this->angleConstraint = angleConstraint;
		
		
		std::vector<int> joints;


	}

};