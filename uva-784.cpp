#include <iostream>
#include <cstdio>
#include <cstring>

class MazeExploration
{
    int n, cx, cy;
    char maze[31][82], wall;

public:
    MazeExploration()
    {
        n = 0;
    }

    void getInput()
    {
        while (gets(maze[n]))
        {
            if (maze[n][0] == '_')
                break;
            for (int j = 0; j < strlen(maze[n]); j++)
            {
                if (maze[n][j] != ' ' && maze[n][j] != '*' && maze[n][j] != '-')
                {
                    wall = maze[n][j];
                    ;
                }
                else if (maze[n][j] == '*')
                {
                    cx = n;
                    cy = j;
                }
            }
            n++;
        }
    }

    void solveMaze(int x, int y)
    {
        maze[x][y] = '#';
        if (x > 0 && maze[x - 1][y] == ' ')
            solveMaze(x - 1, y);
        if (x < n - 1 && maze[x + 1][y] == ' ')
            solveMaze(x + 1, y);
        if (y > 0 && maze[x][y - 1] == ' ')
            solveMaze(x, y - 1);
        if (y < strlen(maze[x]) - 1 && maze[x][y + 1] == ' ')
            solveMaze(x, y + 1);
    }

    void solve()
    {
        solveMaze(cx, cy);
        for (int i = 0; i < n; i++)
        {
            printf("%s\n", maze[i]);
        }
        printf("_____\n");
    }
};

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        MazeExploration me;
        me.getInput();
        me.solve();
    }
    return 0;
}
