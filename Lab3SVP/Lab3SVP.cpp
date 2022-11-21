
#include <iostream>
using namespace std;
//Теперь есть интефейсный и наследованный от него абстрактный
class IVehicle {
public:
	virtual void drive(int kilometrs) = 0;
	virtual void refuel() = 0;
	virtual void printStatus() = 0;

};
class AbstractCar : public IVehicle {
public:
	int beg;//общий пробег тачки
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
class Sedan : public AbstractCar {
public:
	Sedan() {
		full_beer = 50;// полный бак
		expen = 6;// расход топлива
		beg = 0;// пробег
		beer = 0; // остаток топлива
	}
};

class Suv : public AbstractCar {
public:
	Suv() {
		full_beer = 100;// полный бак
		expen = 12;// расход топлива
		beg = 0;// пробег
		beer = 0; // остаток топлива
	}
};
class Bus : public AbstractCar {
public:
	Bus() {
		full_beer = 200;// полный бак
		expen = 32;// расход топлива
		beg = 0;// пробег
		beer = 0; // остаток топлива
	}
};
class Bicycle : public IVehicle {
	int beg;
public:
	Bicycle() {
		beg = 0;// пробег велика
	}
	void drive(int kilometrs) {
			cout << "Велик проехал " << kilometrs << " км\n";
			beg += kilometrs;
	};
	void refuel() {};
	void printStatus() {
		cout << " | Пробег: " << beg << " км\n";

	};
};

int main() {
	setlocale(LC_ALL, "ru");
	IVehicle* vehicles[4] = { new Sedan, new Suv,new Bus, new Bicycle }; // Создаем объекты классов
	for (int i = 0; i < 4; ++i)
	{
		IVehicle* vehicle = vehicles[i];
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
