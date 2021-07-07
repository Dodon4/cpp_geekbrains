#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

void push_avg(list<double>& l)
{
    double sum = 0;
    int count = 0;
    for (auto elem : l)
    {
        sum += elem;
        count++;
    }
    l.push_back(sum / count);
}

class Matrix
{
private:
    size_t _size;
    vector<vector<double>> _arr;
    double calc2x2(const vector<vector<double>>& vec) { return vec[0][0] * vec[1][1] - vec[1][0] * vec[0][1]; }
public:
    Matrix(size_t size) : _arr(size), _size(size)
    {
        int i = 0;
        for (auto vec : _arr)
        {
            vec = vector<double>(size);
            for (auto elem : vec)
            {
                elem = i++;
            }
        }
    }
    Matrix(vector<vector<double>> arr) : _arr(arr) { _size = _arr.size(); }
    double minor(int row, int col, size_t size, const vector<vector<double>> vec)
    {
        double sumMin = 0;
        vector<vector<double>> v(size, vector<double>(size));
        int move = 0;
        for (int i = 0; i < vec.size(); i++)
        {

            if (i == row)
            {
                move++;
                continue;
            }
            for (int j = 1; j < vec.size(); j++)
            {
                v[i - move][j - 1] = vec[i][j];
            }
        }
        if (size == 2)
        {
            sumMin += vec[row][0] * calc2x2(v);
        }
        return sumMin;
    }
    double determinant()
    {
        double sum = 0;
        for (int j = 0; j < _size; j++)
        {
            if (j % 2 == 1)
            {
                sum -= minor(j, 0, _size - 1, _arr);
            }
            else
            {
                sum += minor(j, 0, _size - 1, _arr);
            }

        }
        return sum;
    }

};

template <typename T>
class RangeBase {
public:
    class iterator {
    public:
        iterator(T* ptr) : ptr(ptr) {}
        iterator operator++() { ++ptr; return *this; }
        bool operator!=(const iterator& other) const { return ptr != other.ptr; }
        const T& operator*() const { return *ptr; }
    private:
        T* ptr;
    };
private:
    size_t size;
    T* col;
public:
    RangeBase(T* col, size_t size): size(size), col(col)
    {}
    iterator begin() { return iterator(col); }
    iterator end() { return iterator(col + size); }
};

int main()
{
    list <double> l{ 1, 6 , 2.5 };
    push_avg(l);
    push_avg(l);
    push_avg(l);
    for (auto elem : l)
    {
        cout << elem << " ";
    }
    cout << endl;
    vector<vector<double>> _arr{ {2.5, 3.2, 2.8}, {6.3, 8.7, 9.2}, {1.9, 10.3, 9.7} };
    Matrix m(_arr);
    cout << m.determinant() << endl;
    int* arr = new int[4]{ 1,2,3,4 };
    RangeBase<int> array(arr,4);
    for (auto c : array)
    {
        cout << c << " ";
    }
    return 0;
}
