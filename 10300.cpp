#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
    lli t,n,a,b,c,ans,i,j;
    while(cin>>t)
    {
        for(i=1; i<=t; i++)
        {
            ans = 0;
            cin>>n;
            for(j=1; j<=n; j++)
            {
                cin>>a>>b>>c;
                ans = ans + a*c;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
