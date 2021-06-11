#include"head.h"
using namespace std;

//���캯��
Matrix::Matrix(int line, int row):lines(line),rows(row)
{
	mat = new int* [lines];
	for (int i = 0; i < lines; i++)
		mat[i] = new int[rows];
}


//��������
Matrix::~Matrix()
{
	lines = 0;
	rows = 0;
	for (int i = 0; i < lines; i++)
		delete[] mat[i];
	delete[] mat;
	mat = nullptr;
}


//�������캯��
Matrix::Matrix(const Matrix& M)
{
	lines = M.lines;
	rows = M.rows;

	mat = new int* [lines];
	for (int i = 0; i < lines; i++)
		mat[i] = new int[rows];

	for (int i = 0; i < lines; i++)
		for (int j = 0; j < rows; j++)
			mat[i][j] = M.mat[i][j];
}


//����>>������������
istream& operator>>(istream& is, Matrix& M)
{
	for (int i = 0; i < M.lines; i++)
		for (int j = 0; j < M.rows; j++)
			is >> M.mat[i][j];
	return is;
}


//����<<�����������
ostream& operator<<(ostream& os,const Matrix& M)
{
	for (int i = 0; i < M.lines; i++)
	{
		for (int j = 0; j < M.rows; j++)
			os << M.mat[i][j] << ' ';
		cout << endl;
	}
	return os;
}


//���أ���������ʵ�������͵ļӷ�
const Matrix Matrix::operator+(const Matrix& M)const
{
	if (M.lines != lines || M.rows != rows)
	{
		cerr << "�����С���ȣ��������" << endl;
		return *this;
	}

	Matrix A(lines, rows);
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < rows; j++)
			A.mat[i][j] = mat[i][j] + M.mat[i][j];
	return A;
}


//����-��������ʵ�������͵ļ���
const Matrix Matrix::operator-(const Matrix& M)const
{
	if (M.lines != lines || M.rows != rows)
	{
		cerr << "�����С���ȣ��������" << endl;
		return *this;
	}

	Matrix A(lines, rows);
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < rows; j++)
			A.mat[i][j] = mat[i][j] - M.mat[i][j];
	return A;
}


//����=��������ʵ�������͵ĸ�ֵ
Matrix& Matrix::operator=(const Matrix &M)
{
	if (this == &M)						//�Ը�ֵ
		return *this;

	if (M.lines != lines || M.rows != rows)
	{
		cerr << "�����С���ȣ����ܸ�ֵ" << endl;
		return *this;
	}

	for (int i = 0; i < lines; i++)		//�ͷž�Ԫ��
		delete[] mat[i];
	delete[] mat;

	lines = M.lines;
	rows = M.rows;

	mat = new int* [lines];
	for (int i = 0; i < lines; i++)
		mat[i] = new int[rows];

	for (int i = 0; i < lines; i++)
		for (int j = 0; j < rows; j++)
			mat[i][j] = M.mat[i][j];

	return *this;
}