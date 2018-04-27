#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli f(lli n)
{
    lli c = 0;
    while(n>=1)
    {
        if(n==1)
        {
            c++;
            break;
        }
        else if(n%2==0)
        {
            n=n/2;
            c++;
        }
        else{
            n=3*n+1;
            c++;
        }
    }
    return c;
}
int main()
{
    lli i,j,m,n,max_l;
    while(cin>>m>>n)
    {
        i = m;
        j = n;
        if(i>j)
            swap(i,j);
        max_l = 0;
        for(lli p=i; p<=j; p++)
        {
            lli len;
            len = f(p);
            if(len>max_l)
            {
                max_l = len;
            }
        }
        cout<<m<<" "<<n<<" "<<max_l<<endl;
    }

    return 0;
}
