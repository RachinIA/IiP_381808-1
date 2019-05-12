#include "Kassa.h"



Kassa::Kassa()
{
	Length = ValidLength = Delta = 0; T1 = nullptr; Value = nullptr; 
	
	Sklad=0;	
	
	Sum = 0;
}

Kassa::Kassa(int _ValidLength, istream& _input, int _Delta)
{
	_input >> Sklad;			//Считывание склада

	Length = 0; ValidLength = _ValidLength; Delta = _Delta; Sum = 0;
	
	T1 = new Tovar[ValidLength];
	Value = new int[ValidLength];
	memset(Value, 0, ValidLength * sizeof(int)); //Обнуление
}

Kassa::Kassa(const Kassa& c)
{
	Sklad = c.Sklad;
	Length = c.Length;
	ValidLength = c.ValidLength;
	Delta = c.Delta;
	Sum = c.Sum;
	T1 = new Tovar[ValidLength];
	Value = new int[ValidLength];
	for(int i = 0; i < Length; i++)
	{
		T1[i] = c.T1[i];
		Value[i] = c.Value[i];
	}
	
}


Kassa::~Kassa()
{
	Sum = Length = ValidLength = Delta =  0;
	if (T1 != nullptr)
		delete[] T1;
	if (Value != nullptr)
		delete[] Value;
	
}

void Kassa::Add(int _Code)
{
	Tovar* _T = Sklad.CheckTovar(_Code);	//Поиск товара по коду
	if (_T != nullptr)		
	{//Товар есть
		int k = CheckTovar(_Code);
		if (k != -1)
		{
			Value[k]++;
		}
		else
		{
			if (ValidLength - Length > 0)
			{

				T1[Length] = *_T;
				Value[Length]++;
				Length++;
			}
			else
			{
				ifstream _input("input.txt");

				Kassa _Kassa(ValidLength + Delta, _input, Delta);
				for (int i = 0; i < Length; i++)
				{
					_Kassa.T1[i] = T1[i];
					_Kassa.Value[i] = Value[i];
				}
				_Kassa.Length = Length;
				_Kassa.T1[Length] = *_T;
				_Kassa.Length++;
				*this = _Kassa;
			}
		}
		Sum += (*_T).CheckPrice() * (100 - (double)(*_T).CheckDiscount()) / 100;
		cout << _T->CheckName()<<" добавлен в чек" << endl;
	}
	else cout << "Товар отсутствует на складе" << endl;
}

int Kassa::CheckTovar(int _Code)
{
	int i;
	bool f = false;
	for (i = 0; i < Length; i++)
		if (T1[i].CheckCode() == _Code)
		{
			f = true;
			break;
		}
	if (f)
		return i;
	else
		return -1;
}

void Kassa::DescTovar(int _Code)
{
	Tovar* _T = Sklad.CheckTovar(_Code);
	if (_T != nullptr)
		cout << *_T << endl;
	else
		cout << "Товар не найден!"<<endl;
}

void Kassa::Delete(int _Code)
{
	bool b = false;
	for (int i = 0; i < Length; i++)
	{
		if (T1[i].CheckCode() == _Code)
		{
			Sum -= T1[i].CheckPrice() * (100 - (double)T1[i].CheckDiscount()) / 100 * Value[i];

			for (int j = i; j < Length; j++)
			{
				T1[j] = T1[j + 1];
				Value[j] = Value[j + 1];
			}
			Length--;
			b = true;

		}
	}
	if (b)
	cout << "Удаление успешно" << endl;
	else
	cout << "Данный товар отсутвует в чеке" << endl;
}

void Kassa::Shop(ostream & stream)
{
	
	stream << "=====================================================" << endl;
	stream << "Шт.к. | Наименование | Кол-во | Цена шт. | Стоимость " << endl;
	stream << "=====================================================" << endl;
	for (int i = 0; i < Length; i++)
	{
		stream.setf(ios::left);
		stream << T1[i].CheckCode() << ' ';
		stream.width(12);
		stream << T1[i].CheckName() << ' ';
		stream.width(6);
		stream << Value[i] << ' ';
		stream.width(8);
		stream << fixed << setprecision(2) << (T1[i].CheckPrice() * (100 - (double)T1[i].CheckDiscount()) / 100) << ' ';
		stream.width(9);
		stream << fixed << setprecision(2) << (T1[i].CheckPrice() * (100 - (double)T1[i].CheckDiscount()) / 100) * Value[i] << endl;
	}
	stream << "=====================================================" << endl;
	stream << "ИТОГО: " << Sum << " рублей" << endl;
	stream << "=====================================================" << endl;
}

Kassa& Kassa::operator=(const Kassa & c)
{
	if (this != &c)
	{
		if (ValidLength != c.ValidLength)
		{
			if (T1 != nullptr) 
				delete[] T1;
			ValidLength = c.ValidLength;
			T1 = new Tovar[ValidLength];
			Value = new int[ValidLength];
		}
		Length = c.Length;
		Delta = c.Delta;
		Sum = c.Sum;
		for (int i = 0; i < ValidLength; i++) 
		{
			T1[i] = c.T1[i];
			Value[i] = c.Value[i];
		}
	}
	return *this;


}
