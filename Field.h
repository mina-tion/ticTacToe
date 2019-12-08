#pragma once
#include <iostream>
#include <string>
using std::string;

class Field
{
public:
	Field();
	void changeCell(string cellNumber, string value);
	int getCounter();
	void print();

private:
	string cells[3][3];
	int counter = 0;
};
