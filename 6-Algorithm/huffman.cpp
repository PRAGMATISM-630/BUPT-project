/*
	Huffman����:
	�����ԭ�����������ȶ���д�ģ�����oj���е��⿨ʱ�䣬nlogn���㷨�޷�ͨ��������뵽����O(n)��Ͱ������
	��Ŀ�и���ֵΪ�̶�����λС����ͨ��*1000����ת��Ϊ������
	�Ӷ����Բ���Ͱ����������ʱ�临�Ӷ�ΪO(n)
	�㷨ά���������У���һ�����д�ų�ʼͰ�����ĸ��ʶ���
	�ڶ������д�Ž��ϲ���������½��ֵ����֪�ڶ����������Զ������
	ÿ�ֺϲ����ҳ��������ж���Ԫ�صĽ�Сֵ
*/
#include<queue>
#include<cstdio>
#pragma warning(disable:4996)
using std::queue;

const int maxn = 1005;		//С��λ��Ϊ3�����ֻҪ1000��Ͱ����
int bucket[maxn] = { 0 };

int main()
{
	FILE* fp;
	fp = fopen("huffman.in", "r");

	queue<int>q1;		//��ʼ�Ķ���
	queue<int>q2;		//�ϲ���������½�����ö���

	int n;
	double m;
	fscanf(fp,"%d", &n);

	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%lf", &m);
		m += 1e-5;
		int tmp = int(m * 1000);
		bucket[tmp]++;
	}

	for (int i = 0; i <= maxn; i++)
	{
		while (bucket[i]--)
			q1.push(i);
	}

	int  a, b;
	int res = 0;
	while (--n)
	{
		if (!q1.empty() && (q2.empty() || q1.front() < q2.front()))
		{
			a = q1.front();
			q1.pop();
		}
		else if (!q2.empty() && (q1.empty() || q2.front() <= q1.front()))
		{
			a = q2.front();
			q2.pop();
		}
		else break;
		if (!q1.empty() && (q2.empty() || q1.front() < q2.front()))
		{
			b = q1.front();
			q1.pop();
		}
		else if (!q2.empty() && (q1.empty() || q2.front() <= q1.front()))
		{
			b = q2.front();
			q2.pop();
		}
		else break;
		res += a + b;
		q2.push(a + b);
	}

	FILE* fp2;
	fp2 = fopen("huffman.out", "w");
	fprintf(fp2,"%.3lf\n", (double)res/1000);
}
