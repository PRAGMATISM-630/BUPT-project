#pragma once

//矩阵大小为 4 × 5 （整型)
const int lines{ 4 };
const int rows{ 5 };

void Initialization(int **A);			//矩阵初始化

void PrintMatrix(int** A);				//格式化输出

void Add(int** A1,int** A2, int** A3);	//矩阵加法

void Sub(int** A1,int** A2, int** A3);	//矩阵减法

