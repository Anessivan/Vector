#include "Matrix.h"
#include "Vector.h"
#include <iostream>
#include <ctime>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

template <class T>
void randomvector(vector<T>& v)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < v.length(); i++)
		v[i] = rand();
}

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
	std::cout << "Copy of Matrix"<< std::endl << Left << std::endl;
	std::cin >> Left;
	std::cout << std::endl << Left << std::endl;
	Right = sum * Left;
	std::cout << "Matrix mult = " << std::endl << Right << std::endl;
	Right = sum + Left;
	std::cout << "Matrix Sum = " << std::endl << Right << std::endl;
	std::cout << "Vectors" << std::endl;
	vector<int> v(3);
	std::cout << v << std::endl << "Enter vector with dimention = 3: ";
	std::cin >> v;
	vector<int> v2(4);
	std::cout << "Enter vector with dimention = 4: " << std::endl;
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
	vector<int> Bottle(5000);
	int timestart = clock();
	Bottle.BotleSort();
	int diff = clock() - timestart;
	std::cout << "Botle sort of vector with lenght = 5000 "  << "sort time: " << diff << std::endl;
	vector<int> Insert(5000);
	timestart = clock();
	Insert.InsertSort();
	diff = clock() - timestart;
	std::cout << "Insert sort of vector with lenght = 5000" << "sort time: " << diff << std::endl;
	vector<int> Quic(5000);
	timestart = clock();
	Quic.QuickSort();
	diff = clock() - timestart;
	std::cout << "Quic sort of vector with lenghth = 5000" << "sort time: " << diff << std::endl;
	Matrix<double> left_matrix;
	Matrix<double> right_matrix;
	Matrix<double> result_matrix;
	std::cin >> left_matrix >> right_matrix;
	result_matrix = left_matrix / right_matrix;
	std::cout << result_matrix;
	_getch();
}