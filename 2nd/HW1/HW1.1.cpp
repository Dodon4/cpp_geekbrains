#include <iostream>
#include <math.h>
using namespace std;

class Power
{
private:
    double _a ;
    double _b ;
    
public:
    Power(double a = 2.14, double b = 3.14) : _a(a), _b(b) {}
    void set (double a, double b) 
    {
        _a = a;
        _b = b;
    }
    double calculate()
    {
        return pow(_a,_b);
    }
};
int main()
{
    Power a;

    cout << a.calculate();

    return 0;

}