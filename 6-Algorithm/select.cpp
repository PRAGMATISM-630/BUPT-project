#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;
#pragma warning(disable:4996)

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int RamdomizedPartition(int* a, int l, int r)
{
	srand(time(NULL));
	int m = l + rand() % (r - l + 1);
	int pivot = a[m];
	swap(a[l], a[m]);
	int i = l, j = r + 1;

	int temp = a[l];
	while (i < j)
	{
		while (a[++i] < pivot);
		while (a[--j] > pivot);
		if (i < j)
			swap(a[i], a[j]);
		else
			break;
	}
	a[l] = a[j];
	a[j] = temp;
	return j;
}

int select(int* a, int p, int r, int k)		//找第k小的数
{
	/*
	if (p == r)
		return a[p];
	int i = RamdomizedPartition(a, p, r);
	int j = i - p + 1;		//j表示基准在这个区间内时第几小的
	//j=4
	if (k+1 == j)
		return a[p+k];
	else if (k+1<j)
		return select(a, p, i-1, k);		
	else
		return select(a, i + 1, r, k - j);
		*/
	if (r-p < 75) 
	{
			return a[p + k];
	}
	for (int i = 0; i <= (r - p - 4) / 5; i++) 
	{
		int x = select(a, p, p + (r - p - 4) / 5, (r - p - 4) / 10);
		int tp = RamdomizedPartition(a, p, r), j = tp - p + 1;
		if (k+1 <= j)
			return select(a, p, tp, k);
		else
			return select(a, tp + 1, r, k - j);
	}
	
}

int main()
{
	//fstream fin("select.in", ios::in), fout("select.out", ios::out);
	int n, k;
	scanf("%d%d", &n, &k);
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	cout<<select(a, 0, n - 1, k);
	delete[] a;
	return 0;
}
