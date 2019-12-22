/*
 ~~~~~~~~~~ Ввод номера ячейки
 ~~~~~~~~~~ Обновление поля cверху
 - Провека на выигрыш\проигрыш
		=нужно передавать в функцию проверки структуру по ссылке
		=проверять значения по диагоналям,вертикали и горизонтали
		=возвращать false или true в случае проигрыша и выигрыша
		=вызывать эту функцию проверки после ввода значения в ячейку
 - Проверка на уже введённый номер ячейки
		=нужно передавать в функцию структуру по ссылке
		=передавать в функцию вводимую ячейку 
		=проверять все ячейки в цикле на совпадение
		=возвращать false или true в случае совпадения и несовпадения
		=вызывать функцию в input() перед установкой значений
 - Компьютерный игрок
 ~~~~~~~~~~ Запрос на повторную игру
*/

#include <iostream>
#include <conio.h>
#include "Field.h"
using namespace std;


bool input(Field& field, string str, char value)
{
	char cellNumber = '0';
	while (cellNumber > '9' || cellNumber < '1')
	{
		cout << str << "Enter cell number or \"e\" for exit: ";
		cin >> cellNumber;
		if (cellNumber == 'e')
			return false;
		if (cellNumber > '9' || cellNumber < '1')
			cout << "\nUncorrect! Try again. ";
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
			if (!input(field, "\n~~~Second player\n", secondPlayer))
				return 0;
			system("cls");
			field.print();
		} while (field.getCounter() < 9);
		_getch();

		cout << endl << "Enter \"y\" for start a new game: ";
		cin >> answerNewGame;
	} while (answerNewGame == 'y');
}
