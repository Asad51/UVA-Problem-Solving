#include <iostream>
#include <cstdio>

class Networks
{
    int n;
    int path[101][101];

public:
    Networks(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                path[i][j] = 0;
        }
    }

    void getInput()
    {
        int x, y;
        char ch;
        while (1 == scanf("%d", &x))
        {
            if (0 == x)
                break;
            while (2 == scanf("%d%c", &y, &ch))
            {
                path[x - 1][y - 1] = 1;
                path[y - 1][x - 1] = 1;
                if (ch == '\n')
                    break;
            }
        }
    }

    void reset(int visited[])
    {
        for (int i = 0; i < n; i++)
        {
            visited[i] = 0;
        }
    }

    void dfs(int u, int visited[])
    {
        visited[u] = 1;
        for (int i = 0; i < n; i++)
            if (path[u][i] == 1 && visited[i] != 1)
                dfs(i, visited);
    }

    int getConnectedComponents(int u)
    {
        for (int i = 0; i < n; i++)
        {
            if (path[u][i] == 1)
            {
                path[u][i] = -1;
                path[i][u] = -1;
            }
        }
        int cnt = 0;
        int visited[n];
        reset(visited);
        for (int i = 0; i < n; i++)
        {
            if (i != u && !visited[i])
            {
                dfs(i, visited);
                cnt++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (path[u][i] == -1)
            {
                path[u][i] = 1;
                path[i][u] = 1;
            }
        }
        return cnt;
    }

    void solve()
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int p = getConnectedComponents(i);
            if (p > 1)
            {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
};

int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        Networks networks(n);
        networks.getInput();
        networks.solve();
    }
}