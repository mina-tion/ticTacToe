#include "Field.h"
#include "Graphic.h"
using namespace std;
Field::Field()
{
	cells[0] = '1';
	cells[1] = '2';
	cells[2] = '3';
	cells[3] = '4';
	cells[4] = '5';
	cells[5] = '6';
	cells[6] = '7';
	cells[7] = '8';
	cells[8] = '9';

	lines[0][0] = 0;
	lines[0][1] = 1;
	lines[0][2] = 2;
	lines[1][0] = 3;
	lines[1][1] = 4;
	lines[1][2] = 5;
	lines[2][0] = 6;
	lines[2][1] = 7;
	lines[2][2] = 8;
	lines[3][0] = 0;
	lines[3][1] = 3;
	lines[3][2] = 6;
	lines[4][0] = 1;
	lines[4][1] = 4;
	lines[4][2] = 7;
	lines[5][0] = 2;
	lines[5][1] = 5;
	lines[5][2] = 8;
	lines[6][0] = 0;
	lines[6][1] = 4;
	lines[6][2] = 8;
	lines[7][0] = 2;
	lines[7][1] = 4;
	lines[7][2] = 6;

}

void Field::changeCell(char cellNumber, char value)
{
	counter++;
	for (int i = 0; i < 9; ++i)
			if (cells[i] == cellNumber)
			{
				cells[i] = value;
			}
}

int Field::getCounter()
{
	return counter;
}

void Field::setCell(int cellNumber, char value)
{
	cells[cellNumber] = value;
}

void Field::printCell(int cellNumber)
{
	if (cells[cellNumber] == 'X')
		Graphic::setTextColor(Graphic::Color::Red);
	if (cells[cellNumber] == '0')
		Graphic::setTextColor(Graphic::Color::Blue);
	cout << cells[cellNumber];
	Graphic::setTextColor(Graphic::Color::Green);

}
void Field::print()
{
	Graphic::setTextColor(Graphic::Color::Green);
	Graphic::topBorder();
	cout << endl << "º  ";
	printCell(0);
	cout << "  º  ";
	printCell(1);
	cout << "  º  ";
	printCell(2);
	cout << "  º ";
	Graphic::innerBorder();
	cout << endl << "º  ";
	printCell(3);
	cout << "  º  ";
	printCell(4);
	cout << "  º  ";
	printCell(5);
	cout << "  º ";
	Graphic::innerBorder();
	cout << endl << "º  ";
	printCell(6);
	cout << "  º  ";
	printCell(7);
	cout << "  º  ";
	printCell(8);
	cout << "  º ";
	Graphic::bottomBorder();

}

bool Field::isMarked(char cellNumber)
{
	int cell = cellNumber - '0';
	if (cells[cell - 1] == 'X' || cells[cell - 1] == '0')
		return true;
	else return false;
}

char& Field::cell(int row, int col)
{
	return cells[row*3+col];
}


string Field::getWinner()
{
	int counterX = 0;
	int counter0 = 0;

	for (int i = 0; i < 8; ++i)
	{
		counterX = 0;
		counter0 = 0;
		for (int k = 0; k < 3; k++)
		{
			if (cells[lines[i][k]] == 'X')
				counterX++;
			if (cells[lines[i][k]] == '0')
				counter0++;

			if (counterX == 3)
				return "First";
			if (counter0 == 3)
				return "Second";

		}
	}
	return "";
}
	/*
	char playersArray[2] = { 'X', '0' };
	for (int i = 0; i < 2; i++)
	{
		const char value = playersArray[i];
		if (cell(0,0) == value && cells[1] == value && cells[2] == value ||
			cells[0] == value && cells[3] == value && cells[6] == value ||
			cells[3] == value && cells[4] == value && cells[5] == value ||
			cells[6] == value && cells[7] == value && cells[8] == value ||
			cells[2] == value && cells[5] == value && cells[8] == value ||
			cells[1] == value && cells[4] == value && cells[7] == value ||
			cells[2] == value && cells[4] == value && cells[6] == value ||
			cells[0] == value && cells[4] == value && cells[8] == value)
		{
			if (value == 'X')
				return "First";
			if (value == '0')
				return "Second";
		}
	}
	return "";
	*/


