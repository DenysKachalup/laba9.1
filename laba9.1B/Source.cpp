#include<iostream>	
#include<iomanip>
#include<Windows.h>
#include<string>
#include <fstream>


using namespace std;

enum Spec{ KN, INF, MT, PH };
string specStd[] = { "��������� �����","�����������","����������","Գ����" };

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
	cout << "| � | ������� | ���� | ������������| �����. | Գ���� | ������������� | ���.���. | �����. |"<<endl;
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
		cout << "����� ��������: " << i + 1 << endl;
		cin.get(); 
		cin.sync();

		cout << "�������: "; getline(cin, s[i].prizv);
		cout << "����: "; cin >> s[i].kurs;
		cout << "������������: ( 0 - ��������� �����, 1 - �����������, 2 - ����������, 3 - Գ����): ";
		cin >> spec;
		s[i].special = (Spec)spec;
		cout << "������ � ����������: "; cin >> s[i].math;
		cout << "������ � ������: "; cin >> s[i].Phis;

		switch (s[i].special)
		{
		case KN:
			cout << "������ � ��������������: "; cin >> s[i].progr;
			break;
		case INF:
			cout << "������ � ��������� ������: "; cin >> s[i].chisl;
			break;
		case MT:
		case PH:
			cout << "������ � ���������: "; cin >> s[i].pedag;
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
	cout << "������ ������� ��������: "; cin >> n;
	cout << endl;
	cout << "������ ���� ����� ���������� (5,10,12,100):"; cin >> q;
	Student* s = new Student[n];

	string prizv;
	int kurs;
	Spec special;

	Creat(s, n);
	print(s, n);

	int k = 0;
	Bal(s, n,k);
	cout << endl;
	cout <<"������� � ����� ��������� ������� ���: "<< s[k].prizv << endl;
	cout << endl;
	cout << "ʳ������ ���������� ������" << Zadov(s, n, q) << endl;;
	return 0;
}
