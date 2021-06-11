#include<cstdio>
#include<queue>
#pragma warning(disable:4996)

using std::priority_queue;
using std::vector;
using std::less;

const int maxvex = 5005;
const int maxedge = 400005;
const int inf = -1;
int cnt = 0;
int numvex;
int numedge;
int head[maxvex];

struct EDGE
{
	int next;
	int to;
	int w;
};

EDGE edge[maxedge];

struct VEXCOST
{
	int vex;
	int cost;
};

bool operator<(const VEXCOST& A, const VEXCOST& B)
{
	return A.cost > B.cost;
}

void addEdge(int u, int v, int w)
{
	edge[cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

void prim()
{
	int res = 0;
	priority_queue<VEXCOST, vector<VEXCOST>, less<vector<VEXCOST>::value_type> >q;
	int* cost = new int[numvex + 1];
	bool* visited = new bool[numvex + 1];
	for (int i = 1; i <= numvex; i++)
	{
		cost[i] = -1;
		visited[i] = false;
	}
	q.push({ 1,0 });
	int now;
	while (!q.empty())
	{
		now = q.top().vex;
		int val = q.top().cost;
		q.pop();
		if (visited[now])
			continue;
		visited[now] = true;
		res += val;
		int pos = head[now];
		while (pos != -1)
		{
			if (visited[edge[pos].to])
			{
				pos = edge[pos].next;
				continue;
			}
			if (cost[edge[pos].to] == -1 || edge[pos].w < cost[edge[pos].to])
			{
				cost[edge[pos].to] = edge[pos].w;
				q.push({ edge[pos].to, cost[edge[pos].to] });
			}
			pos = edge[pos].next;
		}
	}

	bool flag = true;					//检查图是否连通
	for (int i = 1; i <= numvex; i++)
	{
		if (!visited[i])
			flag = false;
	}

	FILE* fp;
	fp = fopen("prim.out", "w");
	if (flag)							//连通输出结果
		fprintf(fp,"%d", res);
	else								//不连通输出-1
		fprintf(fp,"-1", res);
}

int main()
{
	FILE* fp;
	fp = fopen("prim.in", "r");

	int u, v, w;
	fscanf(fp,"%d%d", &numvex, &numedge);
	for (int i = 0; i <= numvex; i++)
	{
		head[i] = -1;
	}
	for (int i = 0; i < numedge; i++)
	{
		fscanf(fp,"%d%d%d", &u, &v, &w);
		addEdge(u, v, w);
		addEdge(v, u, w);
	}
	prim();
}
