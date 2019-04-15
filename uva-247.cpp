#include <iostream>
#include <cstdio>
#include <cstring>

class CallingCircle
{
    int n, m, len;
    int path[26][26];
    char name[26][26];
    int visited[26];

public:
    CallingCircle(int n, int m)
    {
        this->n = n;
        this->m = m;
        int i, j;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    path[i][j] = 1;
                else
                    path[i][j] = 0;
                visited[i] = 0;
            }
    }

    int stringCompare(char st1[], char st2[])
    {
        int i;
        for (i = 0; st1[i] && st2[i]; i++)
        {
            if (st1[i] != st2[i])
                return 0;
        }
        if (st1[i] != st2[i])
            return 0;
        return 1;
    }

    int searchString(char st[])
    {
        for (int i = 0; i < len; i++)
            if (stringCompare(st, name[i]))
                return i;
        return -1;
    }

    void stringCopy(char dest[], char src[])
    {
        int i;
        for (i = 0; src[i]; i++)
            dest[i] = src[i];
        dest[i] = '\0';
    }

    void getInput()
    {
        len = 0;
        int x, y;
        char name1[26], name2[26];
        for (int i = 0; i < m; i++)
        {
            scanf("%s %s", name1, name2);
            x = searchString(name1);
            if (-1 == x)
            {
                stringCopy(name[len], name1);
                x = len;
                len++;
            }
            y = searchString(name2);
            if (-1 == y)
            {
                stringCopy(name[len], name2);
                y = len;
                len++;
            }
            path[x][y] = 1;
        }
    }

    void findAllPath()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (path[j][i] && path[i][k])
                    {
                        path[j][k] = 1;
                    }
                }
            }
        }
    }

    void printCircle(int cs)
    {
        int i, j;
        if (cs > 1)
            printf("\n");
        printf("Calling circles for data set %d:\n", cs++);
        for (i = 0; i < n; i++)
            if (0 == visited[i])
            {
                printf("%s", name[i]);
                visited[i] = 1;
                for (j = 0; j < n; j++)
                    if (0 == visited[j] && path[i][j] && path[j][i])
                    {
                        printf(", %s", name[j]);
                        visited[j] = 1;
                    }
                printf("\n");
            }
    }
};

int main()
{
    int n, m, cs = 0;
    while (scanf("%d %d", &n, &m) && (m || n))
    {
        CallingCircle cc(n, m);
        cc.getInput();
        cc.findAllPath();
        cc.printCircle(++cs);
    }
    return 0;
}
