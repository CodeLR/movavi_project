#pragma once
#include "IShape.h"
#include <cmath>

class Rectangle :
	public IShape
{
	private:
		double side_a = 11;
		double side_b = 8;
		double area;


public:
	Rectangle();
	~Rectangle()override;
	double Area() override;
};

