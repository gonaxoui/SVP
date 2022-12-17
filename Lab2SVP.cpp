
#include <iostream>
using namespace std;
//Класс тс - vehicle - основной класс
// типо от него ща наследовать буду, хвхвх
// тут типо должно быть три метода
//  drive - увеличивает пробег(beg) и уменьшает топливо в баке(beer)
//  refuel - переменную бак(beer) заправляет на полную
//  printStatus - показывает пробег(beg) и бак(beer)
//  переменная для полного бака - full_beer
class Vehicle {
public:
	int beg;//общее пробег тачки
	int beer;//топливо в баке на данный момент
	int full_beer;// полный бак
	int expen;//расход топлива за 1 км
	// методы типо
	void drive(int kilometrs) {
		if (beer >= kilometrs * expen) {
			beer -= kilometrs * expen;
			beg += kilometrs;
			cout << "Машинка проехала " << kilometrs << " км\n";
		}
		else {
			cout << "Ноу топлива! Заправляйся!\n";
		}

	};
	void refuel() {
		beer = full_beer;
		cout << "Полный баккк!\n";
	};
	void printStatus() {
		cout << " | Пробег: " << beg << " км\n";
		cout << " | Осталось в баке: " << beer << " л\n";

	};
};
class Sedan : public Vehicle {
public:
	Sedan() {
		full_beer = 50;// полный бак
		expen = 6;// расход топлива
		beg = 0;// пробег
		beer = 0; // остаток топлива
	}
};
class Suv : public Vehicle {
public:
	Suv() {
		full_beer = 100;// полный бак
		expen = 12;// расход топлива
		beg = 0;// пробег
		beer = 0; // остаток топлива
	}
};
class Bus : public Vehicle {
public:
	Bus() {
		full_beer = 200;// полный бак
		expen = 32;// расход топлива
		beg = 0;// пробег
		beer = 0; // остаток топлива
	}
};


int main() {
	setlocale(LC_CTYPE, "rus");
	Vehicle* vehicles[3] = { new Sedan, new Suv,new Bus }; // Создаем объекты классов для моделирования 
	for (int i = 0; i < 3; ++i)
	{
		Vehicle* vehicle = vehicles[i];
		vehicle->refuel(); 
		vehicle->printStatus(); 
		vehicle->drive(1);
		vehicle->printStatus();
		vehicle->drive(4);
		vehicle->printStatus();
		vehicle->drive(3);
		vehicle->printStatus();
		vehicle->refuel();
		vehicle->drive(3);
		vehicle->printStatus();
		delete vehicle;
		cout << endl;
	}
	return 0;
}
