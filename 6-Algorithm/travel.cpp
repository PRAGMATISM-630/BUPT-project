/*
 * �������˻��ݷ��ͷ�֧�޽編
 * ����ͨ��̰���㷨��ȡһ���Ͻ磬�����Ͻ�ķ�֧���ᱻ��ȥ
 * Ȼ����һ������a��¼��Сn���ߵĺ�
 * ���Ѿ�ȷ����һ����·����ʱ����¼�µ�ǰ������ȷ����·����·���ܺ�
 * ��ʱ�����жϣ�����ʣ�µ�·��ȫѡ����С��n���ߣ�����������Ͻ磬��ô��һ������һ�����н�
 */
#include<cstdio>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

const int max_city = 25;
int num_city;
int graph[max_city][max_city];		//�ڽӾ���
int a[max_city * max_city];			//����ǰn����С·�̵ıߵĺ�
int nowbest = 0;					//��ǰֵ
int best;							//����ֵ
int bestpath[max_city];				//���Ž�

int getUpbound()			//ʹ��̰���㷨��ȡһ���Ͻ�
{
	bool visited[max_city];

	for (int i = 2; i <= num_city; i++)
		visited[i] = false;

	int nownode = 1;			//��ǰ���
	int minnode = 2;			//�ֲ����Ž��
	int minvalue;				//�ֲ�����ֵ
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