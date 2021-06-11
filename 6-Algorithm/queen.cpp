#include<cstdio>
#include<cstring>
#pragma warning(disable:4996)

const int maxn = 15;
int n;
int sum = 0;			//�ܷ�����

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

//�����ϵ����µĶԽ��ߣ�����ͼ��(4��1)��Ϊp[1],(3,1)->(4,2)��Ϊp[2]
//......(1,1)->(2,2)->(3,3)->(4,4)��Ϊp[4]......(1,4)��Ϊp[7]
//ֵΪtrue��ʾ�����Խ��߱�ռ��
bool p[2 * maxn];		
//�����ϵ����µĶԽ���,����ͼ��(1��1)��Ϊq[1],(1,2)->(2,1)��Ϊq[2]
//......(1,4)->(2,3)->(3,2)->(4,1)��Ϊq[4]......(4,4)��Ϊq[7]
//ֵΪtrue��ʾ�����Խ��߱�ռ��
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
			if (!p[y - x + n] && !q[x + y - 1] && !r[y])	//�к������Խ��߶�δ��ռ��
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
�α��ϵĽⷨ��
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