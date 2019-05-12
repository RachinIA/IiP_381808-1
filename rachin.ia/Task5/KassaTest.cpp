#include <string>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include "Kassa.h"

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	ifstream input("input.txt");

	Kassa K(5,input);
	input.close();

	cout << "Касса работает..." <<endl;

	cout << "<1> Сканировать товар" << endl;
	cout << "<2> Удалить товар из чека" << endl;
	cout << "<3> Сформировать чек" << endl;
	cout << "<4> Узнать о товаре" << endl;
	cout << "<5> Выход" << endl;
	cout << endl;
	

	do
	{
		int j;

		cout << "Введите команду: ";
		cin >> j;

		switch (j)
		{
		case 1:
		{
			int Code;
			cout << "Введите штрихкод: ";
			cin >> Code;
			K.Add(Code);
			break;
		}

		case 2:
		{
			int Code;
			cout << "Введите штрихкод: ";
			cin >> Code;
			K.Delete(Code);
			break;
		}

		case 3:
		{
			K.Shop(cout);
			break;
		}

		case 4:
		{
			int Code;
			cout << "Введите штрихкод: ";
			cin >> Code;
			K.DescTovar(Code);
			break;
		}

		case 5:
			return;

		default:
			cout << "Неправильный ввод, повторите попытку1" << endl;
		}
	} while (true);
}