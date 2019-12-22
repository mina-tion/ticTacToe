#include "Field.h"
using namespace std;
Field::Field()
{
	cells[0][0] = '1';
	cells[0][1] = '2';
	cells[0][2] = '3';
	cells[1][0] = '4';
	cells[1][1] = '5';
	cells[1][2] = '6';
	cells[2][0] = '7';
	cells[2][1] = '8';
	cells[2][2] = '9';
}

void Field::changeCell(char cellNumber, char value)
{
	counter++;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (cells[i][j] == cellNumber)
			{
				cells[i][j] = value;
				cout << endl << cells[i][j];
			}
		}
}

int Field::getCounter()
{
	return counter;
}

void Field::print()
{
	cout << endl << "ษอออออหอออออหอออออ\xBB";
	cout << endl << "บ  " << cells[0][0] << "  บ  " << cells[0][1] << "  บ  " << cells[0][2] << "  บ";
	cout << endl << "ฬอออออฮอออออฮอออออน";
	cout << endl << "บ  " << cells[1][0] << "  บ  " << cells[1][1] << "  บ  " << cells[1][2] << "  บ";
	cout << endl << "ฬอออออฮอออออฮอออออน";
	cout << endl << "บ  " << cells[2][0] << "  บ  " << cells[2][1] << "  บ  " << cells[2][2] << "  บ";
	cout << endl << "ศอออออสอออออสอออออ\xBC";
}
