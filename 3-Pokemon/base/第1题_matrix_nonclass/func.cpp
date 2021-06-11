#include<iostream>
#include"head.h"

//通过cin输入初始化矩阵
void Initialization(int** A)
{
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < rows; j++)
			std::cin >> A[i][j];
}


//矩阵格式化输出到cout
void PrintMatrix(int** A)
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < rows; j++)
			std::cout << A[i][j] << ' ';
		std::cout << std::endl;
	}
}


//矩阵相加
void Add(int** A1,int** A2,int **A3)
{
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < rows; j++)
			A3[i][j] = A1[i][j] + A2[i][j];
}


//矩阵相减
void Sub(int** A1,int** A2,int** A3)
{
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < rows; j++)
			A3[i][j] = A1[i][j] - A2[i][j];
}