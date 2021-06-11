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
void Save2Matrix(Graph G, Edgetype * D, int sourse);	//����·������������M��
void Print_Matrix(Graph G);								//��ӡ������� 

void Dijkstra(Graph G, int n);							//���Դ��n�������������·��
void Find_Max_Shortest_Path(Graph G);					//�Ӿ���M���ҵ����·������������������

void KeyPath(Graph G, int sourse);						//���Դ��n���������Ĺؼ�·�� (�·���� 
void Find_Max_Longest_Path(Graph G);					//�Ӿ���M���ҵ��·������������������

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
	if(G->numvex>=MAXVEX)
	{
		cout<<"���������󣬳�����ֹ"<<endl;
		exit(1);
	}
	if(G->numedge>=MAXEDGE)
	{
		cout<<"�������󣬳�����ֹ"<<endl;
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
	cout << y << '(' << G->adjlist[y].data << ')' << ",·������Ϊ" << maxl << endl<<endl;
}

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
		now = Q.front();								//�¸�ѭ�����µ�ǰ���׶�������к�� 
	}
	Save2Matrix(G,D,sourse);							//�浽����M�� 
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
	cout << y << '(' << G->adjlist[y].data << ')' << ",·������Ϊ" << maxl << endl<<endl;
}

int main()
{
	Graph G = CreateGraph();
	cout<<"���󶥵����̾�������ֵ��"<<endl; 
	for (int i=1;i<=G->numvex;i++)			//��ÿ��������ΪԴ��ִ��һ��dijkstra�㷨	
		Dijkstra(G, i);
	//cout<<"���·�����ȵľ������Ϊ:\n";
	//Print_Matrix(G);
	Find_Max_Shortest_Path(G);
	cout<<"���󶥵�����������ֵ��"<<endl; 
	for (int i=1;i<=G->numvex;i++)			//��ÿ��������ΪԴ��ִ��һ����ؼ�·�������㷨 
		KeyPath(G, i);
	//cout<<"�·�����ȵľ������Ϊ:\n"; 
	//Print_Matrix(G);
	Find_Max_Longest_Path(G);
	return 0;
}

/*
��������1��
5 7
1 2 3 4 5
1 2 10
1 4 30
1 5 100
2 3 50
3 5 10
4 3 20
4 5 60
��������2��
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
��������3��
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
��������4��
2 1
1 2
2 1 3 
*/
