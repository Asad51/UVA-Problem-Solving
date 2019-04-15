#include <iostream>
#include <cstdio>

class Equidivision
{
    int n;
    int grid[101][101];
    int check[101][101];
    int s[101];

public:
    Equidivision(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                grid[i][j] = n;
                check[i][j] = 0;
            }
            s[i] = 0;
        }
    }

    void getInput()
    {
        int x, y;
        char ch;
        for (int i = 1; i < n; i++)
            while (1)
            {
                scanf("%d %d%c", &x, &y, &ch);
                grid[x - 1][y - 1] = i;
                if (ch == '\n')
                    break;
            }
    }

    void solveGrid(int x, int y, int p)
    {
        check[x][y] = p;
        s[p - 1]++;
        if (x > 0 && !check[x - 1][y] && grid[x - 1][y] == p)
            solveGrid(x - 1, y, p);
        if (x < n - 1 && !check[x + 1][y] && grid[x + 1][y] == p)
            solveGrid(x + 1, y, p);
        if (y > 0 && !check[x][y - 1] && grid[x][y - 1] == p)
            solveGrid(x, y - 1, p);
        if (y < n - 1 && !check[x][y + 1] && grid[x][y + 1] == p)
            solveGrid(x, y + 1, p);
    }

    void solve()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!check[i][j] && !s[grid[i][j] - 1])
                    solveGrid(i, j, grid[i][j]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] < n)
            {
                printf("wrong\n");
                return;
            }
        }
        printf("good\n");
    }
};

int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        Equidivision eq(n);
        eq.getInput();
        eq.solve();
    }
}
