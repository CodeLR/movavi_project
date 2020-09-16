// SizeImageProject.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
const int magicSize = 2;
int CastingSize(int,int);
int main()
{
    cout<<CastingSize(1279,640);
}
int CastingSize(int w,int h)
{
    int countImage = 0;
    while (h >= magicSize && w >= magicSize){

        w = (w / magicSize) / magicSize;
;
        h = (h / magicSize) / magicSize;
        
        ++countImage;
    }
    return countImage;
}

