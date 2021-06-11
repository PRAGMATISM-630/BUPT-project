#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

void merge(int* a, int left, int mid, int right)
{
	int n = right - left + 1;
	int* b = new int[n];
	int i = left, j = mid + 1, k = 0;

	while (i <= mid && j <= right)
	{
		if (a[i] <= a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while (i <= mid)
		b[k++] = a[i++];
	while (j <= right)
		b[k++] = a[j++];

	memcpy(a + left, b, sizeof(int) * n);

	delete[] b;
}


void mergeSort(int* a, int n)
{
	for (int s = 1; s < n; s *= 2)
		for (int i = 0; i + s < n; i += 2 * s)
			if (i + 2 * s - 1 >= n)
				merge(a, i, i + s - 1, n - 1);
			else
				merge(a, i, i + s - 1, i + 2 * s - 1);
}

int main()
{
	fstream fin("mergesort.in", ios::in), fout("mergesort.out", ios::out);
	int n;
	fin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		fin >> a[i];
	}
	mergeSort(a, n);
	for (int i = 0; i < n; i++)
		fout << a[i] << ' ';
	delete[] a;
	return 0;
}