#include<cstdio>
#include<cstring>
#pragma warning(disable:4996)

const int maxn = 15;
int n;
int sum = 0;			//总方案数

/*
-----------------
|   |   |   |   |
-----------------
|   |   |   |   |
-----------------
|   |   |   |   |
-----------------
|   |   |   |   |
-----------------
*/

//从左上到右下的对角线，如上图中(4，1)记为p[1],(3,1)->(4,2)记为p[2]
//......(1,1)->(2,2)->(3,3)->(4,4)记为p[4]......(1,4)记为p[7]
//值为true表示这条对角线被占用
bool p[2 * maxn];		
//从右上到左下的对角线,如上图中(1，1)记为q[1],(1,2)->(2,1)记为q[2]
//......(1,4)->(2,3)->(3,2)->(4,1)记为q[4]......(4,4)记为q[7]
//值为true表示这条对角线被占用
bool q[2 * maxn];		
bool r[maxn];
int v[maxn];

void queen(int x)
{
	if (x > n)
		sum++;
	else
	{
		for (int y = 1; y <= n; y++)
		{
			if (!p[y - x + n] && !q[x + y - 1] && !r[y])	//列和两条对角线都未被占用
			{
				v[x] = y;
				p[y - x + n] = true;
				q[x + y - 1] = true;
				r[y] = true;
				queen(x + 1);
				p[y - x + n] = false;
				q[x + y - 1] = false;
				r[y] = false;
			}
		}
	}
}

int main()
{
	FILE* fp;
	fp = fopen("queen.in","r");
	fscanf(fp,"%d", &n);

	memset(p, false, 2 * maxn + 1);
	memset(q, false, 2 * maxn + 1);
	memset(r, false, maxn);
	memset(v, 0, maxn);
	queen(1);

	FILE* fp2;
	fp2 = fopen("queen.out", "w");
	fprintf(fp2,"%d", sum);
}

/*
课本上的解法：
int m[maxn];

bool place(int i)
{
	for (int j = 1; j < i; j++)
	{
		if (m[j] == m[i] || m[j] - m[i] == j - i || m[j] - m[i] == i - j)
			return false;
	}
	return true;
}

void queen(int t)
{
	if (t > n)
	{
		if (sum < 3)
		{
			for (int j = 1; j <= n; j++)
				printf("%d ", m[j]);
			printf("\n");
		}
		sum++;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			m[t] = i;
			if (place(t))
				queen(t + 1);
		}
	}
}
*/