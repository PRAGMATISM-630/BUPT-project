#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define MAX 700005
using namespace std;

typedef struct
{
	double x;
	double y;
}point;

point p[MAX];			//初始的点列
int a[MAX];			//记录按y排序的下标

int cmpx(point p, point q)			//比较两点的横坐标，用于传入sort函数的第三个参数
{
	return p.x < q.x;
}

int cmpy(int a, int b)			//比较两点的纵坐标，用于传入sort函数的第三个参数
{
	return p[a].y < p[b].y;
}

double dis(point p, point q)		//计算两点之间的距离
{
	return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

double closest(int l, int r)
{
	if (r - l == 1)		//只有2个点，直接返回他们之间的距离
	{
		return dis(p[l], p[r]);
	}

	if (r - l == 2)		//有3个点，返回三个距离中的最小值
	{
		double d1 = dis(p[l], p[l + 1]);
		double d2 = dis(p[l], p[r]);
		double d3 = dis(p[l + 1], p[r]);
		return min(min(d1, d2), d3);
	}

	int m = (l + r) / 2;
	int cnt = 0;
	double dm = min(closest(l, m), closest(m + 1, r));		//两个子问题解的最小值

	for (int i = l; i <= r; i++)
	{
		if (p[i].x - p[m].x <= dm && p[m].x - p[i].x <= dm)		//选出横坐标距离分割线小于dm的点放入p2
		{
			a[cnt++] = i;
		}
	}
	sort(a, a + cnt, cmpy);	//将P2中的点按纵坐标进行排序
	for (int i = 0; i < cnt; i++)
		for (int j = i + 1; j < cnt; j++)
		{
			if (p[a[j]].y - p[a[i]].y <= dm)
			{
				double d = dis(p[a[i]], p[a[j]]);
				if (d < dm)
					dm = d;
			}
			else break;
		}
	return dm;
}

int main()
{
	fstream fin("point.in", ios::in), fout("point.out", ios::out);
	int n;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> p[i].x >> p[i].y;
	}

	sort(p, p + n, cmpx);			//按x排序
	double result = closest(0, n - 1);
	fout.setf(ios::fixed);
	fout << setprecision(2) << result << endl;
}
