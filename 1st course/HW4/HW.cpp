#include <iostream>

using namespace std;
void task1()
{
    cout << "/////////task1/////////" << endl;

    int a,b;

    cout << "Enter first number:" << endl;
    cin >> a;
    cout << "Enter second number:" << endl;
    cin >> b;
    if(a + b >= 10 && a + b <= 20)
    {
        cout << "true" << endl;;
    }
    else
    {
        cout << "false" << endl;; 
    }
}

void task2()
{
    cout << "/////////task2/////////" << endl;

    int a = 10;
    int b = 10;

    if (a == 10 && b == 10 || a + b == 10)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}

void task3()
{
    cout << "/////////task3/////////" << endl;

    for (int i = 1; i < 50; i++)
    {
        if( i % 2 == 1)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void task4()
{
    cout << "/////////task4/////////" << endl;

    int a = 17;
    bool sn = true;
    for(int i = 2; i <= a / 2; i++)
    {
        if(a % i == 0)
        {
            cout << a << ":not simple" << endl;
            sn = false;
            break;
        }    
    }
    if(sn)
    {
    cout << a << ":simple" << endl;
    }
    
}

void task5()
{
    int a;
    cout << "/////////task5/////////" << endl;
    
    do { 
        cout << "Enter number 1 - 3000:" << endl;
        cin >> a;
    } while (a <= 1 || a >= 3000);
    
    if (a % 400 == 0)
    {
        cout << a << " is leap-year" << endl;
    }
    else if (a % 100 == 0)
    {
        cout << a << " is not leap-year" << endl;
    }
    else if (a % 4 == 0)
    {
        cout << a << " is leap-year" << endl;
    }
    else
    {
        cout << a << " is not leap-year" << endl;
    }
}

int main()
{
    task1();
    task2();
    task3();
    task4();
    task5();
    return 0;
}
