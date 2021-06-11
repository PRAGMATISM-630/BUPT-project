/*
  �߼������ͼ
  û��ʹ�ñ�׼�Ĳ��鼯�ṹ���������˲��鼯˼��
*/
#include<cstdio>
#include<queue>
#pragma warning(disable:4996)

using std::priority_queue;
using std::vector;
using std::less;

int numvex;
int numedge;

struct EDGE		//�߼�����
{
	int from;
	int to;
	int w;
};
bool operator<(const EDGE& A, const EDGE& B)
{
	return A.w > B.w;
}

priority_queue<EDGE, vector<EDGE>, less<vector<EDGE>::value_type> >q;


void kruskal()
{
	int* parent = new int[numvex + 1];			//������ڵ�
	for (int i = 1; i <= numvex; i++)
		parent[i] = i;
	int res=0,i;
	
	for (i = 1; i < numvex&&!q.empty();)
	{
		EDGE edge = q.top();
		q.pop();
		int p1 = edge.from, p2 = edge.to;
		while (p1 != parent[p1])
			p1 = parent[p1];
		while (p2 != parent[p2])
			p2 = parent[p2];
		if (p1 != p2)
		{
			parent[p2] = p1;
			res += edge.w;
			i++;
		}
	}

	FILE* fp;
	fp = fopen("kruskal.out", "w");
	if (i == numvex)	//����ͨͼ
		fprintf(fp, "%d", res);
	else
		fprintf(fp, "-1");
}


int main()
{
	FILE* fp;
	fp = fopen("kruskal.in", "r");
	fscanf(fp,"%d%d", &numvex, &numedge);

	int u, v, w;
	for (int i = 1; i <= numedge; i++)
	{
		fscanf(fp,"%d%d%d", &u, &v, &w);
		q.push({ u,v,w });
	}
	kruskal();
}