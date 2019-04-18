#include <cstdio>
typedef long long int lli;
int st;

class GroupSum
{
    int n, q, m, d;
    lli nums[201];
    int dp[205][15][25];

public:
    GroupSum(int n, int q)
    {
        this->n = n;
        this->q = q;
    }

    void reset()
    {
        for (int i = 0; i <= 201; i++)
            for (int j = 0; j <= 10; j++)
                for (int k = 0; k <= 20; k++)
                    dp[i][j][k] = -1;
    }

    void getInput()
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%Ld", &nums[i]);
        }
    }

    int knapsack(int i, int cnt, int sum)
    {
        if (dp[i][cnt][sum] != -1)
            return dp[i][cnt][sum];

        if (cnt == m)
        {
            if (sum == 0)
                return dp[i][cnt][sum] = 1;
            return dp[i][cnt][sum] = 0;
        }

        if (i == n)
            return dp[i][cnt][sum] = 0;

        int left = knapsack(i + 1, cnt, sum);

        lli tmp = sum + nums[i];
        tmp = ((tmp % d) + d) % d;
        int right = knapsack(i + 1, cnt + 1, tmp);

        return dp[i][cnt][sum] = left + right;
    }

    void solve()
    {
        for (int i = 0; i < q; i++)
        {
            reset();
            scanf("%d %d", &d, &m);
            int cnt = knapsack(0, 0, 0);
            printf("QUERY %d: %d\n", i + 1, cnt);
        }
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);
    int n, q;
    st = 1;
    while (scanf("%d %d", &n, &q))
    {
        if (!n && !q)
            break;
        GroupSum gs(n, q);
        gs.getInput();
        printf("SET %d:\n", st++);
        gs.solve();
    }
    return 0;
}
