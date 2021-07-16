#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
using namespace std;
template<class T1, class T2>
void insert_sorted(T1 &cont, const T2 &arg)
{
    cont.insert(std::upper_bound(cont.begin(), cont.end(), arg), arg);
}
double error()
{
    return 0.1;
}
int main()
{
    //1
    vector<int> v = {1, 2, 3, 4, 6, 7, 8, 9};
    insert_sorted(v,5);
    copy(v.begin(), v.end(), ostream_iterator<int>{cout, ", "});
    cout << endl;
    //2
    vector<double> s(100);
    double i = 0;
    generate(s.begin(), s.end(), [&]() {i += 0.1; return rand() % 10 * sin(i); });
    //transform(s.begin(), s.end(), s.begin(), [](const auto i) { return sin(i); });
    copy(s.begin(), s.end(), ostream_iterator<double>{cout, ", "});
    cout << endl;
    vector<double> vecInt(100);
    transform(s.begin(), s.end(), vecInt.begin(), [](const auto i) { return static_cast<int>(i); });
    copy(vecInt.begin(), vecInt.end(), ostream_iterator<double>{cout, ", "});
    cout << endl;
    cout << inner_product(vecInt.begin(), vecInt.end(), s.begin(), 0.0,
        std::plus<>(), [](const double& a, const double& b) {return (a - b) * (a - b); }) << endl;
    double sum = 0;
    return 0;
}
