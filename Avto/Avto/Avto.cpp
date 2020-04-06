

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream in("e:\\avto.txt");
ofstream out("e:\\avto.txt", ios::app);

struct avt
{
	int id;
	string marka;
	string model;
	string status;
	string color;
	int statusBuy;
	avt *next, *pred;
};

class Avto
{
public:
	Avto();

	int createAvto()
	{

		while (!in.eof()) 
		{
			if (in)
			{
				avt *temp = new avt;
				in >> temp->id >> temp->marka >> temp->model >> temp->status >> temp->color >> temp->statusBuy;
				if (temp->id > 0)
				{
					Count++;
					temp->next = 0; temp->pred = 0;
					if (Tail) { Tail->next = temp; temp->pred = Tail; }
					if (!Head)Head = temp;

					Tail = temp;

				}
				else break;
			}

		}

		if (Count == 0) return 1;
		return 0;
	}

	void WriteAll()
	{
		if (Count != 0)
		{
			avt *temp = Head;
			while (temp !=  0)
			{
				cout << temp->id << "\t" << temp->marka << "\t" << temp->model << "\t" << temp->status << "\t" << temp->color << "\t" << temp->statusBuy << endl;
				temp = temp->next;
			}
		}
	}

	void searchId()
	{
		if (Count != 0)
		{
			int id;
			int chec=0;
			cout << "Укажите ID"<<endl;
			cin >> id;
			avt *temp = Head;
			while (temp != 0)
			{
				if (temp->id == id)
				{
					cout << temp->id<<"\t" << temp->marka << "\t" << temp->model << "\t" << temp->status << "\t" << temp->color << "\t" << temp->statusBuy << endl;
					temp = temp->next;
					chec++;
				}
				else temp = temp->next;
			}
			if (chec == 0)cout << "Такого ID нет" << endl;
		}
	}


	void searchMarka()
	{
		if (Count != 0)
		{
			string marka;
			int chec = 0;
			cout << "Укажите марку авто" << endl;
			cin >> marka;
			avt *temp = Head;
			while (temp != 0)
			{
				if (temp->marka == marka)
				{
					cout << temp->id << "\t" << temp->marka << "\t" << temp->model << "\t" << temp->status << "\t" << temp->color << "\t" << temp->statusBuy << endl;
					temp = temp->next;
					chec++;
				}
				else temp = temp->next;
			}
			if (chec == 0)cout << "Такого марки нет" << endl;
		}
	}


	void searchStatus()
	{
		if (Count != 0)
		{
			string status;
			int chec = 0;
			cout << "Укажите статус авто" << endl;
			cin >> status;
			avt *temp = Head;
			while (temp != 0)
			{
				if (temp->status == status)
				{
					cout << temp->id << "\t" << temp->marka << "\t" << temp->model << "\t" << temp->status << "\t" << temp->color << "\t" << temp->statusBuy << endl;
					temp = temp->next;
					chec++;
				}
				else temp = temp->next;
			}
			if (chec == 0)cout << "Такого статуса нет" << endl;
		}
	}



	void AddNewAvto()
	{
		avt *temp = new avt;
		temp->next = 0;
		temp->id = ++Count;
		out << temp->id << "\t";
		cout << "Марка: " << endl;
		cin >> temp->marka;
		out << temp->marka<<"\t";
		cout << "Модель: " << endl;
		cin >> temp->model;
		out << temp->model << "\t";
		cout << "Статус: " << endl;
		cin >> temp->status;
		out << temp->status << "\t";
		cout << "Цвет: " << endl;
		cin >> temp->color;
		out << temp->color << "\t";
		cout << "Продана ли: " << endl;
		cin >> temp->statusBuy;
		out << temp->statusBuy<< endl;
		temp->pred = Tail;
		if (Tail != 0)Tail->next = temp;
		if (Count == 0)Head = Tail = temp;
		else { Tail = temp; Count++; }
	}
private:
	avt *Head, *Tail;
	int Count;
};

Avto::Avto()
{
	Head = Tail = 0;
	Count = 0;
}

void Go();
void Go1();

int main()
{
	setlocale(LC_ALL, "rus");

	int otv;
	int stbase;
	Avto mainAvto;

	if (!in.is_open() || !out.is_open())
	{
		cout << "Файл не найден";   return 1;
	}

	stbase=mainAvto.createAvto();

	
	switch (stbase)
	{
	case 1:
		cout << "База пуста"<<endl;
		Go1();
		break;
	case 0:
		Go();
		break;
	default:
		break;
	}
	cin >> otv;
	switch (otv)
	{
	case 1:
		system("cls");
		mainAvto.searchId();
		break;
	case 2:
		system("cls");
		mainAvto.searchMarka();
		break;
	case 3:
		system("cls");
		mainAvto.searchStatus();
		break;
	case 4:
		system("cls");
		mainAvto.AddNewAvto();
		break;
	case 5:
		system("cls");
		cout << "By";
		return 0;
		break;
	default:
		break;
	}

	in.close();
	out.close();
	
}

void Go()
{
	cout << "\t\tБАЗА ДАННЫХ ПО АВТО" << endl
		<< "1\t Поиск по ID" << endl
		<< "2\t Поиск по марке" << endl
		<< "3\t Поиск по статусу" << endl
		<< "4\t Добавить новое авто" << endl
		<< "5\t ВЫХОД" << endl;

}
void Go1()
{
	cout << "\t\tБАЗА ДАННЫХ ПО АВТО" << endl
		<< "4\t Добавить новое авто" << endl
		<< "5\t ВЫХОД" << endl;

}
