// features of calling methods of inherited classes
#include "pch.h"
#include<iostream>
#include<string>
using namespace std;

class Car
{
public:
	Car()
	{
		cout << "ctor Car class \t\t" << this << endl;
	}
	~Car()
	{
		cout << "\t\tdestor Car \t" << this << endl;
	}
	void Use()
	{
		cout << "method Use() of class Car \t" << this << endl;
	}
	void drive()
	{
		cout << "method drive() of class Car \t\t" << this << endl;
	}
};

class Plane
{
public:
	int v;
	int m;

	int k;
	Plane(int &k):  k(k)
	{
		cout << "ctor Plane class \t" << this << endl;
	}
	~Plane()
	{
		cout << "\t\tdestor Plane \t" << this<< "\t ~Plane() k ="  << k  << endl<<endl;
	}
	void Flight()
	{
		k+=k;
		cout << "method Flight() of class Plane \t" << this << "\t k+k= " << k << endl;//_______________count Flight() 
		//cout   <<  endl;
	}
	void Use()
	{
		cout << "method Use() of class Plane \t" << this << endl;
	}
};
//При создании объекта этого класса первым конструируется в базовом классе "Car" потом "Plane" адресс "FlightCar" будет вызываться по адрессу "Car" 
class FlightCar :public Car, public Plane
{
public:
	FlightCar( int k) :Plane(k)
	{
		cout << "ctor FlightCar class \t" << this << endl;
	}
	void FlightDrive()
	{
		cout << "method FlightDrive() of class FlightCar " << this << endl;
	}
	~FlightCar()
	{
		cout << "\tdestor  FlightCar \t" << this << endl;
	}
};

int main()
{
	int k = 1;
	cout << endl;

	FlightCar flc( k);
	cout << endl;

	cout << "\tUse methods of all inherited classes" << endl;
	flc.drive();
	flc.Flight();
	flc.Flight();
	flc.FlightDrive();

	cout << "\tCalling a specific similar method from the base class creates a new object" << endl;
	((Car)flc).Use();//вызов конкретного схожего метода из базового класса. создает новый объект
	((Plane)flc).Use();
	((Plane)flc).Flight();// адресса будут отличаться при каждым вызове , так же вызывается деструктор класса из которого вызван метод 
	((Plane)flc).Flight();//так же значения переменной увеличенной на 1 в этой функции не сохраняются
	((Plane)flc).Flight();
	cout << endl;
}
