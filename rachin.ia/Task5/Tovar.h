#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>

using namespace std;

class Tovar
{
private:
	int Code;	//Штрих код
	string Name;	//Наименование 
	int Price;	//Стоимость за единицу
	int Discount;	//Скидка от стоимости

public:

	Tovar();	//Конструктор по умолчанию
	Tovar(int _code,string _name,int _price,int _discount);		//Конструктор инициализации
	~Tovar();		//Деструктор
	
	int CheckCode();		//Узнать Штрих Код
	string CheckName();		//Узнать Наименование
	int CheckPrice();		//Узнать цену
	int CheckDiscount();		//Узнать скидку

	Tovar& operator=(const Tovar& c);		//Перегрузка Присваивания
	friend ostream& operator<<(ostream& stream, const Tovar& c);	//Перегрузка Вывода
	friend istream& operator>>(istream& stream, Tovar& c);		//Перегрузка Ввода
};

ostream& operator<<(ostream& stream, const Tovar& c);	//Перегрузка Вывода
istream& operator>>(istream& stream, Tovar& c);		//Перегрузка Ввода