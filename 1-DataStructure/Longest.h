#include "struct.h"
#pragma once

void KeyPath(Graph G, int sourse)						//���Դ��sourse���������Ĺؼ�·�� (�·����
{
	Edgetype D[MAXVEX];									//�洢��ǰ�·���ĳ��� 
	queue<int>Q;										//����Q���� 
	for (int i = 1; i <= G->numvex; i++)
		D[i] = INF;
	int now = sourse;
	D[now] = 0;
	Q.push(now);
	while (!Q.empty())									//��������������г�����ֱ������Ϊ�� 
	{
		Q.pop();
		Edge e = G->adjlist[now].firstedge;
		while (e)										//�������к�̶�����·�����ȣ�ʹ֮�����ܴ� 
		{
			Q.push(e->adjvex);
			if (D[e->adjvex] == INF)					//ԭ��û��·������������ 
				D[e->adjvex] = D[now] + e->weight;
			if (D[e->adjvex] < D[now] + e->weight)
				D[e->adjvex] = D[now] + e->weight;
			e = e->nextedge;
		}
		if(!Q.empty())
		now = Q.front();								//�¸�ѭ�����µ�ǰ���׶�������к�� 
	}
	Save2Matrix(G, D, sourse);							//�浽����M�� 
}

void Find_Max_Longest_Path(Graph G)						//�Ӿ���M���ҵ��·������������������
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
	cout << "ͼ�о�����Զ����������Ϊ" << x << '(' << G->adjlist[x].data << ')' << "��";
	cout << y << '(' << G->adjlist[y].data << ')' << ",·������Ϊ" << maxl << endl << endl;
}