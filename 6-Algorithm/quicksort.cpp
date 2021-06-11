#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>

using namespace std;

#define SOLUTION1		//课本上的解法
//#define SOLUTION2		//另外一种稍有不同的解法

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

#ifdef SOLUTION1
int RamdomizedPartition(int* a, int l, int r)
{
	srand(time(NULL));
	int m = l+rand()%(r-l+1);
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

void quickSort(int* a, int l, int r)
{
	if (l < r)
	{
		int m = RamdomizedPartition(a, l, r);
		quickSort(a, l, m - 1);
		quickSort(a, m + 1, r);
	}
}
#endif

#ifdef SOLUTION2
int median3(int* a, int l, int m, int r)
{
	if (a[l] > a[m])
		swap(a[l], a[m]);
	if (a[l] > a[r])
		swap(a[l], a[r]);
	if (a[m] > a[r])
		swap(a[m], a[r]);
	swap(a[m], a[r - 1]);
	return a[r - 1];
		
}

void quickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) / 2;
	int pivot = median3(a, left, mid, right);
	int i = left, j = right - 1;
	while (i < j)
	{
		while (a[++i] < pivot);
		while (a[--j] > pivot);
		if (i < j)
			swap(a[i], a[j]);
	}
	swap(a[i], a[right - 1]);
	quickSort(a, left, i-1);
	quickSort(a, i + 1, right);
}
#endif


int main()
{
	fstream fin("quicksort.in", ios::in), fout("quicksort.out", ios::out);
	int n;
	fin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		fin >> a[i];
	quickSort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
		fout << a[i] << ' ';
	delete[] a;
	return 0;
}





