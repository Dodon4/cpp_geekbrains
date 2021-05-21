#include <iostream>
namespace tsixns {
	
	void setArr(float* pArr, size_t size)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << "Enter " << i << " num of array:" << std::endl;
			std::cin >> pArr[i];
		}
	}

	void printArr(float* pArr, size_t size)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << pArr[i] << " ";
		}
		std::cout << std::endl;
	}

	void CountPosNeg(float* pArr, size_t size)
	{
		int pos = 0, neg = 0;
		for (int i = 0; i < size; i++)
		{
			if (pArr[i] > 0)
			{
				pos++;
			}
			else if (pArr[i] < 0)
			{
				neg++;
			}
		}
		std::cout << "Num of pos:" << pos << std::endl << "Num of neg:" << neg << std::endl;
	}
}