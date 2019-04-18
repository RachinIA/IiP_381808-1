#pragma once
#include "Song.h";


class SongWriter
{
private:
	int Length, ValidLength, Delta;	//Длина, Действительная длина
	Song *song;
public:
	//Конструкторы
	SongWriter();		//По умолчанию
	SongWriter(int l, int x);		//Инициализации
	SongWriter(const SongWriter& c);		//Копирования
	~SongWriter();		//Деструктор

	void SortWriter(Song *list, int last);		//Сортировка песен
	void AddSong(const Song& c);		//Добавить песню
	void Change(string& _T, string& _Poet, string& _Composer, string& _Executor, string& _Album, Date _d);		//Изменить данные песни по названию
	void Search(string& _Title, string& _Executor);		//Поиск песни по названию и исполнителю
	void CheckFromPoet(string& _Poet);		//Песни по поэту
	void CheckFromComposer(string& _Composer);		//Песни по композитору 
	void CheckFromExecutor(string& _Executor);		//Песни по исполнителю
	int CheckValue();		//Получить количество песен
	void Delete(string& _Title);		//Удалить песню
	bool CheckFromTitle(string& _Title);		//Есть ли песня


	friend ostream& operator<<(ostream& stream, const SongWriter& c);	//Перегрузка Вывода
	friend istream& operator>>(istream& stream, SongWriter& c);		//Перегрузка Ввода
};

ostream& operator<<(ostream& stream, const SongWriter& c);		//Вывод
istream& operator>>(istream& stream, SongWriter& c);		//Ввод
