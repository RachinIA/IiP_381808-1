#include "Polinom.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");
	double x;
	int d;
	cin >> d;
	Polinom T(d);
	for (int j = 0; j < d + 1; j++)cin >> T[j];
	T.Output();
	cout << endl;
	T.devar().Output();
	cout << endl;
	cin >> x;
	cout<<T.FuncVal(x)<<endl;
	int b;   //Степень для ввода пользователем
	cout << "Введите степень члена полинома, коэффициент которого хотите узнать:";
	cin >> b;
	cout << T.CheckCoef(b)<<endl;
	cout << T.Checkn()<<endl;
	

	system("pause");
	return 0;
}