#include "Song.h"



Song::Song()
{
	Title = "";
	Poet = "";
	Composer = "";
	Executor = "";
	Album = "";
	d = { 0,0,0 };
}

Song::Song(const string& _Title, const string& _Poet, const string& _Composer, const string& _Executor, const string& _Album, Date _d)
{
	Title = _Title;
	Poet = _Poet;
	Composer = _Composer;
	Executor = _Executor;
	Album = _Album;
	d = _d;
}

Song::~Song()
{
	Title = "";
	Poet = "";
	Composer = "";
	Executor = "";
	Album = "";
	d = {0,0,0};
}

string Song::CheckT()const
{
	return Title;
}
string Song::CheckP()const
{
	return Poet;
}
string Song::CheckC()const
{
	return Composer;
}
string Song::CheckE()const
{
	return Executor;
}
string Song::CheckA()const
{
	return Album;
}
Date Song::Checkd()
{
	return d;
}

void Song::SetT(const string& i)
{
	Title = i;
}
void Song::SetP(const string& i)
{
	Poet = i;
}
void Song::SetC(const string& i)
{
	Composer = i;
}
void Song::SetE(const string& i)
{
	Executor = i;
}
void Song::SetA(const string& i)
{
	Album = i;
}
void Song::Setd(Date _d)
{
	d = _d;
}

Song& Song::operator=(const Song& c)
{
	Title = c.Title;
	Poet = c.Poet;
	Composer = c.Composer;
	Executor = c.Executor;
	Album = c.Album;
	d = c.d; 
	return *this;

}

bool Song::operator<(const Song& c)
{
	return Title < c.Title;
}

bool Song::operator>(const Song& c)
{
	return Title > c.Title;
}

ostream& operator<<(ostream& stream, const Song& c)
{
	stream << c.Title << " ";
	stream << c.Poet << " ";
	stream << c.Composer << " ";
	stream << c.Executor << " ";
	stream << c.Album << " ";
	stream << c.d.Day<<'.'<<c.d.Month<<'.'<<c.d.Year<<endl;
	return stream;
}
istream& operator>>(istream& stream, Song& c)
{
	stream >> c.Title;
	stream >> c.Poet;
	stream >> c.Composer;
	stream >> c.Executor;
	stream >> c.Album;
	stream >> c.d.Day;
	stream >> c.d.Month; 
	stream >> c.d.Year;
	return stream;
}