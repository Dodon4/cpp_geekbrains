
#include <iostream>
#include <string>
using namespace std;

class Car
{
protected:
	const string _company;
	const string _model;
public:
	Car(const string &company, const string &model) : _company(company), _model(model)
	{ 
		cout << "Car " << _company << " " << _model << endl;
	}
};
class Bus : virtual public Car
{
public:
	Bus(const string& company, const string& model) : Car(company, model)
	{
		cout << "Bus " << _company << " " << _model << endl;
	}

};
class PassengerCar : virtual public Car
{
public:
	PassengerCar(const string& company, const string& model) : Car(company, model)
	{
		cout << "PassengerCar " << _company << " " << _model << endl;
	}
};
class Minivan : public Bus, public PassengerCar
{
public:
	Minivan(const string& company, const string& model) : Car(company, model), Bus(company, model), PassengerCar(company, model)
	{
		cout << "Minivan " << _company << " " << _model << endl;
	}
};
int main()
{
	Car a("bmv", "x5");
	cout << endl;
	Bus b("bmv", "x5");
	cout << endl;
	PassengerCar c("bmv", "x5");
	cout << endl;
	Minivan d("bmv", "x5");

	return 0;
}

