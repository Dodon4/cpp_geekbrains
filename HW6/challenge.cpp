
#include "challenge.h"
using namespace std;


int main()
{
    double x = 9.9, y = 9.9;
    double v = 0.2;
    Player p(x, y,v );
    GameField a(p);

    while (true)
    {
        //p.input();
        a.GetTickCount();
        cout << p.getX() << " " << p.getY();
        cout << endl;
    }

}