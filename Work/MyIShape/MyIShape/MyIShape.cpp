#include <iostream>

#include "IShape.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"

void Display()
{
    std::cout << "1) Circle\n";
    std::cout << "2) Rectangle\n";
    std::cout << "3) Square\n";
    std::cout << "4) Triangle\n";
}
int main()
{
    const int sizeFigure = 4;
    IShape* obj[sizeFigure];
    obj[0] = new Circle();
    obj[1] = new Rectangle();
    obj[2] = new Square();
    obj[3] = new Triangle();
    Display();
    int num = NULL;
    std::cin >> num;
    switch (num)
    {
    case 1 :
        std::cout<<obj[0]->Area();
        break;
    case 2:
        std::cout << obj[1]->Area();
        break;
    case 3:
        std::cout << obj[2]->Area();
        break;
    case 4:
        std::cout << obj[3]->Area();
        break;

    default:
        break;
    }
    

    
    return 0;



}

