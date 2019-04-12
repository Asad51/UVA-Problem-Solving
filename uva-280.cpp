#include <iostream>
#include <cstdio>
#include <cstring>

class GridColoring
{
    int n, cx, cy, check[33][82];
    char grid[33][82], contour;

public:
    GridColoring()
    {
        n = 0;
        for (int i = 0; i < 33; i++)
        {
            for (int j = 0; j < 82; j++)
                check[i][j] = 0;
        }
    }

    int getInput()
    {
        while (gets(grid[n]))
        {
            if (grid[n][0] == '_')
                return 1;
            n++;
        }
        return 0;
    }

    void solveGrid(int x, int y, char marker)
    {
        grid[x][y] = marker;
        if (x > 0 && grid[x - 1][y] == ' ' && !check[x - 1][y])
            solveGrid(x - 1, y, marker);
        if (x < n - 1 && grid[x + 1][y] == ' ' && !check[x + 1][y])
            solveGrid(x + 1, y, marker);
        if (y > 0 && grid[x][y - 1] == ' ' && !check[x][y - 1])
            solveGrid(x, y - 1, marker);
        if (y < strlen(grid[x]) - 1 && grid[x][y + 1] == ' ' && !check[x][y + 1])
            solveGrid(x, y + 1, marker);
    }

    void solve()
    {
        for (int j = 0; j < strlen(grid[0]); j++)
        {
            if (grid[0][j] != ' ')
            {
                contour = grid[0][j];
                ;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < strlen(grid[i]); j++)
            {
                if (!check[i][j] && grid[i][j] != ' ' && grid[i][j] != contour)
                {
                    solveGrid(i, j, grid[i][j]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("%s\n", grid[i]);
        }
        printf("_____________________________\n");
    }
};

int main()
{
    int t = 1;
    while (t)
    {
        GridColoring gc;
        t = gc.getInput();
        if (t)
            gc.solve();
    }
    return 0;
}
