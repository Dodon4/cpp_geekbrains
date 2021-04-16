#include <iostream>
#include <string>
#include <fstream>

using namespace std;
void coutDelArr(int *& ptrArr, size_t &size)
{
    for(int i = 0; i < size; i++)
    {
        cout << ptrArr[i] << " ";
    }
    cout << endl;

    delete[] ptrArr;
}
void createArr(int *& ptrArr, size_t &size)
{
    ptrArr = new int [size];

    for(size_t i = 0, pow = 1; i < size; i++, pow *= 2)
    {
        ptrArr[i] = pow;
    }
}
void task1()
{
    while (true)
    {
        size_t size;

        cout << "Enter your size of array:" << endl;
        cin >> size;

        if(cin.fail())
        {
            cout << "Error. Please enter number > 0!" << endl;
            cin.clear();
            cin.ignore(32767, '\n'); 
        }
        else
        {
            int * ptrArr;

            createArr(ptrArr,size);
            coutDelArr(ptrArr,size);
            return;
        }
    }
    
}
void coutDelArr(int **& ptrArr, size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        for(size_t j = 0; j < size; j++)
        {
            cout << ptrArr[i][j] << " ";
        }
        delete[] ptrArr[i];
        cout << endl;
    }
    delete[] ptrArr;
}
void task2()
{

    const size_t size = 4;
    int** ptrArr = new int* [size];

    for(size_t i = 0; i < size; i++)
    {
        ptrArr[i] = new int [size];
        for(size_t j = 0; j < size; j++)
        {
            ptrArr[i][j] = rand() % 10;
        }
    }
    coutDelArr(ptrArr,size);

        
}  

void task3_1(string &f)
{

    ofstream fout (f);

    for (int i = 0; i < 10; i++) 
    {
        for(int j = 0; j < 10; j++)
        {
            fout << 1;
        }
        fout << endl;
    }  
    fout.close(); 
}

void task3_2(string &f)
{

    ofstream fout (f);
    for (int i = 0; i < 10; i++) 
    {
        for(int j = 0; j < 10; j++)
        {
            fout << 2;
        }
        fout << endl;
    } 
    fout.close();
}
void task4(string &f1, string &f2)
{
    ifstream fin1(f1); 
    ifstream fin2(f2); 
    ofstream fout ("concatinate.txt");

    if (fin1.is_open()) 
    {
        const size_t size = 255;
        char buf[size];
        while (!fin1.eof()) 
        {
            fin1.getline(buf, size);
            fout << buf << endl; 
        }
        fin1.close();
    }
    else
    {
        cout << "Error. Can not open file.";
    }

    if (fin2.is_open()) 
    {
        const size_t size = 255;
        char buf[size];
        while (!fin2.eof()) 
        {
            fin2.getline(buf, size);
            fout << buf << endl; 
        }
        fin2.close();
    }
    else
    {
        cout << "Error. Can not open file.";
    }
    fout.close();
}

void task5(string &f, string &word)
{
    ifstream fin(f); 
    if(fin.is_open())
    {
        while(!fin.eof())
        {
            string fileword;
            fin >> fileword;
            if(fileword == word)
            {
                cout << "True" << endl;
                return;
            }
        }
        cout << "False" << endl;
        fin.close();
    }
    else
    {
        cout << "Error. Can not open file.";
    }
}

int main()
{   
    cout <<"//////////////////task1///////////////////" << endl;
    task1();

    cout <<"//////////////////task2///////////////////" << endl;
    task2();

    cout <<"//////////////////task3///////////////////" << endl;
    cout << "Enter name of file 1:" << endl;
    string f1;
    cin >> f1;
    f1 += ".txt";

    cout << "Enter name of file 2:" << endl;
    string f2;
    cin >> f2;
    f2 += ".txt";

    task3_1(f1);
    task3_2(f2);
   
    cout <<"//////////////////task4///////////////////" << endl;
    cout << "Enter name of file 1:" << endl;
    cin >> f1;
    f1 += ".txt";

    cout << "Enter name of file 2:" << endl;
    cin >> f2;
    f2 += ".txt";
    task4(f1, f2);

    cout <<"//////////////////task5///////////////////" << endl;
    cout << "Enter name of file:" << endl;
    string f3;
    cin >> f3;
    cout << "Enter word:" << endl;
    string word;
    cin >> word;
    task5(f3,word);
}