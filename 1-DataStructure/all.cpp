#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;

typedef int Vertextype;									//顶点数据类型，默认为int
typedef int Edgetype;									//边权值数据类型，默认为int
const int MAXVEX = 200;									//最大顶点数
const int MAXEDGE = 10000;								//最大边数 
const int INF = 0x3f3f3f3f;								//无穷大的值，表示无路径
Edgetype M[MAXVEX][MAXVEX];								//保存最短路径长度的矩阵

//以邻接表方式存储的图
typedef struct edgenode									//边表
{
	Edgetype weight;
	int adjvex;
	struct edgenode* nextedge;
}Edgenode, * Edge;
typedef struct											//顶点结构
{
	Vertextype data;
	Edge firstedge;
}Vertex, Adjlist;
typedef struct											//图结构
{
	int numvex, numedge;
	Adjlist adjlist[MAXVEX];
}graph, * Graph;

Graph CreateGraph();									//建立图
void traceback(Graph G, int n, int* P);					//打印路径
void Save2Matrix(Graph G, Edgetype * D, int sourse);	//保存路径长度至矩阵M中
void Print_Matrix(Graph G);								//打印距离矩阵 

void Dijkstra(Graph G, int n);							//求出源点n到达各顶点的最短路径
void Find_Max_Shortest_Path(Graph G);					//从矩阵M中找到最短路径长度最大的两个顶点

void KeyPath(Graph G, int sourse);						//求出源点n到达各顶点的关键路径 (最长路径） 
void Find_Max_Longest_Path(Graph G);					//从矩阵M中找到最长路径长度最大的两个顶点

Graph CreateGraph()										//建立图
{
	Graph G = (Graph)malloc(sizeof(graph));
	if (G == NULL)
	{
		cout << "内存不足" << endl;
		exit(1);
	}
	cout << "请输入图的顶点数和边数" << endl;
	cin >> G->numvex >> G->numedge;
	if(G->numvex>=MAXVEX)
	{
		cout<<"顶点数过大，程序终止"<<endl;
		exit(1);
	}
	if(G->numedge>=MAXEDGE)
	{
		cout<<"边数过大，程序终止"<<endl;
		exit(1);
	}
	cout << "请依次输入每个顶点的数据，用空格间隔" << endl;
	for (int i = 1; i <= G->numvex; i++)
	{
		cin >> G->adjlist[i].data;
		G->adjlist[i].firstedge = NULL;
	}
	int u, v;
	Edgetype w;
	cout << "请依次输入所有的边的起点，终点，权值" << endl;
	for (int i = 1; i <= G->numedge; i++)
	{
		Edge e = (Edge)malloc(sizeof(edgenode));
		if (e == NULL)
		{
			cout << "内存不足" << endl;
			exit(1);
		}
		cin >> u >> v >> w;
		e->weight = w;
		e->nextedge = G->adjlist[u].firstedge;
		e->adjvex = v;
		G->adjlist[u].firstedge = e;
	}
	return G;
}

void traceback(Graph G, int n, int* P)					//打印路径
{
	if (P[n] != -1)
		traceback(G, P[n], P);
	cout << n << '(' << G->adjlist[n].data << ')' << ' ';
}

void Save2Matrix(Graph G, Edgetype * D, int sourse)		//保存路径长度至矩阵M中
{
	for (int i = 1; i <= G->numvex; i++)
		M[sourse][i] = D[i];
}

void Print(Graph G, int n, Edgetype * D, int* P)		//打印从源点sourse到所有顶点的最短路径及长度
{
	for (int i = 1; i <= G->numvex; i++)
	{
		cout << "从顶点" << n << '(' << G->adjlist[n].data << ')' << "到顶点" << i << '(' << G->adjlist[i].data << ')' << "的最短距离是";
		if (D[i] == INF)
		//if (fabs(D[i] - INF) <= 1e-6)					//若边权值为浮点类型 
		{
			cout << "∞\t";
			cout << "没有从顶点" << n << '(' << G->adjlist[n].data << ')' << "到顶点" << i << '(' << G->adjlist[i].data << ')' << "的路径" << endl;
		}
		else
		{
			cout << D[i] << '\t';
			cout << "从顶点" << n << '(' << G->adjlist[n].data << ')' << "到顶点" << i << '(' << G->adjlist[i].data << ')' << "的最短路径是:";
			traceback(G, i, P);
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
}

void Print_Matrix(Graph G)								//打印距离矩阵 
{
	for (int i = 1; i <= G->numvex; i++)
	{
		for (int j = 1; j <= G->numvex; j++)
			if (M[i][j] != INF)
				cout << M[i][j] << ' ';
			else cout << "∞ ";
		cout << endl;
	}
}

void Dijkstra(Graph G, int n)							//求出源点n到达各顶点的最短路径
{
	bool S[MAXVEX];										//标记是否已经确定了最短路径，true表示已确定
	Edgetype D[MAXVEX];									//存储当前最短路径长度
	int P[MAXVEX];										//存储当前访问到的顶点在当前最短路径上的前驱
	for (int i = 1; i <= G->numvex; i++)
	{
		S[i] = false;
		D[i] = INF;
		P[i] = -1;
	}
	D[n] = 0;
	int tmp = n;										//tmp用于保存源点，以便后面恢复
	while (!S[n])
	{
		S[n] = true;
		Edge e = G->adjlist[n].firstedge;
		while (e)										//更新到达当前所有可达顶点的最短路径
		{
			if (D[n] + e->weight < D[e->adjvex])
			{
				D[e->adjvex] = D[n] + e->weight;
				P[e->adjvex] = n;
			}
			e = e->nextedge;
		}
		Edgetype nowmin = INF;
		int now = 1;
		for (int i = 1; i <= G->numvex; i++)			//找出D[i]中的最小值，存到nowmin中，并将i存到now中
			if (nowmin > D[i] && S[i] != 1)
			{
				nowmin = D[i];
				now = i;
			}
		n = now;										//n改为D[i]最小的那个顶点，继续下次循环
	}
	n = tmp;
	Save2Matrix(G, D, n);								//保存从源点n出发到达各顶点的最短路径长度
	//Print(G, n, D, P);								//打印从源点开始到所有顶点的最短路径及长度
}

void Find_Max_Shortest_Path(Graph G)							//从矩阵M中找到最短路径长度最大的两个顶点
{
	Edgetype maxl = -INF;										//用maxl保存所有距离中的最大值
	int x = 1, y = 1;
	for (int i = 1; i <= G->numvex; i++)						//遍历距离矩阵，更新maxl
		for (int j = 1; j <= G->numvex; j++)
			if (M[i][j] != INF && maxl < M[i][j])
			//if (!(fabs(M[i][j] - INF) <= 1e-6) && maxl < M[i][j])		//如果边权值是浮点类型 
			{
				maxl = M[i][j];
				x = i; y = j;
			}
	cout << "图中距离最远的两个顶点为" << x << '(' << G->adjlist[x].data << ')' << "和";
	cout << y << '(' << G->adjlist[y].data << ')' << ",路径长度为" << maxl << endl<<endl;
}

void KeyPath(Graph G, int sourse)						//求出源点sourse到达各顶点的关键路径 (最长路径）
{
	Edgetype D[MAXVEX];									//存储当前最长路径的长度 
	queue<int>Q;										//队列Q声明 
	for (int i = 1; i <= G->numvex; i++)
		D[i] = INF;
	int now = sourse;
	D[now] = 0;
	Q.push(now);
	while (!Q.empty())									//将顶点依次入队列出队列直到队列为空 
	{
		Q.pop();
		Edge e = G->adjlist[now].firstedge;
		while (e)										//更新所有后继顶点的最长路径长度，使之尽可能大 
		{
			Q.push(e->adjvex);
			if (D[e->adjvex] == INF)					//原本没有路径，现在有了 
				D[e->adjvex] = D[now] + e->weight;
			if (D[e->adjvex] < D[now] + e->weight)
				D[e->adjvex] = D[now] + e->weight;
			e = e->nextedge;
		}
		now = Q.front();								//下个循环更新当前队首顶点的所有后继 
	}
	Save2Matrix(G,D,sourse);							//存到矩阵M中 
}

void Find_Max_Longest_Path(Graph G)						//从矩阵M中找到最长路径长度最大的两个顶点
{
	Edgetype maxl = 0;
	int x = 1, y = 1;
	for (int i = 1; i <= G->numvex; i++)
		for (int j = 1; j <= G->numvex; j++)
			if (M[i][j] != INF && M[i][j] > maxl)
			{
				maxl = M[i][j];
				x = i; y = j;
			}
	cout << "图中距离最远的两个顶点为" << x << '(' << G->adjlist[x].data << ')' << "和";
	cout << y << '(' << G->adjlist[y].data << ')' << ",路径长度为" << maxl << endl<<endl;
}

int main()
{
	Graph G = CreateGraph();
	cout<<"若求顶点间最短距离的最大值："<<endl; 
	for (int i=1;i<=G->numvex;i++)			//将每个顶点作为源点执行一次dijkstra算法	
		Dijkstra(G, i);
	//cout<<"最短路径长度的距离矩阵为:\n";
	//Print_Matrix(G);
	Find_Max_Shortest_Path(G);
	cout<<"若求顶点间最长距离的最大值："<<endl; 
	for (int i=1;i<=G->numvex;i++)			//将每个顶点作为源点执行一次求关键路径长度算法 
		KeyPath(G, i);
	//cout<<"最长路径长度的距离矩阵为:\n"; 
	//Print_Matrix(G);
	Find_Max_Longest_Path(G);
	return 0;
}

/*
测试数据1：
5 7
1 2 3 4 5
1 2 10
1 4 30
1 5 100
2 3 50
3 5 10
4 3 20
4 5 60
测试数据2：
9 11
1 2 3 4 5 6 7 8 9
1 2 6
1 3 4
1 4 5
2 5 1
3 5 1
4 6 2
5 7 9
5 8 7
5 8 4
7 9 2
8 9 4 
测试数据3：
8 10
1 2 3 4 5 6 7 8
1 2 2
1 3 3
3 4 3
2 4 5
3 5 10
4 6 4
6 5 2
5 7 3
7 8 1
6 8 6
测试数据4：
2 1
1 2
2 1 3 
*/
