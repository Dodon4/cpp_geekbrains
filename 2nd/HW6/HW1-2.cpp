#include <iostream>
#include <string>
using namespace std;

int getValue()
{
    while (true)
    {
        cout << "Enter int num:" << endl;
        int a;
        cin >> a;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else
            return a;
    }
}

ostream& endll(ostream& stream)
{
    stream.put(stream.widen('\n'));
    stream.put(stream.widen('\n'));
    return stream;
}

int main()
{
    int a = getValue();
    cout << a << endll << a;
    return 0;
}
