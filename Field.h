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
	bool isMarked(char cellNumber);
	string getWinner();
	void printCell(int cellNumber);
private:
	char cells[9];
	int counter = 0;
};
