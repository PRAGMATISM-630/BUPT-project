#include "struct.h"
#include "Longest.h"
#include "Shortest.h"
#include "Print.h"
int main()
{
	Graph G = CreateGraph();
	cout << "���󶥵����̾�������ֵ��" << endl;
	for (int i = 1; i <= G->numvex; i++)			//��ÿ��������ΪԴ��ִ��һ��dijkstra�㷨	
		Dijkstra(G, i);
	//cout<<"���·�����ȵľ������Ϊ:\n";
	//Print_Matrix(G);
	Find_Max_Shortest_Path(G);
	cout << "���󶥵�����������ֵ��" << endl;
	for (int i = 1; i <= G->numvex; i++)			//��ÿ��������ΪԴ��ִ��һ����ؼ�·�������㷨 
		KeyPath(G, i);
	//cout<<"�·�����ȵľ������Ϊ:\n"; 
	//Print_Matrix(G);
	Find_Max_Longest_Path(G);
	return 0;
}