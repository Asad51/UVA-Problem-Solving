#include <iostream>
#include <cstdio>
#include <cstring>

int n, m, cx, cy, check[51][51];
char d, ins[101];

bool edgeCheck()
{
    if (cx < 0 || cx > n)
        return false;
    if (cy < 0 || cy > m)
        return false;
    return true;
}

int changeLocation()
{
    int tx = cx, ty = cy;
    if (d == 'N')
        cy++;
    else if (d == 'S')
        cy--;
    else if (d == 'E')
        cx++;
    else
        cx--;
    if (check[cy][cx])
        return 0;
    return 1;
}

void changeDirection(char ch)
{
    if (d == 'N')
    {
        if (ch == 'L')
            d = 'W';
        else
            d = 'E';
    }
    else if (d == 'S')
    {
        if (ch == 'L')
            d = 'E';
        else
            d = 'W';
    }
    else if (d == 'W')
    {
        if (ch == 'L')
            d = 'S';
        else
            d = 'N';
    }
    else
    {
        if (ch == 'L')
            d = 'N';
        else
            d = 'S';
    }
}

void solve()
{
    bool isLost = false;
    for (int i = 0; i < strlen(ins); i++)
    {
        if (ins[i] == 'F')
        {
            int px = cx, py = cy;
            if (!changeLocation())
            {
                cx = px;
                cy = py;
            }
            else if (!edgeCheck())
            {
                printf("%d %d %c LOST\n", px, py, d);
                ins[i] = 'O';
                isLost = true;
                check[cy][cx] = 1;
                break;
            }
        }
        else
            changeDirection(ins[i]);
    }
    if (!isLost)
        printf("%d %d %c\n", cx, cy, d);
}

int main()
{
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
            check[i][j] = 0;
    }
    scanf("%d %d", &n, &m);
    while (scanf("%d %d %c", &cx, &cy, &d) != EOF)
    {
        scanf("%s", ins);
        solve();
    }
    return 0;
}
