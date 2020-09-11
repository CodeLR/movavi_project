#pragma once
#include <iostream>

class IShape
{
public:
    IShape();
    virtual ~IShape();
    virtual double Area() = 0;

};
