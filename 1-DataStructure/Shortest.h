#include "struct.h"
#pragma once
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
	cout << y << '(' << G->adjlist[y].data << ')' << ",路径长度为" << maxl << endl << endl;
}