#include <iostream>
#include <conio.h>
using namespace std;

class Field
{
private:
	string cells[3][3];
	int counter = 0;
public:

	Field()
	{
		cells[0][0] = "1";
		cells[0][1] = "2";
		cells[0][2] = "3";
		cells[1][0] = "4";
		cells[1][1] = "5";
		cells[1][2] = "6";
		cells[2][0] = "7";
		cells[2][1] = "8";
		cells[2][2] = "9";
	}


	void changeCell(string cellNumber, string value)
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
		print();

	}

	int getCounter()
	{
		return counter;
	}

	void print()
	{
		cout << endl << "ษอออออหอออออหอออออ\xBB";
		cout << endl << "บ  " << cells[0][0] << "  บ  " << cells[0][1] << "  บ  " << cells[0][2] << "  บ";
		cout << endl << "ฬอออออฮอออออฮอออออน";
		cout << endl << "บ  " << cells[1][0] << "  บ  " << cells[1][1] << "  บ  " << cells[1][2] << "  บ";
		cout << endl << "ฬอออออฮอออออฮอออออน";
		cout << endl << "บ  " << cells[2][0] << "  บ  " << cells[2][1] << "  บ  " << cells[2][2] << "  บ";
		cout << endl << "ศอออออสอออออสอออออ\xBC";
	}

};

void input(Field& field, string str, string value)
{
	string cellNumber = "0";
	while (cellNumber > "9" || cellNumber < "1")
	{
		cout << str << "Enter cell number: ";
		cin >> cellNumber;
		if (cellNumber > "9" || cellNumber < "1")
			cout << "\nUncorrect! Try again. ";
	}
	field.changeCell(cellNumber, value);
}

int main()
{
	string firstPlayer = "X";
	string secondPlayer = "0";
	Field field;
	do
	{
		field.print();
		input(field, "\n~~~First player\n", firstPlayer);

		input(field, "\n~~~Second player\n", secondPlayer);

	} while (field.getCounter() < 9);

	_getch();
}
