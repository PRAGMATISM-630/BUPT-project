#include<iostream>
#include"head.h"

//ͨ��cin�����ʼ������
void Initialization(int** A)
{
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < rows; j++)
			std::cin >> A[i][j];
}


//�����ʽ�������cout
void PrintMatrix(int** A)
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < rows; j++)
			std::cout << A[i][j] << ' ';
		std::cout << std::endl;
	}
}


//�������
void Add(int** A1,int** A2,int **A3)
{
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < rows; j++)
			A3[i][j] = A1[i][j] + A2[i][j];
}


//�������
void Sub(int** A1,int** A2,int** A3)
{
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < rows; j++)
			A3[i][j] = A1[i][j] - A2[i][j];
}