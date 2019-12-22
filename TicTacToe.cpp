/*
 ~~~~~~~~~~ Ввод номера ячейки
 ~~~~~~~~~~ Обновление поля cверху
 ~~~~~~~~~~ Провека на выигрыш\проигрыш
 ~~~~~~~~~~ Проверка на уже введённый номер ячейки
 - Компьютерный игрок
 ~~~~~~~~~~ Запрос на повторную игру
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


int main()
{
	char firstPlayer = 'X';
	char secondPlayer = '0';
	char answerNewGame;
	do {
		Field field;
		field.print();
		do
		{
			if (!input(field, "\n~~~First player\n", firstPlayer))
				return 0;
			system("cls");
			field.print();
			if (field.getCounter() >= 9 )
			{
				if (field.getWinner())
				{
					cout << " player is winner";
				}
				else cout << endl << "Dead heat";
				break;
			}	
			if (!input(field, "\n~~~Second player\n", secondPlayer))
				return 0;
			system("cls");
			field.print();
		} 
		while (field.getCounter() < 9 || !(field.getWinner()));
		_getch();

		cout << endl << "Enter \"y\" for start a new game: ";
		cin >> answerNewGame;
	} while (answerNewGame == 'y');
}
