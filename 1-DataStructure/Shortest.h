#include "struct.h"
#pragma once
void Dijkstra(Graph G, int n)							//���Դ��n�������������·��
{
	bool S[MAXVEX];										//����Ƿ��Ѿ�ȷ�������·����true��ʾ��ȷ��
	Edgetype D[MAXVEX];									//�洢��ǰ���·������
	int P[MAXVEX];										//�洢��ǰ���ʵ��Ķ����ڵ�ǰ���·���ϵ�ǰ��
	for (int i = 1; i <= G->numvex; i++)
	{
		S[i] = false;
		D[i] = INF;
		P[i] = -1;
	}
	D[n] = 0;
	int tmp = n;										//tmp���ڱ���Դ�㣬�Ա����ָ�
	while (!S[n])
	{
		S[n] = true;
		Edge e = G->adjlist[n].firstedge;
		while (e)										//���µ��ﵱǰ���пɴﶥ������·��
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
		for (int i = 1; i <= G->numvex; i++)			//�ҳ�D[i]�е���Сֵ���浽nowmin�У�����i�浽now��
			if (nowmin > D[i] && S[i] != 1)
			{
				nowmin = D[i];
				now = i;
			}
		n = now;										//n��ΪD[i]��С���Ǹ����㣬�����´�ѭ��
	}
	n = tmp;
	Save2Matrix(G, D, n);								//�����Դ��n�����������������·������
	//Print(G, n, D, P);								//��ӡ��Դ�㿪ʼ�����ж�������·��������
}

void Find_Max_Shortest_Path(Graph G)							//�Ӿ���M���ҵ����·������������������
{
	Edgetype maxl = -INF;										//��maxl�������о����е����ֵ
	int x = 1, y = 1;
	for (int i = 1; i <= G->numvex; i++)						//����������󣬸���maxl
		for (int j = 1; j <= G->numvex; j++)
			if (M[i][j] != INF && maxl < M[i][j])
				//if (!(fabs(M[i][j] - INF) <= 1e-6) && maxl < M[i][j])		//�����Ȩֵ�Ǹ������� 
			{
				maxl = M[i][j];
				x = i; y = j;
			}
	cout << "ͼ�о�����Զ����������Ϊ" << x << '(' << G->adjlist[x].data << ')' << "��";
	cout << y << '(' << G->adjlist[y].data << ')' << ",·������Ϊ" << maxl << endl << endl;
}