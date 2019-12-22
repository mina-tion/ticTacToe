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
	cout << endl << "ษอออออหอออออหอออออ\xBB";
}

void Graphic::bottomBorder()
{
	cout << endl << "ศอออออสอออออสอออออ\xBC";
}

void Graphic::innerBorder()
{
	cout << endl << "ฬอออออฮอออออฮอออออน";
}

void Graphic::verticalBorder()
{
	cout << endl << "  บ  ";
}
