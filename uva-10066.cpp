#include <cstdio>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main(int argc, char const *argv[])
{
    int n, m;
    int st = 0;
    while (scanf("%d %d", &n, &m))
    {
        if (!m && !n)
            break;
        int arr1[n], arr2[m];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr1[i]);
        for (int i = 0; i < m; i++)
            scanf("%d", &arr2[i]);

        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (!i || !j)
                    dp[i][j] = 0;
                else if (arr1[i - 1] != arr2[j - 1])
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                else
                    dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }

        printf("Twin Towers #%d\n", ++st);
        printf("Number of Tiles : %d\n", dp[n][m]);
        printf("\n");
    }
    return 0;
}
