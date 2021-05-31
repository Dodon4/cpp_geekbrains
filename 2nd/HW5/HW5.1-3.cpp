#include <iostream>
#include <string>
using namespace std;

template <class T>
class Pair1
{
private:
    T _a;
    T _b;
public:
    Pair1(T a, T b) : _a(a), _b(b) {}

    T first() const
    {
        return _a;
    }

    T second() const
    {
        return _b;
    }
};
template <class T1, class T2>
class Pair
{
protected:
    T1 _a;
    T2 _b;
public:
    Pair(T1 a, T2 b) : _a(a), _b(b) {}
    
    T1 first() const
    {
        return _a;
    }
    
    T2 second() const
    {
        return _b;
    }
};



template <class T>
class StringValuePair : public Pair<string, T>
{
public:
    StringValuePair(string a, T b) : Pair <string, T> (a, b) {}
};


int main()
{
    //1
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    //2
    Pair<int, double> p3(6, 7.8);
    cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

    const Pair<double, int> p4(3.4, 5);
    cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';
    // 3
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;
}
