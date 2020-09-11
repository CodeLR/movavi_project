#include "Circle.h"

Circle::Circle()
{

}

Circle::~Circle()
{
}

double Circle::Area()
{
    radius = radius * radius;
    area = pi * radius;

    return area;
}