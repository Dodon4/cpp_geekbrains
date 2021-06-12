#include <vector>
#include <iostream>
#include <memory>
using namespace std;

template<typename T>
T div(const T &a, const T &b) 
{
	if (b == 0)
		throw "DivByZero";
	return a / b;
}

class Ex
{
private:
	double _x;
public:
	Ex(double x) : _x(x) {}
	double get() const
	{
		return _x;
	}
};

class Bar
{
private:
	double _y;
public:
	Bar(double y = 0) : _y(y) {}
	void set(int a)
	{
		if (_y + a > 100)
			throw Ex(a * _y);
		_y = a;
	}
};
int main()
{
	//1
	double a = 5, b = 2;
	try
	{
		cout << div(a, b) << endl;
	}
	catch (const char* error)
	{
		cerr << error << endl;
	}
	//2
	Bar bar(5.14);
	int n;
	do 
	{
		try
		{
			cin >> n;
			bar.set(n);
		}
		catch (Ex &a)
		{
			cerr << "Error:" << a.get() << endl;
		}
		
	} while (n != 0);
	return 0;
}