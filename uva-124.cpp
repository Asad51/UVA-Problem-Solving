#include <cstdio>

int path[28][28], visited[28], mark[28];
int n, isFirst;
char output[28];

void init()
{
    n = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
            path[i][j] = 0;
        mark[i] = visited[i] = 0;
    }
}

void dfs(int i)
{
    if (i >= n)
    {
        output[i] = '\0';
        printf("%s\n", output);
        return;
    }
    for (int j = 0; j < 26; j++)
    {
        if (mark[j] && !visited[j])
        {
            for (int k = 0; k < 26; k++)
                if (path[j][k] && visited[k])
                    return;
            output[i] = j + 'a';
            visited[j] = 1;
            dfs(i + 1);
            visited[j] = 0;
        }
    }
}

void solve()
{
    if (isFirst)
        isFirst = 0;
    else
        printf("\n");
    dfs(0);
}

int main()
{
    //freopen("int.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    char var, ch;
    isFirst = 1;
    while (scanf("%c%c", &var, &ch) != EOF)
    {
        init();
        mark[var - 'a'] = 1;
        n++;
        while (ch != '\n')
        {
            scanf("%c%c", &var, &ch);
            mark[var - 'a'] = 1;
            n++;
        }
        char a, b, c;
        scanf("%c %c%c", &a, &b, &c);
        path[a - 'a'][b - 'a'] = 1;
        while (c != '\n')
        {
            scanf("%c %c%c", &a, &b, &c);
            path[a - 'a'][b - 'a'] = 1;
        }
        solve();
    }
    return 0;
}
