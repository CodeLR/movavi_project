#include <iostream>
#include <stdio.h>
#include <filesystem>
#include <string.h>
using namespace std;
void MyFile(const char*);
int main()
{
	try
	{
		MyFile("C:/qtProject/Work/fileopen/mytext.txt");
		//MyFile("Ваша директория");
	}
	catch (invalid_argument&e)
	{
		cerr << e.what() << endl;
		cout << "Exeption";
		return -1;
	}
}
void MyFile(const char * name)
{
	FILE* fp = fopen(name, "w");
	if (name == "") {
		throw invalid_argument("argument");
	}
	else {
		fprintf(fp, "Rodion Loskutov");
	}
	// возможны и другие проверки
	fclose(fp);
}
