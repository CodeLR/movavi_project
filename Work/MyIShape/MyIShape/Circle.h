#pragma once
#include "IShape.h"
class Circle :
	public IShape
{
private:
	const double pi = 3.1415;
	double radius = 9;
	double area = NULL;
public:
	Circle();
	~Circle() override ;
	double Area() override;
};

