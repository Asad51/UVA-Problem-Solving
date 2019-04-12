#include <iostream>
#include <cstdio>

typedef long long int lli;

class Y2K
{
    lli s, d, surplus;
    lli v[13];

public:
    Y2K(lli s, lli d)
    {
        this->s = s;
        this->d = d;
        surplus = -100000000;
        for (int i = 0; i < 12; i++)
            v[i] = 0;
    }

    void solve(int i, int sum)
    {
        if (i >= 12 && sum < 0)
        {
            lli tmp = 0;
            for (int j = 0; j < 12; j++)
                tmp += v[j];
            if (tmp > surplus)
            {
                surplus = tmp;
            }
            return;
        }

        if (i >= 5)
        {
            if (sum > 0)
                return;
            sum -= v[i - 5];
        }

        v[i] = s;
        solve(i + 1, sum + s);
        v[i] = -d;
        solve(i + 1, sum - d);
    }

    void print()
    {
        if (surplus >= 0)
            printf("%Ld\n", surplus);
        else
            printf("Deficit\n", surplus);
    }
};

int main()
{
    lli s, d;
    while (scanf("%Ld %Ld", &s, &d) != EOF)
    {
        Y2K y2k(s, d);
        y2k.solve(0, 0);
        y2k.print();
    }
    return 0;
}