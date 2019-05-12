#include "Sklad.h"



Sklad::Sklad()
{
	N = 0;
	T = nullptr;

}

Sklad::Sklad(int _N)
{
	N = _N;
	T = new Tovar[N];

}

Sklad::Sklad(const Sklad & c)
{
	N = c.N;
	T = new Tovar[N];
	for (int i = 0; i < N; i++)
		T[i] = c.T[i];
}


Sklad::~Sklad()
{
	N = 0;
	delete[] T;
	T = nullptr;
}

Sklad& Sklad::operator=(const Sklad& c)
{
		if (N != c.N)
		{
			delete[] T;
			N = c.N;
			T = new Tovar[N];
		}
		for (int i = 0; i < N; i++)
			T[i] = c.T[i];
	return *this;
}

Tovar* Sklad::CheckTovar(int _Code)
{
	int i;
	bool b=false;
	for(i=0;i<N;i++)
		if (_Code == T[i].CheckCode())
		{
			b = true;
			break;
		}
	if (b == true)
		return &T[i];
	else
		return nullptr;
}

ostream & operator<<(ostream & stream, const Sklad & c)
{
	for (int i = 0; i < c.N; i++)
		stream << c.T[i] << endl;;
	return stream;
}

istream & operator>>(istream & stream, Sklad& c)
{
	stream >> c.N;
	c.T = new Tovar[c.N];
	for (int i = 0; i < c.N; i++)
		stream >> c.T[i];
	return stream;
}