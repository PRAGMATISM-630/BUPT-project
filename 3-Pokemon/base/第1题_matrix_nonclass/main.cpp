#include<iostream>
#include"head.h"

int main()
{
	//动态申请三个矩阵： A1 、 A2 、 A3
	int** A1 = new int*[lines];
	for (int i = 0; i < lines; i++)
		A1[i] = new int[rows];

	int** A2 = new int* [lines];
	for (int i = 0; i < lines; i++)
		A2[i] = new int[rows];

	int** A3 = new int* [lines];
	for (int i = 0; i < lines; i++)
		A3[i] = new int[rows];


	//初始化 A1 、 A2
	std::cout << "请输入一个整型矩阵A1（4行5列）" << std::endl;
	Initialization(A1);
	std::cout << "请输入另一个整型矩阵A2（4行5列）" << std::endl;
	Initialization(A2);


	//计算并输出 A3 = A1 加 A2， A3 = A1 减 A2
	Add(A1, A2, A3);
	std::cout << "\nA1+A2=\n";
	PrintMatrix(A3);

	Sub(A1, A2, A3);
	std::cout << "\nA1-A2=\n";
	PrintMatrix(A3);


	//释放矩阵空间
	for (int i = 0; i < lines; i++)
	{
		delete[] A1[i];
		delete[] A2[i];
		delete[] A3[i];
	}
	delete[] A1;
	delete[] A2;
	delete[] A3;


	return 0;
}