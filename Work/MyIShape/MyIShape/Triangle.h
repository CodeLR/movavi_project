#pragma once
#include "IShape.h"
class Triangle :
	public IShape
{
private:
	double side_a = 3;
	double side_b = 3;
	double side_c = 3;
	double half_perimeter;
	double area;

public:
	Triangle();
	~Triangle() override;
	double Area() override;
};

