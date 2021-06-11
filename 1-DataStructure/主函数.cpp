#include "struct.h"
#include "Longest.h"
#include "Shortest.h"
#include "Print.h"
int main()
{
	Graph G = CreateGraph();
	cout << "若求顶点间最短距离的最大值：" << endl;
	for (int i = 1; i <= G->numvex; i++)			//将每个顶点作为源点执行一次dijkstra算法	
		Dijkstra(G, i);
	//cout<<"最短路径长度的距离矩阵为:\n";
	//Print_Matrix(G);
	Find_Max_Shortest_Path(G);
	cout << "若求顶点间最长距离的最大值：" << endl;
	for (int i = 1; i <= G->numvex; i++)			//将每个顶点作为源点执行一次求关键路径长度算法 
		KeyPath(G, i);
	//cout<<"最长路径长度的距离矩阵为:\n"; 
	//Print_Matrix(G);
	Find_Max_Longest_Path(G);
	return 0;
}