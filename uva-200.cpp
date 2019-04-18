#include <cstring>
#include <cstdio>

int graph[28][28];
int mark[28], inDegree[28];

void solve()
{
    while (true)
    {
        int cnt = 0;
        for (int i = 0; i < 26; i++)
            if (mark[i] && inDegree[i] > 0)
                cnt++;
        for (int i = 0; i < 26; i++)
        {
            if (mark[i] && !inDegree[i])
            {
                printf("%c", 'A' + i);
                mark[i] = 0;
                for (int j = 0; j < 26; j++)
                {
                    if (graph[i][j] && mark[j] && inDegree[j] > 0)
                        inDegree[j]--;
                }
            }
        }
        if (!cnt)
            break;
    }
    printf("\n");
}

void reset()
{
    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 28; j++)
            graph[i][j] = 0;
        inDegree[i] = mark[i] = 0;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    char str1[25], str2[25];
    while (scanf("%s", str1) != EOF)
    {
        reset();
        for(int i = 0; str1[i] != '\0'; i++){
            int u = str1[i] - 'A';
            mark[u] = 1;
        }
        while (scanf("%s", str2) && str2[0] != '#')
        {
            for(int i = 0; str2[i] != '\0'; i++){
                int u = str2[i] - 'A';
                mark[u] = 1;
            }
            for (int j = 0; j < str1[j] != '\0' && str2[j] != '\0'; j++)
            {
                if (str1[j] != str2[j])
                {
                    int u = str1[j] - 'A';
                    int v = str2[j] - 'A';
                    if(!graph[u][v])
                        inDegree[v]++;
                    graph[u][v] = 1;
                    break;
                }
            }
            int j = 0;
            for (; j < str2[j] != '\0'; j++)
                str1[j] = str2[j];
            str1[j] = '\0';
        }
        solve();
    }

    return 0;
}
