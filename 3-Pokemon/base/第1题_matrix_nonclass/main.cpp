#include<iostream>
#include"head.h"

int main()
{
	//��̬������������ A1 �� A2 �� A3
	int** A1 = new int*[lines];
	for (int i = 0; i < lines; i++)
		A1[i] = new int[rows];

	int** A2 = new int* [lines];
	for (int i = 0; i < lines; i++)
		A2[i] = new int[rows];

	int** A3 = new int* [lines];
	for (int i = 0; i < lines; i++)
		A3[i] = new int[rows];


	//��ʼ�� A1 �� A2
	std::cout << "������һ�����;���A1��4��5�У�" << std::endl;
	Initialization(A1);
	std::cout << "��������һ�����;���A2��4��5�У�" << std::endl;
	Initialization(A2);


	//���㲢��� A3 = A1 �� A2�� A3 = A1 �� A2
	Add(A1, A2, A3);
	std::cout << "\nA1+A2=\n";
	PrintMatrix(A3);

	Sub(A1, A2, A3);
	std::cout << "\nA1-A2=\n";
	PrintMatrix(A3);


	//�ͷž���ռ�
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