#include<iostream>
#include"head.h"
using namespace std;

int main()
{
	double x1, y1, r1;
	double x2, y2, r2;

	cout << "请依次输入第一个圆的圆心横坐标，圆心纵坐标及半径" << endl;
	cin >> x1 >> y1 >> r1;
	cout << "请依次输入第二个圆的圆心横坐标，圆心纵坐标及半径" << endl;
	cin >> x2 >> y2 >> r2;

	Point P1(x1, y1);
	Point P2(x2, y2);
	Circle C1(P1, r1);
	Circle C2(P2, r2);

	C1.Intersect(C2);

}

/*
当给入测试样例
2.0 3.0 1.5
5.0 -1.0 4.5后，输出结果为：
Point构造函数
Point构造函数
Point拷贝构造函数
Circle构造函数
Point拷贝构造函数
Circle构造函数

两圆相交

Circle析构函数
Point析构函数
Circle析构函数
Point析构函数
Point析构函数
Point析构函数
*/

/*分析：

1.我们首先创建了两个Point类对象，因此调用了两次Point构造函数
	28行是P1的调用
	29行是P2的调用

2.接着，我们在创建Circle类对象时，采用了初始化的方法将Point类对象赋给Circle类对象的成员，
因此调用了两次Point拷贝构造函数，同时也自然调用了两次Circle构造函数
	30行是初始化C1的圆心P1调用的Point拷贝构造函数
	31行是C1的调用
	32行是初始化C2的圆心P2调用的Point拷贝构造函数
	33行是C2的调用

3.最后，当对象的生命周期结束时也就是程序执行完前，调用了Circle和Point的析构函数
因为程序是采用堆栈的方式，所以析构函数的调用顺序与构造函数恰好相反
	(37~42行依次对应33~28行）
*/