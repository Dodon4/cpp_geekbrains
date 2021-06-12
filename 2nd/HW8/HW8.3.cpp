#include <iostream>
#include <conio.h>
using namespace std;

class OffTheField
{
    const int _x;
    const int _y;
    const string _dir;
public:
    int getX() const { return _x; }
    int getY() const { return _y; }
    string getDir() const { return _dir; }
    OffTheField(const int& x, const int& y, const string& dir) : _x(x), _y(y), _dir(dir) {}
};
class IllegalCommand
{
    const int _x;
    const int _y;
public:
    int getX() const { return _x; }
    int getY() const { return _y; }
    IllegalCommand(const int& x, const int& y) : _x(x), _y(y) {}
};

class Robot
{
    int _x;
    int _y;
public:
    Robot(int x = 5, int y = 5): _x(x), _y(y) {}
    void move()
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'd':
                ++_x;
                if (_x > 10)
                {
                    --_x;
                    throw OffTheField(_x, _y, "right");
                }
                cout << "coord(" << _x << "," << _y << ")" << endl;
                cout << "Dir: right" << endl;
                break;
            case 'w':
                ++_y;
                if (_y > 10)
                {
                    --_y;
                    throw OffTheField(_x, _y, "up");
                }
                cout << "coord(" << _x << "," << _y << ")" << endl;
                cout << "Dir: up" << endl;
                break;
            case 'a':
                --_x;
                if (_x < 0)
                {
                    ++_x;
                    throw OffTheField(_x, _y, "left");
                }
                cout << "coord(" << _x << "," << _y << ")" << endl;
                cout << "Dir: left" << endl;
                break;
            case 's':
                --_y;
                if (_y < 0)
                {
                    ++_y;
                    throw OffTheField(_x, _y, "down");
                }
                cout << "coord(" << _x << "," << _y << ")" << endl;
                cout << "Dir: down" << endl;
                break;
            default:
                throw IllegalCommand(_x, _y);
            }

        }
    }
};

int main()
{
    Robot r;
    while (true)
    {
        try
        {
            r.move();
        }
        catch (const IllegalCommand &ill)
        {
            cerr << "Illegal command:" << endl << "coord(" << ill.getX() << "," << ill.getY() << ")" << endl;
            cerr << "undefined direction" << endl;
        }
        catch (const OffTheField& off)
        {
            cerr << "OffTheField:" << endl << "coord(" << off.getX() << "," << off.getY() << ")" << endl;
            cerr << off.getDir() << endl;
        }
    }


    return 0;
}
