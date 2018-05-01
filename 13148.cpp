#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    long n;
    while(cin>>n)
    {
        if(n==0)
            break;
        double st = round(pow(n, 1.0/2.0));
        double qb = round(pow(n, 1.0/3.0));
        long ans1 = st*st;
        long ans2 = qb*qb*qb;
        if(ans1==n && ans2==n)
        {
            printf("Special\n");
        }
        else
            printf("Ordinary\n");
    }
    return 0;
}
