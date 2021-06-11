#include<algorithm>
#include<cstdio>
#pragma warning(disable:4996)

const int maxn = 5000;
int c[maxn];
int w[maxn];
int dp[maxn][maxn];			//dp[i][j]表示将前i件物品放进容量为j的背包可达的最大价值

int main()
{
	FILE* fp;
	fp = fopen("bag.in", "r");
	int v, n;
	fscanf(fp, "%d %d", &v, &n);
	for (int i = 1; i <= n; i++)
		fscanf(fp, "%d %d", &c[i], &w[i]);

	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = 0;
	}
	for (int j = 1; j <= v; j++)
	{
		dp[n + 1][j] = 0;
	}
	for (int i = n; i >= 1; i--)
		for (int j = 1; j <= v; j++)
		{
			if (c[i] <= j)
				dp[i][j] = std::max(dp[i + 1][j], dp[i + 1][j - c[i]] + w[i]);
			else
				dp[i][j] = dp[i + 1][j];
		}

	FILE* fp2;
	fp2 = fopen("bag.out", "w");
	fprintf(fp2, "%d\n", dp[1][v]);
}
