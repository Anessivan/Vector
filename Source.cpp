#include "Matrix.h"
#include "Vector.h"
#include <iostream>



int main()
{
	Matrix<double> Right(2,2);
	Matrix<double> Left(Right);
	Matrix<double> sum(Left);
	double n = sum[0][0];
	std::cout << sum << std::endl;
	std::cin >> sum;
	std::cout << std::endl << sum << std::endl;
	Left = sum;
	std::cout << std::endl << Left << std::endl;
	std::cin >> Left;
	std::cout << std::endl << Left << std::endl;
	Right = sum * Left;
	std::cout << "Matrix mult = " << Right << std::endl;
	Right = sum + Left;
	std::cout << "Matrix Sum = " << Right << std::endl;
	std::cout << "Vectors" << std::endl;
	vector<int> v(3);
	std::cout << v << std::endl;
	std::cin >> v;
	vector<int> v2(4);
	std::cin >> v2;
	vector<int> sum1 = v - v2;
	std::cout <<" vector differens = " << sum1 << std::endl;
	sum1 = v + v2;
	std::cout << " vector sum = " << sum1 << std::endl;
	int scalar = v * v2;
	std::cout << " vector  inner product = " << scalar << std::endl;
	int count = sum1.Count(4);
	std::cout <<"count of 4 = " <<  count << std::endl;
	vector<int*> t = sum1.find(4);
	std::cout << "find of 4 = ";
	for (int i = 0; i < t.length(); i++)
	{
		std::cout << t[i][0] << ' ';
	}
	sum1.BotleSort();
	std::cout << "Botle sort of sum: " << sum1;
	v.InsertSort();
	std::cout << "Insert sort of first vector " << v;
	v2.QuickSort();
	std::cout << "Quic sort of second vector" << v2;
}