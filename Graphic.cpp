#include "Graphic.h"
#include <windows.h>
#include <iostream>
using namespace std;

void Graphic::setBaseColors()
{
	system("color F0");
}
void Graphic::setTextColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void Graphic::topBorder()
{
	cout << endl << "������������������\xBB";
}

void Graphic::bottomBorder()
{
	cout << endl << "������������������\xBC";
}

void Graphic::innerBorder()
{
	cout << endl << "�����������������͹";
}

void Graphic::verticalBorder()
{
	cout << endl << "  �  ";
}
