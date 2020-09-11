#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    const char* name = "‪C:/qtProject/Work/fileopen/text.txt";
    FILE* fp=fopen("C:/qtProject/Work/fileopen/mytext.txt" , "w");
    // написать исключение по файлу
    fclose(fp);
}
