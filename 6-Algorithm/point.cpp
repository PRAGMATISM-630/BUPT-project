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

point p[MAX];			//��ʼ�ĵ���
int a[MAX];			//��¼��y������±�

int cmpx(point p, point q)			//�Ƚ�����ĺ����꣬���ڴ���sort�����ĵ���������
{
	return p.x < q.x;
}

int cmpy(int a, int b)			//�Ƚ�����������꣬���ڴ���sort�����ĵ���������
{
	return p[a].y < p[b].y;
}

double dis(point p, point q)		//��������֮��ľ���
{
	return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

double closest(int l, int r)
{
	if (r - l == 1)		//ֻ��2���㣬ֱ�ӷ�������֮��ľ���
	{
		return dis(p[l], p[r]);
	}

	if (r - l == 2)		//��3���㣬�������������е���Сֵ
	{
		double d1 = dis(p[l], p[l + 1]);
		double d2 = dis(p[l], p[r]);
		double d3 = dis(p[l + 1], p[r]);
		return min(min(d1, d2), d3);
	}

	int m = (l + r) / 2;
	int cnt = 0;
	double dm = min(closest(l, m), closest(m + 1, r));		//��������������Сֵ

	for (int i = l; i <= r; i++)
	{
		if (p[i].x - p[m].x <= dm && p[m].x - p[i].x <= dm)		//ѡ�����������ָ���С��dm�ĵ����p2
		{
			a[cnt++] = i;
		}
	}
	sort(a, a + cnt, cmpy);	//��P2�еĵ㰴�������������
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

	sort(p, p + n, cmpx);			//��x����
	double result = closest(0, n - 1);
	fout.setf(ios::fixed);
	fout << setprecision(2) << result << endl;
}
