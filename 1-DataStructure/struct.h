#pragma once
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;

typedef int Vertextype;									//�����������ͣ�Ĭ��Ϊint
typedef int Edgetype;									//��Ȩֵ�������ͣ�Ĭ��Ϊint
const int MAXVEX = 200;									//��󶥵���
const int MAXEDGE = 10000;								//������ 
const int INF = 0x3f3f3f3f;								//������ֵ����ʾ��·��
Edgetype M[MAXVEX][MAXVEX];								//�������·�����ȵľ���

//���ڽӱ�ʽ�洢��ͼ
typedef struct edgenode									//�߱�
{
	Edgetype weight;
	int adjvex;
	struct edgenode* nextedge;
}Edgenode, * Edge;
typedef struct											//����ṹ
{
	Vertextype data;
	Edge firstedge;
}Vertex, Adjlist;
typedef struct											//ͼ�ṹ
{
	int numvex, numedge;
	Adjlist adjlist[MAXVEX];
}graph, * Graph;

Graph CreateGraph();									//����ͼ
void traceback(Graph G, int n, int* P);					//��ӡ·��
void Save2Matrix(Graph G, Edgetype* D, int sourse);	//����·������������M��
void Print_Matrix(Graph G);								//��ӡ������� 

void Dijkstra(Graph G, int n);							//���Դ��n�������������·��
void Find_Max_Shortest_Path(Graph G);					//�Ӿ���M���ҵ����·������������������

void KeyPath(Graph G, int sourse);						//���Դ��n���������Ĺؼ�·�� (�·���� 
void Find_Max_Longest_Path(Graph G);					//�Ӿ���M���ҵ��·������������������