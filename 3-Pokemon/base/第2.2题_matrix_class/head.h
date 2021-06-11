#pragma once
#include<iostream>

class Matrix
{
public:
	Matrix():lines(0),rows(0),mat(nullptr){};			//Ĭ�Ϲ��캯��
	Matrix(int line, int row);							//���캯��
	~Matrix();											//��������
	Matrix(const Matrix&M);								//�������캯��
	friend std::istream& operator>>(std::istream& is, Matrix &M);		//����
	friend std::ostream& operator<<(std::ostream& os, const Matrix &M);	//���
	const Matrix operator+(const Matrix &M)const;						//�ӷ�
	const Matrix operator-(const Matrix &M)const;						//����
	Matrix& operator=(const Matrix &M);									//��ֵ

private:				//�����С
	int lines;			//����
	int rows;			//����
	int** mat;			//ָ�������ָ��
};