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
	char& cell(int row, int col);
	void setCell(int cellNumber, char value);
private:

	char cells[9];
	int lines[8][3];
	int counter = 0;
};
