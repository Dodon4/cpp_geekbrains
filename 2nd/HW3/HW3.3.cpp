
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class Fraction
{
private:
	int _a;
	int _b;
public:

	Fraction(int a, int b = 1) : _a(a), _b(b)
	{
		assert(b != 0);
	}
	Fraction operator+(const Fraction& a)
	{
		if (_b != a._b)
			return Fraction(_a * a._b + a._a * _b, _b * a._b);
		else
			return Fraction(_a + a._a, _b);
	}
	Fraction operator-(const Fraction& a)
	{
		if (_b != a._b)
			return Fraction(_a * a._b - a._a * _b, _b * a._b);
		else
			return Fraction(_a - a._a, _b);
	}
	Fraction operator*(const Fraction& a)
	{
		return Fraction(_a * a._a, _b * a._b);
	}
	Fraction operator/(const Fraction& a)
	{
		return Fraction(_a * a._b, _b * a._a);
	}
	Fraction operator-() const
	{
		return Fraction(-_a, -_b);
	}
	void getFrac() const
	{
		cout << _a << "/" << _b << endl;
	}
	bool operator>(const Fraction& a) const
	{
		return static_cast<float> (_a) / _b > static_cast<float> (a._a) / a._b;
	}
	bool operator<=(const Fraction& a) const
	{
		return !(*this > a);
	}
	bool operator<(const Fraction& a) const
	{
		return static_cast<float> (_a) / _b < static_cast<float> (a._a) / a._b;
	}
	bool operator>=(const Fraction& a) const
	{
		return !(*this < a);
	}
	bool operator==(const Fraction& a) const
	{
		return static_cast<float> (_a) / _b == static_cast<float> (a._a) / a._b;
	}
	bool operator!=(const Fraction& a) const
	{
		return !(*this == a);
	}
};

int main()
{
	Fraction a(3, 2), b(3, 3), c(2,2);
	if (a > b)
		cout << "1111111111" << endl;
	if (b <= a)
		cout << "2222222222" << endl;
	if (b >= c)
		cout << "3333333333" << endl;
	if (b < a)
		cout << "4444444444" << endl;
	if (b == c)
		cout << "5555555555" << endl;
	if (b != a)
		cout << "6666666666" << endl;
	Fraction d = a + b;
	d.getFrac();
	d = -d;
	d.getFrac();
	d = a - b;
	d.getFrac();
	d = a * b;
	d.getFrac();
	d = a / b;
	d.getFrac();
	return 0;
}

