#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
#include <chrono>
#include <random>

using namespace std;

mutex m;
mutex pc;

struct pcout
{
    std::unique_lock<mutex> pout;
    pcout() : pout(unique_lock<mutex>(pc)) {}
    template<typename T>
    pcout& operator<<(const T& os)
    {
        cout << os;
        return *this;
    }
    pcout& operator<<(ostream& (*os)(ostream&))
    {
        cout << os;
        return *this;
    }
};
int32_t getRandomNum(int32_t min, int32_t max)
{
    const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937_64 generator(seed);
    std::uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}

void collect(vector<int> &a) {
    lock_guard lg(m);
    a.push_back(getRandomNum(1, 50));
    pcout() << "new collection:";
    for (auto el : a)
    {
        pcout() << el << " ";
    }
    pcout() << endl;
}

void steal(vector<int> &a) {
    lock_guard lg(m);
    sort(a.begin(), a.end());
    if (a.empty())
        return;
    pcout() << "///////////////////////stolen: " << *(a.end() - 1) << endl;
    a.pop_back();
}

int simpNum(int n)
{
    if (n == 1)
        return 2;
    pcout() << "1 : 2" << endl;
    int i = 1;
    long unsigned int buf = 3;
    while (i != n)
    {
        bool cont = false;
        for (long unsigned int j = 3; j < buf / 2; j += 2)
        {
            if (buf % j == 0)
            {
                cont = true;
                break;
                continue;
            }
        }
        if (cont)
        {
            buf += 2;
            continue;
        }
        i++;
        pcout() << i << " : " << buf << endl;
        buf += 2;
    }
    return buf - 2;
}

int main()
{
    srand(time(0));
    vector<int> a = { 5, 10, 20, 30, 40};
    int simp;
    thread th([&]() { simp = simpNum(1000); });
    for (int i = 0; i < 100; i++)
    {
        thread th1(collect, ref(a));
        thread th2(steal, ref(a));
        th1.join();
        th2.join();
    }
    th.join();
    cout << "simple number is:" << simp << endl;
    return 0;
}
