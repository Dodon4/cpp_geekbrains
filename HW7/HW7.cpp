#include <iostream>
#include <string>
#include <fstream>
#include "mylib.h"
using namespace std;

#define TASK2(a, b) (a >= 0 && a < b ? true : false)
#define SIZEARR 10
#define SWAPINT(a, b) int tmp = a; a = b; b = tmp;

void task2()
{
	int a, b;
	cout << "Enter num:" << endl;
	cin >> a;
	cout << "Enter lim num:" << endl;
	cin >> b;

	if (TASK2(a, b))
		cout << "true" << endl;
	else
		cout << "false" << endl;

}
void printArr(int* pArr)
{
	for (int i = 0; i < SIZEARR; i++)
	{
		cout << pArr[i] << " ";
	}
	cout << endl;
}
void setArr(int* pArr)
{
	for (int i = 0; i < SIZEARR; i++)
	{
		cout << "Enter " << i << " num of array:" << endl;
		cin >> pArr[i];
	}
}

void sort(int* pArr)
{
	for (int i = 0; i < SIZEARR; i++)
	{
		for (int j = 0; j < SIZEARR - i; j++)
		{
			if (pArr[j] < pArr[j + 1])
			{
				SWAPINT(pArr[j], pArr[j + 1]);
			}
		}
	}
}

void task3()
{
	int* pArr;
	pArr = new int[SIZEARR];

	setArr(pArr);
	sort(pArr);
	printArr(pArr);

	delete[] pArr;
}

#pragma pack(push, 1)
struct Employee
{
	unsigned int id, salary;
	string FirstName;
	string SecondName;
};
#pragma pack(pop)

void printEmp(Employee* em)
{
	cout << "id:" << em->id << endl << "salary:" << em->salary << endl
		<< "First name:" << em->FirstName << endl << "Second name:" << em->SecondName;
}

void writeFile(Employee* em)
{
	ofstream fout("Employee.txt");
	fout << "id:" << em->id << endl;
	fout << "salary:" << em->salary << endl;
	fout << "FirstName:" << em->FirstName << endl;
	fout << "SecondName:" << em->SecondName << endl;
}
void task4()
{
	Employee* pEm = new Employee;
	pEm->id = 5345325;
	pEm->salary = 100000;
	pEm->FirstName = "Alexandr";
	pEm->SecondName = "Dodonov";
	printEmp(pEm);
	cout << "Size of Employee:" << sizeof(Employee) << endl;
	writeFile(pEm);
	delete pEm;
}

int main()
{
	cout << "////////////////////task2//////////////////" << endl;
	task2();

	cout << "////////////////////task3//////////////////" << endl;
	task3();

	cout << "////////////////////task4//////////////////" << endl;
	task4();

	cout << "////////////////////task5//////////////////" << endl;
	const size_t size = 10;
	float* pArr = new float[size];
	tsixns::setArr(pArr, size);
	tsixns::printArr(pArr, size);
	tsixns::CountPosNeg(pArr, size);
	delete[] pArr;
	return 0;

}
