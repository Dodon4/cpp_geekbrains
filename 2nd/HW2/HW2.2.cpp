#include <iostream>
#include <string>
using namespace std;

class Fruit
{
private:
    string _name;
    string _color;
public:
    Fruit(string name, string color): _name(name), _color(color) {}
    string getName() const
    {
        return _name;
    }
    string getColor() const
    {
        return _color;
    }
};
class Apple : public Fruit
{
public:
    Apple(string color, string name = "Apple") : Fruit(name, color)  {}
};
class Banana : public Fruit
{
public:
    Banana() : Fruit("Banana", "yellow")  {}
};
class GrannySmith  : public Apple
{
public:
    GrannySmith() : Apple("green", "GrannySmith") {}
};
int main()
{
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;

}