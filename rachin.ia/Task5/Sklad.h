#pragma once
#include "Tovar.h"

using namespace std;

class Sklad
{
private:
	int N;		//Количество разных товаров
	Tovar* T;	//Товары
public:

	Sklad();
	Sklad(int _N);
	Sklad(const Sklad& c);
	~Sklad();


	Sklad& operator=(const Sklad& c);
	Tovar* CheckTovar(int _Code);

	friend ostream& operator<<(ostream& stream, const Sklad& c);	//Перегрузка Вывода
	friend istream& operator>>(istream& stream, Sklad& c);		//Перегрузка Ввода
};

ostream& operator<<(ostream& stream, const Sklad& c);	//Перегрузка Вывода
istream& operator>>(istream& stream, Sklad& c);		//Перегрузка Ввода

