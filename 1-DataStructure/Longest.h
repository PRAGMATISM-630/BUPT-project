#include "struct.h"
#pragma once

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
		if(!Q.empty())
		now = Q.front();								//下个循环更新当前队首顶点的所有后继 
	}
	Save2Matrix(G, D, sourse);							//存到矩阵M中 
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
	cout << y << '(' << G->adjlist[y].data << ')' << ",路径长度为" << maxl << endl << endl;
}