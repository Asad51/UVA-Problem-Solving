#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,m,n,i,j,k,l;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        for(int p=1; p<=n; p++)
        {
            for(k=1; k<=m; k++)
            {
                for(l=1; l<=k; l++)
                    cout<<k;

                cout<<endl;
            }
            for(k=m-1; k>=1; k--)
            {
                for(l=1; l<=k; l++)
                    cout<<k;

                cout<<endl;
            }
            if (p !=n )
                cout<<endl;
        }
        if (t)
            cout<<endl;
    }

    return 0;
}
