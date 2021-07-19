#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <list>
#include <math.h>
#include <set>
using namespace std;
template<class Iterator>
void out_nonRepeated(Iterator first, Iterator last)
{
    vector<string> v;
    copy(first, last, back_inserter(v));
    sort(v.begin(), v.end());
    auto unique_v = unique(v.begin(), v.end());
    v.erase(unique_v, v.end());
    copy(v.begin(), v.end(), ostream_iterator<string>{cout, ", "});
    cout << endl;
}

int main()
{
    vector<string> v = { "aaa", "bbb", "abc", "bbb", "aaa" };
    list<string> l = { "aaa", "bbb", "abc", "bbb", "aaa" };
    out_nonRepeated(v.begin(), v.end());
    out_nonRepeated(l.begin(), l.end());

    return 0;
}
