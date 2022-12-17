
#include <iostream>
#include <string>
#include <clocale>
#include <vector>
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
		if (beer >= kilometrs * expen ) {
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
		cout << "|   Полный баккк!   ||   Обьем = "<< full_beer<<"\n";
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
	int xKm = 0;
	int yKm = 0;
	string name;
	RoutePoint(int PoX, int PoY, string title_of_pyt) {
		xKm = PoX;
		yKm = PoY;
		name = title_of_pyt;
	}

};
class Route{
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
				for (int i = 0; i < tochki.size()-1; i++) {
					// формула - расстояние равно корню из суммы разностей
					S = sqrt(pow((tochki[i+1].xKm - tochki[i].xKm), 2) + (pow((tochki[i+1].yKm - tochki[i].yKm), 2)));
					cout <<"\n\nРасстояние равно: " << S << endl;
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

	int main() {
		setlocale(LC_ALL, "ru");
		Route routes[2];

		routes[0].addPoint(RoutePoint{ 0, 0, "Point1" });
		routes[0].addPoint(RoutePoint{ 100, 0, "Point2" });
		routes[0].addPoint(RoutePoint{ 200, 100, "Point3" });
		routes[0].addPoint(RoutePoint{ 300, 300, "Point4" });
		routes[0].addPoint(RoutePoint{ 100, 450, "Point5" });
		routes[0].addPoint(RoutePoint{ 0, 450, "Point6" });

		routes[1].addPoint(RoutePoint{ 0, 0, "Moscow" });
		routes[1].addPoint(RoutePoint{ 0, 450, "Voronezh" });
		routes[1].addPoint(RoutePoint{ 0, 100, "Lipetsk" });

		IVehicle* vehicles[4] = { new Bus,new Sedan,new Suv, new Bicycle };
		for (int i = 0; i < 4; ++i) {
			{
				IVehicle* vehicle = vehicles[i];
				for (int j = 0; j < 2; j++)
				{
					cout << "Маршрут номер: " << j + 1 << '\n';
					routes[j].func(vehicle);


				}
				delete vehicle;
			}
		}
		return 0;
	}