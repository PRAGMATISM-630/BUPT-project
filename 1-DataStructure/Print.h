#include "struct.h"
#pragma once
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
	if (G->numvex >= MAXVEX)
	{
		cout << "顶点数过大，程序终止" << endl;
		exit(1);
	}
	if (G->numedge >= MAXEDGE)
	{
		cout << "边数过大，程序终止" << endl;
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
