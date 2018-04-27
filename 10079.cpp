#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,i,j,o,sum;
    while(cin>>n)
    {
        if(n<0)
            return 0;
        sum = 0;
        for(i=0; i<=n; i++)
        {
            if(i==0)
                sum = sum + 1;
            else
                sum = sum + i;
        }
        cout<<sum<<endl;
    }

    return 0;
}
