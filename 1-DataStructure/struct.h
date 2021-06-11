#pragma once
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
void Save2Matrix(Graph G, Edgetype* D, int sourse);	//保存路径长度至矩阵M中
void Print_Matrix(Graph G);								//打印距离矩阵 

void Dijkstra(Graph G, int n);							//求出源点n到达各顶点的最短路径
void Find_Max_Shortest_Path(Graph G);					//从矩阵M中找到最短路径长度最大的两个顶点

void KeyPath(Graph G, int sourse);						//求出源点n到达各顶点的关键路径 (最长路径） 
void Find_Max_Longest_Path(Graph G);					//从矩阵M中找到最长路径长度最大的两个顶点