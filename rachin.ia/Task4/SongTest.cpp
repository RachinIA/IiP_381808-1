#include "SongWriter.h"

void outputMenu() {
	cout << "Выберите действие:\n";
	cout << "1 - Добавить песню\n";
	cout << "2 - Изменить данные песни по её названию\n";
	cout << "3 - Найти песню по названию и исполнителю\n";
	cout << "4 - Выдать все песни заданного поэта\n";
	cout << "5 - Выдать все песни заданного композитора\n";
	cout << "6 - Выдать все песни заданного исполнителя\n";
	cout << "7 - Узнать число песен и вывести их (в виде: Название Поэт Композитор Исполнитель Альбом Дата)\n";
	cout << "8 - Удалить песню по названию\n";
	cout << "9 - Сохранить песенник в файл <<output.txt>> и завершить работу\n";
	cout << "0 - <Exit>\n";

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale(LC_CTYPE, "Russian");

	SongWriter s;

	ifstream input("input.txt");
	
	input >> s;
	input.close();

	cout << s;
	cout << "Песенник загружен из файла <<input.txt>>..." << endl;

	int count = -10;

	do
	{
		outputMenu();
		cout << "--> ";
		cin >> count;
		system("cls");

		switch (count)
		{
		case 1:
		{

			string T, P, C, E, A;
			cin.ignore();
			cout << "Введите название песни: ";
			std::getline(cin,T);
			cout << "Введите автора текста: ";
			getline(cin, P);
			cout << "Введите автора музыки: ";
			getline(cin, C);
			cout << "Введите исполнителя: ";
			getline(cin, E);
			cout << "Введите альбом: ";
			getline(cin, A);
			cout << "Введите дату выхода песни (Формата: День Месяц Год): ";
			int d, m, y;
			cin >> d >> m >> y;
			Date _d{ d,m,y };
			Song K(T, P, C, E, A, _d);
			s.AddSong(K);
			cout << "Добавлено! " << endl << "Нажмите клавишу чтобы продолжить...";
		
			break;
		}

		case 2:
		{
			string T;
			cout << "Введите название нужной песни: ";
			cin.ignore();
			getline(cin, T);
			if (s.CheckFromTitle(T))
			{
				string P, C, E, A;
				P = C = E = A = "";
				int d = 0, m = 0, y = 0;
				cout << "Введите другого автора текста: ";
				getline(cin, P);
				cout << "Введите другого автора музыки: ";
				getline(cin, C);
				cout << "Введите другого исполнителя: ";
				getline(cin, E);
				cout << "Введите другой альбом : ";
				getline(cin, A);
				cout << "Введите другую дату выхода(Формата: День Месяц Год): ";
				cin >> d >> m >> y;
				Date _d{ d,m,y };

				s.Change(T, P, C, E, A, _d);
			}
			else
			{
				cout << "Песни нет в песеннике" <<endl;
			}
			break;
		}

		case 3:
		{
			string T, C;
			cin.ignore();
			cout << "Введите название песни: ";
			getline(cin, T);
			cout << "Введите исполнителя: ";
			getline(cin, C);
			s.Search(T, C);
			break;
		}

		case 4:
		{
			string P;
			cout << "Введите имя поэта: ";
			cin.ignore();
			getline(cin, P);
			s.CheckFromPoet(P);
			break;
		}

		case 5:
		{
			string C;
			cout << "Введите имя поэта: ";
			cin.ignore();
			getline(cin, C);
			s.CheckFromComposer(C);
			break;
		}

		case 6:
		{
			string E;
			cout << "Введите исполнителя: ";
			cin.ignore();

			getline(cin, E);
			s.CheckFromExecutor(E);
			break;
		}

		case 7:
		{
			cout << "Всего песен: " << s << endl;
			system("pause");
			break;
		}

		case 8:
		{
			string T;
			cin.ignore();

			cout << "Введите название необходимой песни: ";
			getline(cin, T);
			s.Delete(T);
			cout << "Удалено!"<<endl;
			break;
		}

		case 9:
		{
				ofstream output("output1.txt");
				output << s;
				output.close();
		}

		case 0:
		{return 0; }

		default:
			cout << "Неверные данные, попробуйте ещё раз!" << endl;
			break;
		}

	} while (count != 0);
}
