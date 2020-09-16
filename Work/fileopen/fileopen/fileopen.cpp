#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include <filesystem>
#include <string.h>
using namespace std;
void MyFile(const char*);
int main()
{
	try
	{
		MyFile("C:/qtProject/Work/fileopen/mytext.txt");	
	}
	catch (FILE* f)
	{
		cout << "Exeption";
		return -1;

	}
	catch (std::invalid_argument& s) {
		cout << "Exeption NULL";
		return -1;
	}
}
void MyFile(const char * name)
{
	FILE* fp = fopen(name,"w");
	
	if (name == "") {
	
		throw (fp);
	}
	if (fp == NULL){
		throw invalid_argument("No Open");
	}
	
	else {
		fputs("Loskutov Rodion ",fp);
		
	}
	fclose(fp);


	// возможны и другие проверки
	
}
