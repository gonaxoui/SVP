
#include <iostream>
#include <string>
#include <clocale>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
class IVehicle {
public:
	virtual bool drive(int kilometrs) = 0;
	virtual void refuel() = 0;
	virtual void printStatus() = 0;

};
class AbstractCar : public IVehicle {


public:

	int beer;//топливо в баке на данный момент
	int full_beer;// полный бак
	int expen;//расход топлива за 1 км
	int beg = 0;;//общий пробег тачки

	bool drive(int kilometrs) {
		bool indik = true;
		if (beer >= kilometrs * expen) {
			beer -= kilometrs * expen;


			beg += kilometrs;

		}
		else {
			cout << "|   Ноу топлива! Заправляйся!\n";
			indik = false;
		}
		return indik;

	};
	void refuel() {
		beer = full_beer;
		cout << "|   Полный баккк!   ||   Обьем = " << full_beer << "\n";
	};
	void printStatus() {
		cout << " || Пробег: " << beg << " км\n";
		cout << " || Осталось в баке: " << beer << " л\n";

	};
};
class Sedan : public AbstractCar {
	int beg = 0;
public:
	Sedan() {
		full_beer = 5000;// полный бак
		expen = 6;// расход топлива
		beer = 0;
		beg = 0;

	}
};

class Suv : public AbstractCar {
	int beg = 0;
public:
	Suv() {
		full_beer = 10000;// полный бак
		expen = 12;// расход топлива
		beer = 0;
		beg = 0;

	}
};
class Bus : public AbstractCar {
	int beg = 0;
public:
	Bus() {
		full_beer = 20000;// полный бак
		expen = 32;// расход топлива
		beer = 0;
		beg = 0;

	}
};
class Bicycle : public IVehicle {
	int beg = 0;
public:
	Bicycle() {
		beg = 0;// пробег велика
	}
	bool drive(int kilometrs) {
		cout << "^^Велик проехал " << kilometrs << " км^^\n";
		beg += kilometrs;

		return true;
	};
	void refuel() { cout << "|  Я посмотрю как ты велик заправишь))  |\n"; };
	void printStatus() {
		cout << " || Пробег: " << beg << " км\n";

	};
};
struct RoutePoint {
	int xKm;
	int yKm = 0;
	string name;

};
class Route {
public:
	vector <RoutePoint> tochki;
	void addPoint(const RoutePoint& point) {
		tochki.push_back(point);
	}
	void func(IVehicle* vehicle) {
		if (tochki.size() < 2) {
			cout << "\n|   Нереально пройти путь! Хотя бы 2 точки надо задать!   |\n";
			return;
		}
		else {
			int S = 0;
			for (int i = 0; i < tochki.size() - 1; i++) {
				// формула - расстояние равно корню из суммы разностей
				S = sqrt(pow((tochki[i + 1].xKm - tochki[i].xKm), 2) + (pow((tochki[i + 1].yKm - tochki[i].yKm), 2)));
				cout << "\n\nРасстояние равно: " << S << endl;
				if (vehicle->drive(S) == false) {
					vehicle->refuel();
					vehicle->printStatus();
				}
				else {
					vehicle->printStatus();
					cout << "!!!Путь пройден!!! гспд спасибо\n\n";

				}
			}
		}
	};
};

int main(int argc, char* argv[]) {

	setlocale(LC_ALL, "ru");
	for (int i = 0; i < argc; i++)
		if (argc != 2) {
			cout << "Парамаетры пожавуста правильно напишите\n";
			return 0;
		}
	Route routes[1];
	RoutePoint ris;
	string put = argv[1]; 
	ifstream fin;
	cout << endl << endl;
	fin.open(put);
	if (!fin.is_open()) {
		cout << " Не явление христа народу(файл не открылся)" << endl;
		return 0;
	}
	else {
		cout << "Явление христа народу(фаел открылся!!!)" << endl;
		string str1;
		while (getline(fin, str1)) {
			istringstream str2(str1);
			string name;
			int xKm, yKm;
			str2 >> xKm >> yKm >> name;
			routes[0].addPoint(ris = { xKm, yKm, name });
		}
	}
	fin.close();

	IVehicle* vehicles[4] = { new Bus,new Sedan,new Suv, new Bicycle };
	for (int i = 0; i < 4; ++i) {
		IVehicle* vehicle = vehicles[i];
		routes[0].func(vehicle);
		delete vehicle;
	}
	system("pause");
	return 0;
}
