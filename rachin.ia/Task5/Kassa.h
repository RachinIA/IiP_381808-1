#pragma once
#include "Tovar.h"
#include "Sklad.h"


using namespace std;

class Kassa
{
private:
	Sklad Sklad;	//Склад
	int Length, ValidLength, Delta;	// Длина доступная, Длина занятая(действительная), дельта прибавки
	Tovar* T1; //Массив товаров 
	int* Value; //Кол-во каждого товара
	double Sum;	 //Итоговая Сумма
	//int FindItemByBarcode(int barcode) const; //Поиск товара по штрихкоду

public:
	Kassa();	//По умолчанию
	Kassa(int _ValidLength, istream& _input, int _Delta = 10); //Констуктор инициализатор (Действительная длина,Дельта, Поток)
	Kassa(const Kassa& c);		//Копирования
	~Kassa();		//Деструктор
	//По штрих коду
	void Add(int Code);		//Добавить товар
	int CheckTovar(int _Code);		//Найти товар в чеке
	void DescTovar(int Code);		//Найти данные по товару на складе
	void Delete(int _Code);	//false если товар отсутвует в чеке


	void Shop(ostream& stream);		//Сформировать чек

	Kassa& operator=(const Kassa&);		//Перегрузка присваивания
};

