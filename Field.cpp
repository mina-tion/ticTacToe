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

