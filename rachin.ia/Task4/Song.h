#pragma once
#include <fstream>;
#include <iostream>;
#include <string>
#include <clocale>
#include <conio.h>
#include "windows.h"
using namespace std;

struct Date		//Дата Выпуска песни
{		//День Месяц Год
	unsigned int Day;
	unsigned int Month;
	unsigned int Year;
	//Date();
};


class Song
{
private:
	string Title, Poet, Composer, Executor, Album;		//Название, Поэт, Композитор, Исполнитель, Название альбома
	Date d;		//Дата Выпуска песни

public:
	//Конструкторы
	Song();		//По умолчанию
	Song(const string& _Title, const string& _Poet, const string& _Composer, const string& _Executor, const string& _Album, Date _d);
	//Инициализации
	~Song();		//Деструктор
	//Получение свойств песни
	string CheckT()const;
	string CheckP()const;
	string CheckC()const;
	string CheckE()const;
	string CheckA()const;
	Date Checkd();

	//Присваивание свойств песни
	void SetT(const string& i);
	void SetP(const string& i);
	void SetC(const string& i);
	void SetE(const string& i);
	void SetA(const string& i);
	void Setd(Date _d);

	Song& operator=(const Song& c);		//Присваивание
	bool operator<(const Song& c);		//Сравнение
	bool operator>(const Song& c);		//Сравнение

	friend ostream& operator<<(ostream& stream, const Song& c);	//Перегрузка Вывода
	friend istream& operator>>(istream& stream, Song& c);		//Перегрузка Ввода
};

ostream& operator<<(ostream& stream, const Song& c);		//Вывод
istream& operator>>(istream& stream, Song& c);		//Ввод
