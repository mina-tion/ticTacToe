﻿/*
 ~~~~~~~~~~ Ввод номера ячейки
 ~~~~~~~~~~ Обновление поля cверху
 ~~~~~~~~~~ Провека на выигрыш\проигрыш
 ~~~~~~~~~~ Проверка на уже введённый номер ячейки
 - Компьютерный игрок
 ~~~~~~~~~~ Запрос на повторную игру
 - unit test
*/

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Field.h"
#include "Graphic.h"
using namespace std;


bool input(Field& field, string str, char value)
{
	char cellNumber = '0';
	while (cellNumber > '9' || cellNumber < '1' || field.isMarked(cellNumber))
	{
		cout << str << "Enter cell number or \"e\" for exit: ";
		cin >> cellNumber;

		if (cellNumber > '9' || cellNumber < '1' || field.isMarked(cellNumber))
			cout << "\nUncorrect! Try again. ";

		if (cellNumber == 'e')
			return false;

	}
	field.changeCell(cellNumber, value);
	return true;
}

bool playGame()
{
	const char firstPlayer = 'X';
	const char secondPlayer = '0';
	Field field;
	field.print();
	bool isFirstPlayer = true;
	while (field.getCounter() < 9)
	{
		if (isFirstPlayer)
		{
			if (!input(field, "\n~~~First player\n", firstPlayer))
				return false;
			
		}
		else
		{
			if (!input(field, "\n~~~Second player\n", secondPlayer))
				return false;
		}
		isFirstPlayer = !isFirstPlayer;
		system("cls");
		field.print();

		string winResult = field.getWinner();
		if (!winResult.empty())
		{
			cout << endl << winResult << " player is winner";
			return false;
		}

	};
	cout << endl << "Dead heat";
	return true;
}

Field testField()
{
	Field result;

	result.setCell(0, '0');
	result.setCell(1, 'X');
	result.setCell(2, '0');
	result.setCell(3, 'X');
	result.setCell(4, '0');
	result.setCell(5, 'X');
	result.setCell(6, '0');
	result.setCell(7, 'X');
	result.setCell(8, '0');

	return result;
}



bool test()
{
	Field field = testField();
	string winner = field.getWinner();
	if (winner == "Second")
	{
		cout << endl << "Test success!";
		return true;
	}
	else
	{
		cout << endl << "Test fail!";
		return false;
	}
	cout << endl;
}
/*
void test()
{
	Data data = testData();
	data.sort();
	const Data expected = expectedData();
	if (data == expected)
		cout << endl << "Test success!";
	else
	{
		cout << endl << "Test fail!";
		data.print("Sorted");
		expected.print("Expected");
	}
	cout << endl;

} 
*/
int main()
{
	if (!test()) 
		return 0;
	char answerNewGame;
	do {
		if (!playGame())
			return 0;
		_getch();
		cout << endl << "Enter \"y\" for start a new game: ";
		cin >> answerNewGame;
	} while (answerNewGame == 'y');
	return 0;
}
