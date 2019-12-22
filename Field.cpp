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

void Field::print()
{
	
	Graphic::topBorder();
	cout << endl << "º  " << cells[0] << "  º  " << cells[1] << "  º  " << cells[2] << "  º";
	Graphic::innerBorder();
	cout << endl << "º  " << cells[3] << "  º  " << cells[4] << "  º  " << cells[5] << "  º";
	Graphic::innerBorder();
	cout << endl << "º  " << cells[6] << "  º  " << cells[7] << "  º  " << cells[8] << "  º";
	Graphic::bottomBorder();
	Graphic::setTextColor(9, 0);
	
}

bool Field::isMarked(char cellNumber)
{
	int cell = cellNumber - '0';
	if (cells[cell - 1] == 'X' || cells[cell - 1] == '0')
		return true;
	else return false;
}

bool Field::getWinner()
{
	char playersArray[2] = { 'X', '0' };
	for (int i = 0; i < 2; i++)
	{
		if (cells[0] == playersArray[i] && cells[1] == playersArray[i] && cells[2] == playersArray[i] ||
			cells[0] == playersArray[i] && cells[3] == playersArray[i] && cells[6] == playersArray[i] ||
			cells[3] == playersArray[i] && cells[4] == playersArray[i] && cells[5] == playersArray[i] ||
			cells[6] == playersArray[i] && cells[7] == playersArray[i] && cells[8] == playersArray[i] ||
			cells[2] == playersArray[i] && cells[5] == playersArray[i] && cells[8] == playersArray[i] ||
			cells[1] == playersArray[i] && cells[4] == playersArray[i] && cells[7] == playersArray[i] ||
			cells[2] == playersArray[i] && cells[4] == playersArray[i] && cells[6] == playersArray[i] ||
			cells[0] == playersArray[i] && cells[4] == playersArray[i] && cells[8] == playersArray[i])

		{
			if (playersArray[i] == 'X')
			{
				cout << endl << "First";
				return true;
			}
			if (playersArray[i] == '0')
			{
				cout << endl << "Second";
				return true;
			}
		}
	}
	return false;
	
}

