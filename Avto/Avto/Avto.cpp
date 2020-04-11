

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include < windows.h>

using namespace std;

ifstream avtoIn("e:\\avto.txt");
ofstream avtoOut("e:\\avto.txt",ios::app);
ifstream clientIn("e:\\client.txt");
ofstream clientOut("e:\\client.txt", ios::app);


// Структура полной базы
struct avt
{
	string id;
	string marka;
	string model;
	string status;
	string color;
	avt *next, *pred;
}; 
// Структура временного поиска
struct avtSlot
{
	string id;
	string marka;
	string model;
	string status;
	string color;
	avtSlot *next, *pred;
};  

struct Klient 
{
	string name;
	string id;
	string marka;
	string model;
	string status;
	string color;
	Klient *next, *pred;
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
	int createAvto()
	{

		while (!avtoIn.eof()) 
		{
			if (avtoIn)
			{
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

		}
		if (Count == 0) return 1;
		return 0;
	} 
	// Вывод всей базы
	void WriteAll()
	{
		if (Count != 0)
		{
			avt *temp = Head;
			while (temp !=  0)
			{
				cout << temp->id << "\t" << temp->marka << "\t" << temp->model << "\t" << temp->status << "\t" << temp->color << "\t" << endl;
				temp = temp->next;
			}
		};
	}
	// Поиск по ИД (только во всей базе)
	void searchId()
	{
		if (Count != 0)
		{
			string id;
			int chec = 0;
			cout << "Укажите ID"<<endl;
			cin >> id;
			system("cls");
			avt *temp = Head; 
			while (temp != 0)
			{
					if (temp->id == id)
					{
						cout << temp->id << "\t" << temp->marka << "\t" << temp->model << "\t" << temp->status << "\t" << temp->color << "\t"  << endl;
						temp = temp->next;
						break;
					}
					else temp = temp->next;
			}					
		}
	}

	// Поиск по марке (во всей базе)
	void searchMarka()
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
					slot->pred = 0;
					if (CountSlot == 0)
					{
						HeadSlot = TailSlot = slot;
					}
					else {
						TailSlot->next = slot;
						slot->pred = TailSlot;
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
	void searchMarka(int n)
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
					slot->pred = 0;
					if (CountSlot == 0)
					{
						HeadSlot = TailSlot = slot;
					}
					else {
						TailSlot->next = slot;
						slot->pred = TailSlot;
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

	// Поиск по моделе (во всей базе)
	void searchModel()
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
					slot->pred = 0;
					if (CountSlot == 0)
					{
						HeadSlot = TailSlot = slot;
					}
					else {
						TailSlot->next = slot;
						slot->pred = TailSlot;
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
	void searchModel(int n)
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
					slot->pred = 0;
					if (CountSlot == 0)
					{
						HeadSlot = TailSlot = slot;
					}
					else {
						TailSlot->next = slot;
						slot->pred = TailSlot;
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
	void searchStatus()
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
					slot->pred = 0;
					if (CountSlot == 0)
					{
						HeadSlot = TailSlot = slot;
					}
					else {
						TailSlot->next = slot;
						slot->pred = TailSlot;
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
	void searchStatus(int n)
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
					slot->pred = 0;
					if (CountSlot == 0)
					{
						HeadSlot = TailSlot = slot;
					}
					else {
						TailSlot->next = slot;
						slot->pred = TailSlot;
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
	void searchColor()
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
					slot->pred = 0;
					if (CountSlot == 0)
					{
						HeadSlot = TailSlot = slot;
					}
					else {
						TailSlot->next = slot;
						slot->pred = TailSlot;
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
	void searchColor(int n)
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
					slot->pred = 0;
					if (CountSlot == 0)
					{
						HeadSlot = TailSlot = slot;
					}
					else {
						TailSlot->next = slot;
						slot->pred = TailSlot;
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
		avtoOut << temp->color << endl;
		temp->pred = Tail;
		if (Tail != 0)Tail->next = temp;
		if (Count == 0)Head = Tail = temp;
		else { Tail = temp; Count++; }
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
		return 0;
	}


	int setCount() {
		return Count;
	}
	void createCount() {
		Count--;
	}
	avt *setHead()
	{
		return Head;
	}
	void createHead(avt *h)
	{
		Head = h;
	}
	void createTail(avt *t)
	{
		Tail = t;
	}


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

	int createClient()
	{

		while (!clientIn.eof())
		{
			if (clientIn)
			{
				Klient *client= new Klient;
				clientIn >> client->name >> client->id >> client->marka >> client->model >> client->status >> client->color;
				if (client->name != "")
				{
					CountClient++;
					client->next = 0; client->pred = 0;
					if (TailClient){ TailClient->next = client; client->pred = TailClient;}
					if (!HeadClient)HeadClient = client;

					TailClient = client;

				}
				else break;
			}

		}
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
				cout <<temp->name <<temp->id << "\t" << temp->marka << "\t" << temp->model << "\t" << temp->status << "\t" << temp->color << "\t" << endl;
				temp = temp->next;
			}
		};
	}


	void By()
	{

		int v =  setCount();
		if (v != 0)
		{
			ofstream avtoDel("e:\\avto.txt");
			string id;
			cout << "Введите номер: ";
			cin >> id;
			cout << "Введите имя: ";
			string name;
			cin >> name;
			int n = 1;
			avt *Del = setHead();
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
			client->pred = TailClient;
			if (TailClient != 0)TailClient->next = client;
			if (CountClient == 0)HeadClient = TailClient = client;
			else { TailClient = client; CountClient++; }

			clientOut << client->name <<"\t"<< client->id << "\t" << client->marka << "\t" << client->model << "\t" << client->status << "\t" << client->color  << endl;
			// Доходим до элемента, 
			// который предшествует удаляемому
			avt *PredDel = Del->pred;
			// Доходим до элемента, который следует за удаляемым
			avt *AfterDel = Del->next;

			// Если удаляем не голову
			if (PredDel != 0 && (setCount() != 1))
				PredDel->next = AfterDel;
			// Если удаляем не хвост
			if (AfterDel != 0 && (setCount() != 1))
				AfterDel->pred = PredDel;

			// Удаляются крайние?
			if (n == 1)
				createHead(AfterDel);
			if (n == setCount())
				createTail(PredDel);

			// Удаление элемента
			delete Del;
			if (v != 0)
			{
				avt *temp = setHead();
				while (temp != 0)
				{
					avtoDel << temp->id << "\t" << temp->marka << "\t" << temp->model << "\t" << temp->status << "\t" << temp->color << endl;
					temp = temp->next;
				}
			};
			createCount();
		}		
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

	int otv;
	int stbase;
	int clientbase;
	Prog prog;
	if (!avtoIn.is_open() || !avtoOut.is_open())
	{
		cout << "Файл не найден";   return 1;
	}

	while (true)
	{
		stbase = prog.createAvto();
		clientbase = prog.createClient();
		switch (stbase)
		{
		case 1:
			cout << "База пуста" << endl;
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
			prog.searchId();
			break;
		case 2:
			system("cls");
			prog.searchMarka();
			break;
		case 3:
			system("cls");
			prog.searchStatus();
			break;
		case 4:
			system("cls");
			prog.searchColor();
			break;
		case 5:
			system("cls");
			prog.searchModel();
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
				prog.searchMarka(1);
				break;
			case 2:
				system("cls");
				prog.searchStatus(1);
				break;
			case 3:
				system("cls");
				prog.searchColor(1);
				break;
			case 4:
				system("cls");
				prog.searchModel();
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
			prog.By();
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
	

	avtoIn.close();
	avtoOut.close();
	
}

void Go()
{
	cout << "\t\tБАЗА ДАННЫХ ПО АВТО" << endl
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
		<< "0\t ВЫХОД" << endl;


}
void GoAgane()
{
	cout << "\t\tБАЗА ДАННЫХ ПО АВТО" << endl
		<< "1\t Поиск по марке" << endl
		<< "2\t Поиск по статусу" << endl
		<< "3\t Поиск по цвету" << endl
		<< "4\t Поиск по моделе" << endl;
}
void Go1()
{
	cout << "\t\tБАЗА ДАННЫХ ПО АВТО" << endl
		<< "6\t Добавить новое авто" << endl
		<< "0\t ВЫХОД" << endl;

}
