#include "Tovar.h"
#include "Sklad.h"



Tovar::Tovar()
{
	Code = Price = Discount = 0;
	Name = string();
}

Tovar::Tovar(int _code, string _name, int _price, int _discount)
{
	Code = _code;
	Name = _name;
	Price = _price;
	Discount = _discount;
}

Tovar::~Tovar()
{
	Code = Price = Discount = 0;
	Name = string();

}

int Tovar::CheckCode()
{
	return Code;
}

string Tovar::CheckName()
{
	return Name;
}

int Tovar::CheckPrice()
{
	return Price;
}

int Tovar::CheckDiscount()
{
	return Discount;
}

Tovar& Tovar::operator=(const Tovar& c)
{
	Code = c.Code;
	Name = c.Name;
	Price = c.Price;
	Discount = c.Discount;
	return *this;
}

ostream& operator<<(ostream& stream, const Tovar& c)
{
	stream << c.Code << '-';
	stream.width(12);
	stream << c.Name << " : ";
	stream.width(5);
	stream << c.Price << " / ";
	stream.width();
	stream << c.Discount;

	return stream;
}

istream& operator>>(istream& stream, Tovar& c)
{
	stream >> c.Code;
	stream >> c.Name;
	stream >> c.Price;
	stream >> c.Discount;
	return stream;
}


