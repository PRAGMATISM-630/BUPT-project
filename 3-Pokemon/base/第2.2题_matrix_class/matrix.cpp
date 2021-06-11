#include"head.h"
using namespace std;

//构造函数
Matrix::Matrix(int line, int row):lines(line),rows(row)
{
	mat = new int* [lines];
	for (int i = 0; i < lines; i++)
		mat[i] = new int[rows];
}


//析构函数
Matrix::~Matrix()
{
	lines = 0;
	rows = 0;
	for (int i = 0; i < lines; i++)
		delete[] mat[i];
	delete[] mat;
	mat = nullptr;
}


//拷贝构造函数
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


//重载>>操作符以输入
istream& operator>>(istream& is, Matrix& M)
{
	for (int i = 0; i < M.lines; i++)
		for (int j = 0; j < M.rows; j++)
			is >> M.mat[i][j];
	return is;
}


//重载<<操作符以输出
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


//重载＋操作符以实现类类型的加法
const Matrix Matrix::operator+(const Matrix& M)const
{
	if (M.lines != lines || M.rows != rows)
	{
		cerr << "矩阵大小不等，不能相加" << endl;
		return *this;
	}

	Matrix A(lines, rows);
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < rows; j++)
			A.mat[i][j] = mat[i][j] + M.mat[i][j];
	return A;
}


//重载-操作符以实现类类型的减法
const Matrix Matrix::operator-(const Matrix& M)const
{
	if (M.lines != lines || M.rows != rows)
	{
		cerr << "矩阵大小不等，不能相减" << endl;
		return *this;
	}

	Matrix A(lines, rows);
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < rows; j++)
			A.mat[i][j] = mat[i][j] - M.mat[i][j];
	return A;
}


//重载=操作符以实现类类型的赋值
Matrix& Matrix::operator=(const Matrix &M)
{
	if (this == &M)						//自赋值
		return *this;

	if (M.lines != lines || M.rows != rows)
	{
		cerr << "矩阵大小不等，不能赋值" << endl;
		return *this;
	}

	for (int i = 0; i < lines; i++)		//释放旧元素
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