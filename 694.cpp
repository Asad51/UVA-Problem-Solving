#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
    lli a,l,i,j,aa,ll;
    lli c = 1;
    while(cin>>a>>l)
    {
        if(a<0 && l<0)
            break;
        aa = a;
        ll = l;
        i=1;
        while(a!=1)
        {

            if(a%2==0)
            {
                a = a/2;
            }
            else
            {
                a = 3*a + 1;
            }
            if(a>l)
                break;
            i++;
        }
        cout<<"Case "<<c<<": A = "<<aa<<", limit = "<<ll<<", number of terms = "<<i<<endl;
        c++;
    }
    return 0;
}
