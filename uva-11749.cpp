#include <cstdio>
#include <climits>
#define NEG_INF -2147483648

typedef long long int lli;

template <class T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

class Province
{
    int n, m, u, v, cnt, maxCnt;
    lli maxPPA, w;
    lli path[501][501];
    int visited[501];

public:
    Province(int n, int m)
    {
        this->n = n;
        this->m = m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                path[i][j] = NEG_INF;
            visited[i] = 0;
        }
        maxPPA = NEG_INF;
        maxCnt = -1;
    }

    void getInput()
    {
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %Ld", &u, &v, &w);
            if (w > path[u - 1][v - 1])
            {
                path[u - 1][v - 1] = path[v - 1][u - 1] = w;
            }
            maxPPA = max(maxPPA, w);
        }
    }

    void dfs(int u)
    {
        visited[u] = 1;
        cnt++;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && path[u][i] == maxPPA)
                dfs(i);
        }
    }

    void solve()
    {
        for (int i = 0; i < n; i++)
        {
            cnt = 0;
            if (!visited[i])
            {
                dfs(i);
                maxCnt = max(cnt, maxCnt);
            }
        }
        printf("%d\n", maxCnt);
    }
};

int main(int argc, char const *argv[])
{
    int n, m;
    while (scanf("%d %d", &n, &m))
    {
        if (!m && !n)
            break;
        Province p(n, m);
        p.getInput();
        p.solve();
    }
    return 0;
}
