#include<cstdio>
#include<queue>
#pragma warning(disable:4996)
using std::priority_queue;
using std::vector;
using std::less;

const int maxedge = 400005;
const int maxvex = 5005;
const int inf = 0x3f3f3f3f;
int cnt = 0;
int head[maxvex];
int numvex;
int numedge;

struct EDGE
{
	int next;
	int to;
	int w;
};
EDGE edge[maxedge];

struct VEXDIST
{
	int vex;
	int dist;
};

void addEdge(int u,int v,int w)
{
	edge[cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

bool operator<(const VEXDIST& A, const VEXDIST& B)
{
	return A.dist > B.dist;
}

void dijkstra(int src,int dest)
{
	int* dist = new int[numvex + 1];		//从源src到各顶点的最短距离
	bool* visited = new bool[numvex + 1];	//标记顶点是否被访问

	for (int i = 1; i <= numvex; i++)
	{
		dist[i] = inf;
		visited[i] = false;
	}
	dist[src] = 0;

	priority_queue<VEXDIST, vector<VEXDIST>, less<vector<VEXDIST>::value_type> >q;
	q.push({ src,0 });

	int now;		//当前访问的顶点
	while (!q.empty())
	{
		now = q.top().vex;
		q.pop();
		if (visited[now])
			continue;
		visited[now] = true;

		int pos = head[now];	//以now为起点的边
		while (pos != -1)
		{
			if (!visited[edge[pos].to] && dist[now] + edge[pos].w < dist[edge[pos].to])
			{
				dist[edge[pos].to] = dist[now] + edge[pos].w;
				q.push({ edge[pos].to ,dist[edge[pos].to] });
			}
			pos = edge[pos].next;
		}
	}

	FILE* fp;
	fp = fopen("dijkstra.out", "w");
	if(dist[dest]==inf)
		fprintf(fp, "-1", dist[dest]);
	else
		fprintf(fp,"%d",dist[dest]);
}

int main()
{
	FILE* fp;
	fp = fopen("dijkstra.in", "r");
	int u, v, w;
	fscanf(fp,"%d%d", &numvex, &numedge);

	for (int i = 0; i < numvex; i++)
	{
		head[i] = -1;
	}

	for (int i = 1; i <= numedge; i++)
	{
		fscanf(fp,"%d%d%d", &u, &v, &w);
		addEdge(u, v, w);
		addEdge(v, u, w);	//无向图要添加上这行
	}
	dijkstra(1,numvex);
}