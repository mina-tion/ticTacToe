/*
 - Ввод номера ячейки
 - Обновление поля вверху
 - Провека на выигрыш\проигрыш
 - Проверка на уже введённый номер ячейки
 - Компьютерный игрок
 - Запрос на повторную игру
*/

#include <iostream>
#include <conio.h>
#include "Field.h"
using namespace std;


bool input(Field& field, string str, string value)
{
	string cellNumber = "0";
	while (cellNumber > "9" || cellNumber < "1")
	{
		cout << str << "Enter cell number or \"e\" for exit: ";
		cin >> cellNumber;
		if (cellNumber == "e")
			return false;
		if (cellNumber > "9" || cellNumber < "1")
			cout << "\nUncorrect! Try again. ";
	}
	field.changeCell(cellNumber, value);
	return true;
}

int main()
{
	string firstPlayer = "X";
	string secondPlayer = "0";
	Field field;
	do
	{
		field.print();
		if (!input(field, "\n~~~First player\n", firstPlayer))
			return 0;
		if (!input(field, "\n~~~Second player\n", secondPlayer))
			return 0;

	} while (field.getCounter() < 9);

	_getch();
}
