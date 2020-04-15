#include "Graphic.h"
#include <windows.h>
#include <iostream>
using namespace std;

namespace Graphic
{
	void setBaseColors()
	{
		system("color F0");
	}
	void setTextColor(Color color)
	{
		WORD param = 0;
		switch(color)
		{
		case Color::Red: param = FOREGROUND_RED; break;
		case Color::Blue: param = FOREGROUND_BLUE; break;
		case Color::Green: param = FOREGROUND_GREEN; break;
		defult: throw 1;
		}
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut, param);
		//SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
	}

	void topBorder()
	{
		cout << endl << "������������������\xBB";
	}

	void bottomBorder()
	{
		cout << endl << "������������������\xBC";
	}

	void innerBorder()
	{
		cout << endl << "�����������������͹";
	}

	void verticalBorder()
	{
		cout << endl << "  �  ";
	}
}