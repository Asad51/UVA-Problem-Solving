#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int m,n;
    while(scanf("%lld %lld",&m,&n)!=EOF)
    {
        if(m>n)
            cout<<m-n<<endl;
        else
            cout<<n-m<<endl;
    }

    return 0;
}
