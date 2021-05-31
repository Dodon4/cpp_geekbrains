#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
int main()
{
    vector <int> arr = { 1, 1 , 1, 2, 2, 3, 4, 5, 5, 1, 6 };
    sort(arr.begin(), arr.end());
    int buf = 0, i = 0;
    for (const int v : arr)
    {
        if (v != buf)
        {
            buf = v;
            i++;
        }
    }
    cout << i;

    return 0;
}