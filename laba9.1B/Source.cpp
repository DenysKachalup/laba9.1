#include<iostream>	
#include<iomanip>
#include<Windows.h>
#include<string>
#include <fstream>


using namespace std;

enum Spec{ KN, INF, MT, PH };
string specStd[] = { "Компютерні науки","Інформатика","Математика","Фізика" };

struct Student
{
	string prizv;
	int kurs;
	Spec special;
	short Phis;
	short math;
	union 
	{
		short progr;
		short chisl;
		short pedag;
	};
};
void print(Student* s, const int n)
{
	cout << "============================================================================================" << endl;
	cout << "| № | Прізвище | Курс | Спеціальність| Матем. | Фізика | Програмування | Чис.мет. | Педаг. |"<<endl;
	cout << "============================================================================================" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "|" << setw(3) << i + 1 << "| " << setw(8) 
			<< s[i].prizv << " |" << setw(6) << s[i].kurs << "|" << setw(14) 
			<< specStd[s[i].special] << "|" << setw(8) << s[i].math << "|" << setw(8) << s[i].Phis << "|";
		switch (s[i].special)
		{
		case KN:
			cout << setw(15) << s[i].progr << "|" << setw(10) << " " << "|" << setw(8) << " "<< "|" << endl;
			break;
		case INF:
			cout << setw(15) << " " << "|" << setw(10) << s[i].chisl << "|" << setw(8) << " " << "|" << endl;
			break;
		case MT:
		case PH:
			cout << setw(15) << " " << "|" << setw(10) << " " << "|" << setw(8) << s[i].pedag << "|" << endl;
			break;
		}
		//<< setw(15) << s[i].progr << "|" << setw(10) << s[i].chisl << "|" << setw(9) << s[i].pedag << "|" << endl;
	}


	cout << "============================================================================================" << endl;



}
void Creat(Student* s, const int n)
{
	int spec;
	for (int i = 0; i < n; i++)
	{
		cout << "Номер студента: " << i + 1 << endl;
		cin.get(); 
		cin.sync();

		cout << "Прізвище: "; getline(cin, s[i].prizv);
		cout << "Курс: "; cin >> s[i].kurs;
		cout << "Спеціальність: ( 0 - Компютерні науки, 1 - Інформатика, 2 - Математика, 3 - Фізика): ";
		cin >> spec;
		s[i].special = (Spec)spec;
		cout << "Оцінка з математики: "; cin >> s[i].math;
		cout << "Оцінка з фізики: "; cin >> s[i].Phis;

		switch (s[i].special)
		{
		case KN:
			cout << "Оцінка з програмуванння: "; cin >> s[i].progr;
			break;
		case INF:
			cout << "Оцінка з чисельних методів: "; cin >> s[i].chisl;
			break;
		case MT:
		case PH:
			cout << "Оцінка з педагогіки: "; cin >> s[i].pedag;
			break;
		}
		cout << endl;
	}
}
void Bal(Student* s, const int n,int &k)
{
	int min=s[0].math ;
	
	for (int i = 0; i < n; i++)
	{
		
		int b = (s[i].math + s[i].Phis + s[i].progr)/3;
		if (min >=b)
		{
			min = b;
			k = i;
		}
	}
	
}
int Zadov(Student* s, const int n,const int q)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (q == 5)
		{
			if (s[i].math == 3)
				k++;
			if (s[i].Phis == 3)
				k++;
			if (s[i].progr == 3)
				k++;
		}
		if (q == 10)
		{
			if (4 <=s[i].math&& s[i].math <=6)
				k++;
			if (4 <= s[i].Phis && s[i].Phis <= 6)
				k++;
			if (4 <= s[i].progr && s[i].progr <= 6)
				k++;
		}
		if (q == 12)
		{
			if (7 <= s[i].math && s[i].math <= 9)
				k++;
			if (7 <= s[i].Phis && s[i].Phis <= 9)
				k++;
			if (7 <= s[i].progr && s[i].progr <= 9)
				k++;
		}
		if (q == 100)
		{
			if (40<= s[i].math && s[i].math <= 60)
				k++;
			if (40<= s[i].Phis && s[i].Phis <= 60)
				k++;
			if (40 <= s[i].progr && s[i].progr <= 60)
				k++;
		}

	}
	return k;
}
int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	int q;
	int n;
	cout << "Введіть кількість студентів: "; cin >> n;
	cout << endl;
	cout << "Введіть свою шкалу оцінювання (5,10,12,100):"; cin >> q;
	Student* s = new Student[n];

	string prizv;
	int kurs;
	Spec special;

	Creat(s, n);
	print(s, n);

	int k = 0;
	Bal(s, n,k);
	cout << endl;
	cout <<"Студент у якого найменший середній бал: "<< s[k].prizv << endl;
	cout << endl;
	cout << "Кількість задовільних оцінок" << Zadov(s, n, q) << endl;;
	return 0;
}
