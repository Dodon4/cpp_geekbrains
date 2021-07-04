#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include <tuple>
#include <algorithm>
#include <optional>
using namespace std;

#include <chrono>
#include <iostream>

class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;

    std::string m_name;
    std::chrono::time_point<clock_t> m_beg;
    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }

public:
    Timer() : m_beg(clock_t::now()) { }
    Timer(std::string name) : m_name(name), m_beg(clock_t::now()) { }

    void start(std::string name) {
        m_name = name;
        m_beg = clock_t::now();
    }
    void print() const {
        std::cout << m_name << ":\t" << elapsed() * 1000 << " ms" << '\n';
    }
};

template<typename T>
void Swap(T* a, T* b)
{
    T buf = *a;
    *a = *b;
    *b = buf;
}
template<typename T>
void SortPointers(vector<T*> vect)
{
    size_t size = vect.size();
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*vect[j] > *vect[j + 1]) {
                temp = *vect[j];
                *vect[j] = *vect[j + 1];
                *vect[j + 1] = temp;
            }
        }
    }
}
void num2(ifstream& filename)
{
    Timer timer("2");
    vector<char> alph = {'у', 'е', 'ы', 'а', 'о' , 'э', 'я', 'и', 'ю', 'ё' };
    auto check = ([&](char c)
        {
            for (auto ch : alph)
            {
                if (c == ch)
                    return 1;
            }
        });
    string str;
    int count = 0;
    if (filename.is_open())
    {
        while (!filename.eof())
        {
            getline(filename, str);
            count += count_if(str.begin(), str.end(), check);
        }
    }
    filename.close();
    cout << count << endl;
    timer.print();
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int* a = new int(3);
    int* b = new int(5);
    vector<int*> vect = { new int(0),new int(2),new int(1),new int(8),new int(5) };
    Swap(a, b);
    cout << *a << " " << *b << endl;
    SortPointers(vect);
    for (int i = 0; i < 5; i++)
    {
        cout << *vect[i] << " ";
        delete vect[i];
    }
    cout << endl;
    ifstream file("C:\\Users\\dodon\\source\\repos\\ConsoleApplication8\\Debug\\asd.txt");
    num2(file);
    return 0;
}
