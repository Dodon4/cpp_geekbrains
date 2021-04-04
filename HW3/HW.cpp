#include <iostream>

extern int a;
extern int b;
extern int c;
extern int d;

int main()
{
    //4
    std::cout << a * (b + (static_cast<float> (b) / d)) << std::endl;

    //2
    int num = 30;
    int res = (num <= 21) ? (num - 21) : (num - 21) * 2;
    std::cout << res << std::endl; 

    //3
    int arr[3][3][3] = {0};
    int* ptr = &arr[1][1][1];
    *ptr = 3;
    std::cout << *ptr << " " << arr[1][1][1];
    return 0;
}
