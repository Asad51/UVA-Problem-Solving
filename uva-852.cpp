#include <iostream>
#include <cstdio>

char board[10][10];
int check[10][10];
bool bFound, wFound;

void checkOpposite(int x, int y)
{
    if (bFound && wFound)
        return;
    check[x][y] = 1;
    if (x > 0)
    {
        if (board[x - 1][y] == 'O')
            wFound = true;
        else if (board[x - 1][y] == 'X')
            bFound = true;
        else if (board[x - 1][y] == '.' && !check[x - 1][y])
            checkOpposite(x - 1, y);
    }
    if (x < 8)
    {
        if (board[x + 1][y] == 'O')
            wFound = true;
        else if (board[x + 1][y] == 'X')
            bFound = true;
        else if (board[x + 1][y] == '.' && !check[x + 1][y])
            checkOpposite(x + 1, y);
    }
    if (y > 0)
    {
        if (board[x][y - 1] == 'O')
            wFound = true;
        else if (board[x][y - 1] == 'X')
            bFound = true;
        else if (board[x][y - 1] == '.' && !check[x][y - 1])
            checkOpposite(x, y - 1);
    }
    if (y < 8)
    {
        if (board[x][y + 1] == 'O')
            wFound = true;
        else if (board[x][y + 1] == 'X')
            bFound = true;
        else if (board[x][y + 1] == '.' && !check[x][y + 1])
            checkOpposite(x, y + 1);
    }
}

void reset()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            check[i][j] = 0;
    }
}

void solve(int x, int y, char ch)
{
    check[x][y] = 1;
    board[x][y] = ch;
    if (x > 0 && !check[x - 1][y] && (board[x - 1][y] == ch || board[x - 1][y] == '.'))
        solve(x - 1, y, ch);
    if (x < 8 && !check[x + 1][y] && (board[x + 1][y] == ch || board[x + 1][y] == '.'))
        solve(x + 1, y, ch);
    if (y > 0 && !check[x][y - 1] && (board[x][y - 1] == ch || board[x][y - 1] == '.'))
        solve(x, y - 1, ch);
    if (y < 8 && !check[x][y + 1] && (board[x][y + 1] == ch || board[x][y + 1] == '.'))
        solve(x, y + 1, ch);
}

int main(int argc, char const *argv[])
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        for (int i = 0; i < 9; i++)
            gets(board[i]);
        reset();
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.' && !check[i][j])
                {
                    bFound = wFound = false;
                    checkOpposite(i, j);
                    if (bFound && wFound)
                    {
                        reset();
                        solve(i, j, '#');
                    }
                }
            }
        }
        reset();
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (!check[i][j] && (board[i][j] == 'O' || board[i][j] == 'X'))
                    solve(i, j, board[i][j]);
            }
        }
        int bCount = 0, wCount = 0;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == 'O')
                    wCount++;
                else if (board[i][j] == 'X')
                    bCount++;
            }
        }
        printf("Black %d White %d\n", bCount, wCount);
    }
    return 0;
}
