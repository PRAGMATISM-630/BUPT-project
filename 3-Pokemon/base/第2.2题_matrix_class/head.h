#pragma once
#include<iostream>

class Matrix
{
public:
	Matrix():lines(0),rows(0),mat(nullptr){};			//默认构造函数
	Matrix(int line, int row);							//构造函数
	~Matrix();											//析构函数
	Matrix(const Matrix&M);								//拷贝构造函数
	friend std::istream& operator>>(std::istream& is, Matrix &M);		//输入
	friend std::ostream& operator<<(std::ostream& os, const Matrix &M);	//输出
	const Matrix operator+(const Matrix &M)const;						//加法
	const Matrix operator-(const Matrix &M)const;						//减法
	Matrix& operator=(const Matrix &M);									//赋值

private:				//矩阵大小
	int lines;			//行数
	int rows;			//列数
	int** mat;			//指向数组的指针
};