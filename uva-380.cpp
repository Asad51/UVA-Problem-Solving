#include <iostream>
#include <cstdio>

struct Forward
{
    int source;
    int start;
    int end;
    int dest;
};

class CallForwarding
{
    Forward forwards[101];
    int n, time, source, duration, destination, sourceIndex;
    int check[10000];

public:
    CallForwarding()
    {
        n = 0;
    }

    void reset()
    {
        for (int i = 0; i < 10000; i++)
            check[i] = 0;
    }

    void getInput()
    {
        while (scanf("%d", &forwards[n].source) && forwards[n].source)
        {
            scanf("%d %d %d", &forwards[n].start, &duration, &forwards[n].dest);
            forwards[n].end = forwards[n].start + duration;
            n++;
        }
    }

    void solveRequest(int s)
    {
        if (check[s])
        {
            destination = 9999;
            return;
        }
        check[s] = 1;
        for (int i = 0; i < n; i++)
        {
            if (s == forwards[i].source && forwards[i].start <= time && forwards[i].end >= time)
            {
                return solveRequest(forwards[i].dest);
            }
        }
        destination = s;
    }

    void solve()
    {
        while (scanf("%d", &time) && time != 9000)
        {
            scanf("%d", &source);
            reset();
            solveRequest(source);
            printf("AT %04d CALL TO %04d RINGS %04d\n", time, source, destination);
        }
    }
};

int main(int argc, char const *argv[])
{
    //freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    printf("CALL FORWARDING OUTPUT\n");
    for (int i = 1; i <= n; i++)
    {
        CallForwarding cf;
        cf.getInput();
        printf("SYSTEM %d\n", i);
        cf.solve();
    }
    printf("END OF OUTPUT\n");
    return 0;
}
