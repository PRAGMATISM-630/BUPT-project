/*
 * 本题结合了回溯法和分支限界法
 * 首先通过贪心算法获取一个上界，超过上界的分支将会被减去
 * 然后用一个数组a记录最小n条边的和
 * 当已经确定了一部分路径后时，记录下当前所有已确定的路径的路程总和
 * 这时进行判断：假设剩下的路径全选择最小的n条边，如果超过了上界，那么它一定不是一个可行解
 */
#include<cstdio>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

const int max_city = 25;
int num_city;
int graph[max_city][max_city];		//邻接矩阵
int a[max_city * max_city];			//保存前n条最小路程的边的和
int nowbest = 0;					//当前值
int best;							//最优值
int bestpath[max_city];				//最优解

int getUpbound()			//使用贪心算法获取一个上界
{
	bool visited[max_city];

	for (int i = 2; i <= num_city; i++)
		visited[i] = false;

	int nownode = 1;			//当前结点
	int minnode = 2;			//局部最优结点
	int minvalue;				//局部最优值
	int upbound = 0;
	for (int k = 1; k < num_city; k++)
	{
		minvalue = 0x3f3f3f3f;
		visited[nownode] = true;
		for (int i = 2; i <= num_city; i++)
		{
			if (i != nownode && !visited[i])
			{
				if (minvalue > graph[nownode][i])
				{
					minvalue = graph[nownode][i];
					minnode = i;
				}
			}
		}
		nownode = minnode;
		upbound += minvalue;
	}
	return upbound + graph[nownode][1];
}

void TSP(int n)
{
	if (n == num_city)
	{
		if (nowbest + graph[bestpath[n]][1] + graph[bestpath[n - 1]][bestpath[n]] < best)
			best = nowbest + graph[bestpath[n]][1] + graph[bestpath[n - 1]][bestpath[n]];
		return;
	}
	for (int i = n; i <= num_city; i++)
	{
		swap(bestpath[n], bestpath[i]);
		nowbest += graph[bestpath[n - 1]][bestpath[n]];
		if (nowbest + a[num_city - n] < best)
			TSP(n + 1);
		nowbest -= graph[bestpath[n - 1]][bestpath[n]];
		swap(bestpath[n], bestpath[i]);
	}
}

void init()
{
	FILE* fp;
	fp = fopen("travel.in", "r");
	fscanf(fp,"%d", &num_city);
	int t;
	int cnt = 0;

	for (int i = 1; i < num_city; i++)
		for (int j = 1; j <= num_city - i; j++)
		{
			fscanf(fp, "%d", &graph[i][i + j]);
			graph[i + j][i] = graph[i][i + j];
			a[cnt++] = graph[i][i + j];
			a[cnt++] = graph[i][i + j];
		}

	sort(a, a + cnt);
	for (int i = 1; i < num_city * num_city; i++)
		a[i] += a[i - 1];

	for (int i = 1; i <= num_city; i++)
		bestpath[i] = i;

	best = getUpbound();
}

int main()
{
	init();
	TSP(2);

	FILE* fp;
	fp = fopen("travel.out", "w");
	fprintf(fp,"%d", best);
}