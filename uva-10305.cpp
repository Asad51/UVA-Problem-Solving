#include <iostream>
#include <cstdio>

class OrderingTasks
{
    int n, m, x, y;
    int adj[101][101], visited[101], degree[101];

public:
    OrderingTasks(int n, int m)
    {
        this->n = n;
        this->m = m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                adj[i][j] = 0;
            visited[i] = degree[i] = 0;
        }
    }

    void getInput()
    {
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &x, &y);
            adj[x - 1][y - 1] = 1;
            degree[y - 1]++;
        }
    }

    void solve(int t)
    {
        int arr[n], len = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (degree[i] <= 0)
                {
                    if (t)
                        printf(" ");
                    arr[len++] = i;
                    printf("%d", i + 1);
                    visited[i] = 1;
                    t++;
                }
                else
                    cnt++;
            }
        }
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[arr[i]][j] && !visited[j])
                    degree[j]--;
            }
        }
        if (cnt > 0)
            solve(t);
    }
};

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) && (m || n))
    {
        OrderingTasks ot(n, m);
        ot.getInput();
        ot.solve(0);
        printf("\n");
    }
}
