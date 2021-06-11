#include "struct.h"
#pragma once
Graph CreateGraph()										//����ͼ
{
	Graph G = (Graph)malloc(sizeof(graph));
	if (G == NULL)
	{
		cout << "�ڴ治��" << endl;
		exit(1);
	}
	cout << "������ͼ�Ķ������ͱ���" << endl;
	cin >> G->numvex >> G->numedge;
	if (G->numvex >= MAXVEX)
	{
		cout << "���������󣬳�����ֹ" << endl;
		exit(1);
	}
	if (G->numedge >= MAXEDGE)
	{
		cout << "�������󣬳�����ֹ" << endl;
		exit(1);
	}
	cout << "����������ÿ����������ݣ��ÿո���" << endl;
	for (int i = 1; i <= G->numvex; i++)
	{
		cin >> G->adjlist[i].data;
		G->adjlist[i].firstedge = NULL;
	}
	int u, v;
	Edgetype w;
	cout << "�������������еıߵ���㣬�յ㣬Ȩֵ" << endl;
	for (int i = 1; i <= G->numedge; i++)
	{
		Edge e = (Edge)malloc(sizeof(edgenode));
		if (e == NULL)
		{
			cout << "�ڴ治��" << endl;
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
void traceback(Graph G, int n, int* P)					//��ӡ·��
{
	if (P[n] != -1)
		traceback(G, P[n], P);
	cout << n << '(' << G->adjlist[n].data << ')' << ' ';
}

void Save2Matrix(Graph G, Edgetype * D, int sourse)		//����·������������M��
{
	for (int i = 1; i <= G->numvex; i++)
		M[sourse][i] = D[i];
}

void Print(Graph G, int n, Edgetype * D, int* P)		//��ӡ��Դ��sourse�����ж�������·��������
{
	for (int i = 1; i <= G->numvex; i++)
	{
		cout << "�Ӷ���" << n << '(' << G->adjlist[n].data << ')' << "������" << i << '(' << G->adjlist[i].data << ')' << "����̾�����";
		if (D[i] == INF)
			//if (fabs(D[i] - INF) <= 1e-6)					//����ȨֵΪ�������� 
		{
			cout << "��\t";
			cout << "û�дӶ���" << n << '(' << G->adjlist[n].data << ')' << "������" << i << '(' << G->adjlist[i].data << ')' << "��·��" << endl;
		}
		else
		{
			cout << D[i] << '\t';
			cout << "�Ӷ���" << n << '(' << G->adjlist[n].data << ')' << "������" << i << '(' << G->adjlist[i].data << ')' << "�����·����:";
			traceback(G, i, P);
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
}

void Print_Matrix(Graph G)								//��ӡ������� 
{
	for (int i = 1; i <= G->numvex; i++)
	{
		for (int j = 1; j <= G->numvex; j++)
			if (M[i][j] != INF)
				cout << M[i][j] << ' ';
			else cout << "�� ";
		cout << endl;
	}
}
