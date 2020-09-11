#pragma once
#include "IShape.h"
class Square :
	public IShape
{
private:
	double side_dia=10;
	double area = NULL;
	
public:
	Square();
	~Square() override;
	double Area() override;
};

