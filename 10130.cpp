#include <stdio.h>

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int knap_sack(int p[], int w[], int n, int c)
{
	int kn[n + 1][c + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= c; j++)
		{
			if (!i || !j)
				kn[i][j] = 0;
			else if (w[i - 1] <= j)
			{
				kn[i][j] = max(p[i - 1] + kn[i - 1][j - w[i - 1]], kn[i - 1][j]);
			}
			else
			{
				kn[i][j] = kn[i - 1][j];
			}
		}
	}
	return kn[n][c];
}

int main()
{
	int t, n, g;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		int p[1001], w[1001];
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &p[i], &w[i]);
		}

		scanf("%d", &g);
		int tp = 0, c;
		for (int i = 0; i < g; i++)
		{
			scanf("%d", &c);
			tp += knap_sack(p, w, n, c);
		}
		printf("%d\n", tp);
	}

	return 0;
}
