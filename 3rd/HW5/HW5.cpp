#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <list>
#include <math.h>
#include <set>
#include <map>
#include <string>
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
    multimap<int,string> mlt;
    string str;
    getline(std::cin, str);
    size_t sep_pos = 0;
    while (true) {
        size_t pos = str.find('.', sep_pos);
        if (pos == str.npos) {
            string tmp = str.substr(sep_pos, str.size() - sep_pos);
            mlt.insert({tmp.size(), tmp});
            break;
        }
        string tmp = str.substr(sep_pos, pos - sep_pos);
        mlt.insert({ tmp.size(), tmp });
        sep_pos = pos + 1;
    }
    for_each(mlt.begin(), mlt.end(),
        [](pair<int, string> item) {
            cout << item.first << " " << item.second << "\n";
        });
    return 0;
}
