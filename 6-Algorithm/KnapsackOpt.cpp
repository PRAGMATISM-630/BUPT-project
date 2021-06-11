#include<cstdio>
#pragma warning(disable:4996)

const int maxn = 5000;
int c[maxn];
int w[maxn];

typedef struct
{
	int x;
	int y;
}Point;

int main()
{
	FILE *fp;
	fp = fopen("bag.in", "r");
	int v, n;
	fscanf(fp,"%d %d", &v, &n);
	for (int i = 1; i <= n; i++)
		fscanf(fp,"%d %d", &c[i], &w[i]);

	Point** p = new Point * [n + 2];
	Point** q = new Point * [n + 2];

	for (int i = 0; i <= n + 1; i++)
	{
		p[i] = new Point[maxn];
		q[i] = new Point[maxn];
	}

	Point t;
	t.x = 0;
	t.y = 0;
	p[n + 1][0] = t;

	int pn1 = 1;		//p[n+1]的跳跃点个数
	int qn1 = 0;		//q[n+1]的跳跃点个数
	int pn = 0;			//p[n]的跳跃点个数

	while (n)
	{
		for (int i = 0; i < pn1; i++)
		{
			Point tmp;
			tmp.x = p[n + 1][i].x + c[n];
			tmp.y = p[n + 1][i].y + w[n];
			if (tmp.x <= v)
				q[n + 1][qn1++] = tmp;
		}

		int i = 0, j = 0;
		while (i < pn1 && j < qn1)
		{
			if (p[n + 1][i].x < q[n + 1][j].x || p[n + 1][i].x == q[n + 1][j].x && p[n + 1][i].y < q[n + 1][j].y)
			{
				if (pn != 0)
				{
					Point last = p[n][pn - 1];
					if (last.x == p[n + 1][i].x && last.y < p[n + 1][i].y)
						pn--;
					if (last.x < p[n + 1][i].x && last.y > p[n + 1][i].y)
					{
						i++;
						continue;
					}
				}
				p[n][pn++] = p[n + 1][i++];
			}
			else
			{
				if (pn != 0)
				{
					Point last = p[n][pn - 1];
					if (last.x == q[n + 1][j].x && last.y < q[n + 1][j].y)
						pn--;
					if (last.x < q[n + 1][j].x && last.y > q[n + 1][j].y)
					{
						j++;
						continue;
					}
				}
				p[n][pn++] = q[n + 1][j++];
			}
		}
		while (i < pn1)
		{
			if (pn != 0)
			{
				Point last = p[n][pn - 1];
				if (last.x == p[n + 1][i].x && last.y < p[n + 1][i].y)
					pn--;
				if (last.x < p[n + 1][i].x && last.y > p[n + 1][i].y)
				{
					i++;
					continue;
				}
			}
			p[n][pn++] = p[n + 1][i++];
		}
		while (j < qn1)
		{
			if (pn != 0)
			{
				Point last = p[n][pn - 1];
				if (last.x == q[n + 1][j].x && last.y < q[n + 1][j].y)
					pn--;
				if (last.x < q[n + 1][j].x && last.y > q[n + 1][j].y)
				{
					j++;
					continue;
				}
			}
			p[n][pn++] = q[n + 1][j++];
		}
		n--;
		pn1 = pn;
		qn1 = 0;
		pn = 0;
	}

	FILE* fp2;
	fp2 = fopen("bag.out", "w");
	fprintf(fp2,"%d\n", p[1][pn1 - 1].y);
}
