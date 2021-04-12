#include <iostream>
using namespace std;


void task1(double *arr, size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void task2(int *arr, size_t size)
{
    cout << "Before changing:";
    for(size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << "Changed array:";
    for(size_t i = 0; i < size; i++)
    {
        if(arr[i] == 1)
        {
            arr[i] = 0;
        }
        else
        {
            arr[i] = 1;
        }
    }
    for(size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void task3(int *arr, size_t size)
{
    int a = 1;
    for(size_t i = 0; i < size; i++)
    {
        arr[i] = a;
         a += 3;
    }
    for(size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// 444444444444444444444
void swap(int& a, int& b)
{
    int buf = a;
    a = b;
    b = buf;
}
void move(int *arr, size_t size, bool right)
{
    if(right)
    {
        for(int i = size - 1; i > 0; i--)
        {
            swap(arr[i], arr[i - 1]);
        }
    }
    else 
    {
        for(int i = 0; i < size - 1; i++)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}

void task4(int *arr, int n, size_t size)
{
    bool dir = n > 0 ? true : false;
    int offset = abs(n) % size;

    for (int i = 0; i < offset; i++)
    {
        move(arr, size, dir);
    }

    for(size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// 444444444444444444444

void task5(int *arr, size_t size)
{
    int left = arr[0];
    int right = 0;
    bool tf = false;
    for(int i = 1; i < size; i++)
    {
        right += arr[i];
    }
    
    for(int i = 1; i < size; i++)
    {
        if(left == right)
        {
            cout << "true" << endl;
            tf = true;
            break;
        }
        left += arr[i];
        right -= arr[i];
    }
    if(!tf)
    {
        cout << "false" << endl;
    }

}

int main()
{
    const size_t SIZETASK1 = 5;
    const size_t SIZETASK2 = 10;
    const size_t SIZETASK3 = 8;
    const size_t SIZETASK4 = 10;
    const size_t SIZETASK5 = 10;

    cout << "///////////task1//////////////" << endl;
    double arrTask1[] = { 5.1234, 8.53523, 55.034850, 32.535656, 77.5345345 };
    task1(arrTask1,SIZETASK1);

    cout << "///////////task2//////////////" << endl;
    int arrTask2 [] = { 0, 1, 1, 1, 1, 0, 0, 0, 1, 1 };
    task2(arrTask2, SIZETASK2);

    cout << "///////////task3//////////////" << endl;
    int arrTask3 [SIZETASK3];
    task3(arrTask3, SIZETASK3);

    cout << "///////////task4//////////////" << endl;
    int arrTask4 [] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    task4(arrTask4, -16, SIZETASK4);

    cout << "///////////task5//////////////" << endl;
    int arrTask5 [] = { 14, 3, 18, 2, 7, 1, 8, 6, 6, 5 };
    task5(arrTask5, SIZETASK5);

    return 0;
}
