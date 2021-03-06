﻿#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include < windows.h>

using namespace std;


// Структура полной базы авто
struct avt
{
	string id;
	string marka;
	string model;
	string status;
	string color;
	avt *next, *pred;
}; 
// Структура временного поиска авто
struct avtSlot
{
	string id;
	string marka;
	string model;
	string status;
	string color;
	avtSlot *next;
};  
// Структура базы клиетов 
struct Klient 
{
	string name;
	string id;
	string marka;
	string model;
	string status;
	string color;
	Klient *next;
};


class Avto
{
public:
	Avto()
	{
		Head = Tail = 0;
		HeadSlot = TailSlot = 0;
		Count = 0;
		CountSlot = 0;
	}
	//Начальная инициализация базы
	int CreateAvto()
	{
		ifstream avtoIn("e:\\avto.txt");// открытие файла 
		if (!avtoIn.is_open()  )
		{
			cout << "Файл не найден";   return 1;
		}

		if (Count > 0)return 0;// Если база не пуста не проводить инициализацию базы с файла 
		while (!avtoIn.eof()) // пока не конец файла 
		{
			// построчно считывем и записываем данные с файла в структуру 
				avt *temp = new avt;
				avtoIn >> temp->id >> temp->marka >> temp->model >> temp->status >> temp->color;
				if (temp->id != "")
				{
					Count++;
					temp->next = 0; temp->pred = 0;
					if (Tail) { Tail->next = temp; temp->pred = Tail; }
					if (!Head)Head = temp;

					Tail = temp;

				}
				else break;
		
		}
		avtoIn.close();
		if (Count == 0) return 1;// Предупреждает о пустоте файла 
		return 0;
	} 
	// Вывод всей базы
	void WriteAll()
	{
		if (Count != 0)
		{
			avt *temp = Head;
	
				while (temp != 0)
				{
					cout << temp->id << "\t" << temp->marka << "\t" << temp->model << "\t" << temp->status << "\t" << temp->color << "\t" << endl;
					temp = temp->next;
				}

		}
	}
	// Поиск по ИД (только во всей базе)
	void SearchId()
	{
		if (Count != 0)
		{
			string id; // ID для поиска
			int chec = 0;// флаг для обозначиния соотвецтвий
			cout << "Укажите ID"<<endl;
			cin >> id;
			system("cls");
			avt *temp = Head; 
			CountSlot = 0;
			while (temp != 0)// пока не конец структуры 
			{
					if (temp->id == id)
					{
						// Вывод полей и запись их в стековую структуру поиска
						
						cout << temp->id << "\t" << temp->marka << "\t" << temp->model << "\t" << temp->status << "\t" << temp->color << "\t"  << endl;
						temp = temp->next;

						chec++;
						break;
					}
					else temp = temp->next;		
			}	
			if (chec == 0)cout << "Такой авто нет" << endl;
		}
	}

	// Поиск по марке (во всей базе)
	void SearchMarka()
	{
		if (Count != 0)
		{
			string marka;
			int chec = 0;
			cout << "Укажите марку авто" << endl;
			cin >> marka;
			system("cls");
			avt *temp = Head;
			CountSlot = 0;
			while (temp != 0)
			{
				if (temp->marka == marka)
				{

					avtSlot *slot = new avtSlot;
					slot->id = temp->id; slot->marka = temp->marka; slot->model = temp->model; slot->status = temp->status; slot->color = temp->color; 
					cout << temp->id << "\t" << temp->marka << "\t" << temp->model << "\t" << temp->status << "\t" << temp->color << "\t" << endl;
					temp = temp->next;
					slot->next = 0;
					
					if (CountSlot == 0)
					{
						HeadSlot = TailSlot = slot;
					}
					else {
						TailSlot->next = slot;
						
						TailSlot = slot;
					}
					++CountSlot;
					chec++;

				}
				else temp = temp->next;
			}
			if (chec == 0)cout << "Такой марки нет" << endl;
		}
	}
	// Поиск по марке (в временной структуре поиска)
	void SearchMarka(int n)
	{
		if (CountSlot != 0)
		{
			string marka;
			int chec = 0;
			cout << "Укажите марку авто" << endl;
			cin >> marka;
			system("cls");
			avtSlot *temp = HeadSlot;
			CountSlot = 0;
			while (temp != 0)
			{
				if (temp->marka == marka)
				{
					avtSlot *slot = new avtSlot;
					slot->id = temp->id; slot->marka = temp->marka; slot->model = temp->model; slot->status = temp->status; slot->color = temp->color; 
					cout << slot->id << "\t" << slot->marka << "\t" << slot->model << "\t" << slot->status << "\t" << slot->color << "\t" << endl;
					temp = temp->next;
					slot->next = 0;
					
					if (CountSlot == 0)
					{
						HeadSlot = TailSlot = slot;
					}
					else {
						TailSlot->next = slot;
						
						TailSlot = slot;
					}
					++CountSlot;
					chec++;
				}
				else temp = temp->next;
			}
			if (chec == 0)cout << "Такой машины нет" << endl;
		}
	}

	// Поиск по моделе (во всей базе)
	void SearchModel()
	{
		if (Count != 0)
		{
			string model;
			int chec = 0;
			cout << "Укажите модель авто" << endl;
			cin >> model;
			system("cls");
			avt *temp = Head;
			CountSlot = 0;
			while (temp != 0)
			{
				if (temp->model == model)
				{

					avtSlot *slot = new avtSlot;
					slot->id = temp->id; slot->marka = temp->marka; slot->model = temp->model; slot->status = temp->status; slot->color = temp->color; 
					cout << temp->id << "\t" << temp->marka << "\t" << temp->model << "\t" << temp->status << "\t" << temp->color << "\t"  << endl;
					temp = temp->next;
					slot->next = 0;
					
					if (CountSlot == 0)
					{
						HeadSlot = TailSlot = slot;
					}
					else {
						TailSlot->next = slot;
						
						TailSlot = slot;
					}
					++CountSlot;
					chec++;

				}
				else temp = temp->next;
			}
			if (chec == 0)cout << "Такой модели нет" << endl;
		}
	}
	// Поиск по моделе (в временной структуре поиска)
	void SearchModel(int n)
	{
		if (CountSlot != 0)
		{
			string model;
			int chec = 0;
			cout << "Укажите модель авто" << endl;
			cin >> model;
			system("cls");
			avtSlot *temp = HeadSlot;
			CountSlot = 0;
			while (temp != 0)
			{
				if (temp->model == model)
				{
					avtSlot *slot = new avtSlot;
					slot->id = temp->id; slot->marka = temp->marka; slot->model = temp->model; slot->status = temp->status; slot->color = temp->color; 
					cout << slot->id << "\t" << slot->marka << "\t" << slot->model << "\t" << slot->status << "\t" << slot->color << "\t" << endl;
					temp = temp->next;
					slot->next = 0;
					
					if (CountSlot == 0)
					{
						HeadSlot = TailSlot = slot;
					}
					else {
						TailSlot->next = slot;
						
						TailSlot = slot;
					}
					++CountSlot;
					chec++;
				}
				else temp = temp->next;
			}
			if (chec == 0)cout << "Такой модели нет" << endl;
		}
	}


	// Поиск по статусу (во всей базе)
	void SearchStatus()
	{
		if (Count != 0)
		{
			string status;
			int chec = 0;
			cout << "Укажите статус авто" << endl;
			cin >> status;
			system("cls");
			avt *temp = Head;
			CountSlot = 0;
			while (temp != 0)
			{
				if (temp->status == status)
				{
					avtSlot *slot = new avtSlot;
					slot->id = temp->id; slot->marka = temp->marka; slot->model = temp->model; slot->status = temp->status; slot->color = temp->color;
					cout << temp->id << "\t" << temp->marka << "\t" << temp->model << "\t" << temp->status << "\t" << temp->color << "\t" << endl;
					temp = temp->next;
					slot->next = 0;
					
					if (CountSlot == 0)
					{
						HeadSlot = TailSlot = slot;
					}
					else {
						TailSlot->next = slot;
						
						TailSlot = slot;
					}
					++CountSlot;
					chec++;
				}
				else temp = temp->next;
			}
			if (chec == 0)cout << "Такого статуса нет" << endl;
		}
	}
	// Поиск по статусу (в временной структуре поиска)
	void SearchStatus(int n)
	{
		if (CountSlot != 0)
		{
			string status;
			int chec = 0;
			cout << "Укажите статус авто" << endl;
			cin >> status;
			system("cls");
			avtSlot *temp = HeadSlot;
			CountSlot = 0;
			while (temp != 0)
			{
				if (temp->status == status)
				{
					avtSlot *slot = new avtSlot;
					slot->id = temp->id; slot->marka = temp->marka; slot->model = temp->model; slot->status = temp->status; slot->color = temp->color; 
					cout << slot->id << "\t" << slot->marka << "\t" << slot->model << "\t" << slot->status << "\t" << slot->color << "\t"  << endl;
					temp = temp->next;
					slot->next = 0;
					
					if (CountSlot == 0)
					{
						HeadSlot = TailSlot = slot;
					}
					else {
						TailSlot->next = slot;
						
						TailSlot = slot;
					}
					++CountSlot;
					chec++;
				}
				else temp = temp->next;
			}
			if (chec == 0)cout << "Такого статуса нет" << endl;
		}
	}



	// Поиск по цвету (во всей базе)
	void SearchColor()
	{
		if (Count != 0)
		{
			string color;
			int chec = 0;
			cout << "Укажите цвет авто" << endl;
			cin >> color;
			system("cls");
			avt *temp = Head;
			CountSlot = 0;
			while (temp != 0)
			{
				if (temp->color == color)
				{

					avtSlot *slot = new avtSlot;
					slot->id = temp->id; slot->marka = temp->marka; slot->model = temp->model; slot->status = temp->status; slot->color = temp->color; 
					cout << temp->id << "\t" << temp->marka << "\t" << temp->model << "\t" << temp->status << "\t" << temp->color << "\t"  << endl;
					temp = temp->next;
					slot->next = 0;
					
					if (CountSlot == 0)
					{
						HeadSlot = TailSlot = slot;
					}
					else {
						TailSlot->next = slot;
					
						TailSlot = slot;
					}
					++CountSlot;
					chec++;

				}
				else temp = temp->next;
			}
			if (chec == 0)cout << "Такого цвета нет" << endl;
		}
	}
	// Поиск по цвету (в временной структуре поиска)
	void SearchColor(int n)
	{
		if (CountSlot != 0)
		{
			string color;
			int chec = 0;
			cout << "Укажите цвет авто" << endl;
			cin >> color;
			system("cls");
			avtSlot *temp = HeadSlot;
			CountSlot = 0;
			while (temp != 0)
			{
				if (temp->color == color)
				{
					avtSlot *slot = new avtSlot;
					slot->id = temp->id; slot->marka = temp->marka; slot->model = temp->model; slot->status = temp->status; slot->color = temp->color; 
					cout << slot->id << "\t" << slot->marka << "\t" << slot->model << "\t" << slot->status << "\t" << slot->color << "\t"  << endl;
					temp = temp->next;
					slot->next = 0;
					
					if (CountSlot == 0)
					{
						HeadSlot = TailSlot = slot;
					}
					else {
						TailSlot->next = slot;
						
						TailSlot = slot;
					}
					++CountSlot;
					chec++;
				}
				else temp = temp->next;
			}
			if (chec == 0)cout << "Такого цвета нет" << endl;
		}
	}

	// Добавление авто в базу
	void AddNewAvto()
	{
		ofstream avtoOut("e:\\avto.txt", ios::app);
		avt *temp = new avt;
		temp->next = 0;
		cout << "Номер: " << endl;
		cin >> temp->id;
		avtoOut << temp->id << "\t";
		cout << "Марка: " << endl;
		cin >> temp->marka;
		avtoOut << temp->marka<<"\t";
		cout << "Модель: " << endl;
		cin >> temp->model;
		avtoOut << temp->model << "\t";
		cout << "Статус: " << endl;
		cin >> temp->status;
		avtoOut << temp->status << "\t";
		cout << "Цвет: " << endl;
		cin >> temp->color;
		avtoOut << temp->color<<"\n";
		temp->pred = Tail;
		if (Tail != 0)Tail->next = temp;
		if (Count == 0)Head = Tail = temp;
		Tail = temp; ++Count; 
		avtoOut.close();
	}  
	int DelAvto()
	{
		ofstream avtoDel("e:\\avto.txt");
		if (Count != 0)
		{
			string id;
			cout << "Введите номер: ";
			cin >> id;
			int n = 1;
			avt *Del = Head;

			while (Del->id != id)
			{
				Del = Del->next;
				++n;
			}

			// Доходим до элемента, 
			// который предшествует удаляемому
			avt *PredDel = Del->pred;
			// Доходим до элемента, который следует за удаляемым
			avt *AfterDel = Del->next;

			// Если удаляем не голову
			if (PredDel != 0 && Count != 1)
				PredDel->next = AfterDel;
			// Если удаляем не хвост
			if (AfterDel != 0 && Count != 1)
				AfterDel->pred = PredDel;

			// Удаляются крайние?
			if (n == 1)
				Head = AfterDel;
			if (n == Count)
				Tail = PredDel;

			// Удаление элемента
			delete Del;

			Count--;

			if (Count != 0)
			{
				avt *temp = Head;
				while (temp != 0)
				{
					avtoDel << temp->id << "\t" << temp->marka << "\t" << temp->model << "\t" << temp->status << "\t" << temp->color << endl;
					temp = temp->next;
				}
			};
		}
		else cout << "Такого номера нет";
		avtoDel.close();
		return 0;
	}

	~Avto()
	{
		delete Head, Tail, HeadSlot, TailSlot;
	}

	friend class Client;

private:
	avt *Head, *Tail;
	avtSlot *HeadSlot, *TailSlot;
	int Count;
	int CountSlot;
};

class Client : public Avto
{
public:
	Client()
	{
		HeadClient = TailClient = 0;
		CountClient = 0;
	}

	int СreateClient()
	{
		ifstream clientIn("e:\\client.txt");
		if (CountClient > 0)return 0;
		while (!clientIn.eof())
		{
				Klient *client= new Klient;
				clientIn >> client->name >> client->id >> client->marka >> client->model >> client->status >> client->color;
				if (client->name != "")
				{
					CountClient++;
					client->next = 0;
					if (TailClient){ TailClient->next = client;}
					if (!HeadClient)HeadClient = client;

					TailClient = client;

				}
				else break;
		}
		clientIn.close();
		if (CountClient == 0) return 1;
		return 0;
	}

	void WriteAllClient()
	{
		if (CountClient != 0)
		{
			Klient *temp = HeadClient;
			while (temp != 0)
			{
				cout <<temp->name<<"\t" <<temp->id << "\t" << temp->marka << "\t" << temp->model << "\t" << temp->status << "\t" << temp->color << "\t" << endl;
				temp = temp->next;
			}
		}
		else cout << "База клиентов пуста" << endl;
	}


	void SearchClientId()
	{
		if (CountClient != 0)
		{
			string id;
			int chec = 0;
			cout << "Укажите ID" << endl;
			cin >> id;
			system("cls");
			Klient *temp = HeadClient;
			while (temp != 0)
			{
				if (temp->id == id)
				{
					cout <<temp->name<<"\t"<< temp->id << "\t" << temp->marka << "\t" << temp->model << "\t" << temp->status << "\t" << temp->color << "\t" << endl;
					temp = temp->next;
					chec++;
					break;
				}
				else temp = temp->next;
			}
			if (chec == 0)cout << "Такого клиента в базе нет";
		}
	}


	void ByAvto()
	{

		int v =  Count;
		if (v != 0)
		{
			ofstream clientOut("e:\\client.txt", ios::app);
			ofstream avtoDel("e:\\avto.txt");
			string id;
			cout << "Введите номер: ";
			cin >> id;
			cout << "Введите имя: ";
			string name;
			cin >> name;
			int n = 1;
			avt *Del = Head;
			Klient *client = new Klient;
			while (Del->id != id)
			{
				Del = Del->next;
				++n;
			}
			client->next = 0;

			client->name = name;
			client->id = Del->id;
			client->color = Del->color;
			client->marka = Del->marka;
			client->model = Del->model;
			client->status = Del->status;
			if (TailClient != 0)TailClient->next = client;
			if (CountClient == 0)HeadClient = TailClient = client;
			 TailClient = client; CountClient++; 

			clientOut << client->name <<"\t"<< client->id << "\t" << client->marka << "\t" << client->model << "\t" << client->status << "\t" << client->color  << endl;
			// Доходим до элемента, 
			// который предшествует удаляемому
			avt *PredDel = Del->pred;
			// Доходим до элемента, который следует за удаляемым
			avt *AfterDel = Del->next;

			// Если удаляем не голову
			if (PredDel != 0 && (Count != 1))
				PredDel->next = AfterDel;
			// Если удаляем не хвост
			if (AfterDel != 0 && (Count != 1))
				AfterDel->pred = PredDel;

			// Удаляются крайние?
			if (n == 1)
				Head = AfterDel;
			if (n == Count)
				Tail = PredDel;

			// Удаление элемента
			delete Del;
			if (v != 0)
			{
				avt *temp = Head;
				while (temp != 0)
				{
					avtoDel << temp->id << "\t" << temp->marka << "\t" << temp->model << "\t" << temp->status << "\t" << temp->color << endl;
					temp = temp->next;
				}
			};
			Count--;
			avtoDel.close();
			clientOut.close();
		}		
	}
	~Client()
	{
		delete HeadClient, TailClient;
	}
private:
	Klient *HeadClient,*TailClient;
	int CountClient;
};

class Prog :public Client
{

};


// Функции вывода
void Go();
void Go1();
void GoAgane();


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Prog prog;
	int otv;
	int stbase;
	int clientbase;

	while (true)
	{
		stbase = prog.CreateAvto();
		clientbase = prog.СreateClient();


		switch (stbase)
		{
		case 1:
			cout << "База пуста" << endl;
			Go1();
			switch (clientbase)
			{
			case 1:
				cout << "База клиентов пуста" << endl;
				break;
			case 0:
				cout << "11\t Вывод базы клиентов" << endl;
				break;
			default:
				break;
			}
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
			prog.SearchId();
			break;
		case 2:
			system("cls");
			prog.SearchMarka();
			break;
		case 3:
			system("cls");
			prog.SearchStatus();
			break;
		case 4:
			system("cls");
			prog.SearchColor();
			break;
		case 5:
			system("cls");
			prog.SearchModel();
			break;
		case 6:
			system("cls");
			prog.AddNewAvto();
			break;
		case 7:
			int ov;
			GoAgane();
			cin >> ov;
			switch (ov)
			{

			case 1:
				system("cls");
				prog.SearchMarka(1);
				break;
			case 2:
				system("cls");
				prog.SearchStatus(1);
				break;
			case 3:
				system("cls");
				prog.SearchColor(1);
				break;
			case 4:
				system("cls");
				prog.SearchModel();
				break;
			default:
				break;
			}
			break;
		case 8:
			system("cls");
			prog.WriteAll();
			break;
		case 9:
			system("cls");
			prog.DelAvto();
			break;
		case 10:
			system("cls");
			prog.ByAvto();
			break;
		case 11:
			system("cls");
			prog.WriteAllClient();
			break;
		case 12:
			system("cls");
			prog.SearchClientId();
			break;
		case 0:
			system("cls");
			cout << "By";
			return 0;
			break;

		default:
			break;
		}
	} 
	

	
}

void Go()
{
	cout << "\t\tБАЗА ДАННЫХ АВТО" << endl
		<< "1\t Поиск по ID" << endl
		<< "2\t Поиск по марке" << endl
		<< "3\t Поиск по статусу" << endl
		<< "4\t Поиск по цвету" << endl
		<< "5\t Поиск по моделе" << endl
		<< "6\t Добавить новое авто" << endl
		<< "7\t Продолжить поиск" << endl
		<< "8\t Вывести всю базу" << endl
		<< "9\t Удалить машину с базы" << endl
		<< "10\t Авто купили" << endl
		<< "11\t Вывод базы клиентов" << endl
		<< "12\t Поиск клиента по номеру" << endl
		<< "0\t ВЫХОД" << endl;


}
void GoAgane()
{
	cout << "\t\tБАЗА ДАННЫХ АВТО" << endl
		<< "1\t Поиск по марке" << endl
		<< "2\t Поиск по статусу" << endl
		<< "3\t Поиск по цвету" << endl
		<< "4\t Поиск по моделе" << endl;
}
void Go1()
{
	cout << "\t\tБАЗА ДАННЫХ АВТО" << endl
		<< "6\t Добавить новое авто" << endl
		<< "0\t ВЫХОД" << endl;

}
