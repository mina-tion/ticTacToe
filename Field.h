#pragma once
#include <iostream>
#include <string>
using std::string;

class Field
{
public:
	Field();
	void changeCell(char cellNumber, char value);
	int getCounter();
	void print();

private:
	char cells[3][3];
	int counter = 0;
};
