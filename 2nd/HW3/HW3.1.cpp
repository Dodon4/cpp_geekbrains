#include <iostream>

using namespace std;

class Figure
{
public:
	virtual float area() const = 0;
};
class Parallelogram : public Figure
{
protected:
	float _a;
	float _h;
public:
	Parallelogram(float a, float h) : _a(a), _h(h) {}
	float area() const override { return _a * _h; }
};
class Square : public Parallelogram
{
public:
	Square(float a) : Parallelogram(a, 0){}
	float area() const override { return _a * _a; }
};
class Rhombus : public Parallelogram
{
public:
	Rhombus(float a, float h) : Parallelogram(a, h) {}
	float area() const override { return _a * _h; }
};
class Circle : public Figure
{
private:
	float _r;
	const float pi = 3.14;
public:
	Circle(float r) : _r(r) {}
	float area() const override { return _r * _r * pi; }
};
int main()
{
	Parallelogram p(3, 4);
	Square s(3);
	Rhombus r(3, 4);
	Circle c(3);
	cout << p.area() << endl;
	cout << s.area() << endl;
	cout << r.area() << endl;
	cout << c.area() << endl;

	return 0;
}
