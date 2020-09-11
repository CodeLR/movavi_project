#include "Triangle.h"

Triangle::Triangle()
{

}

Triangle::~Triangle()
{
}

double Triangle::Area()
{
    half_perimeter = (side_a + side_b + side_c) / 2.0;
    area = sqrt(half_perimeter * (half_perimeter - side_a) * (half_perimeter - side_b) * (half_perimeter - side_c));
    return area;
}
