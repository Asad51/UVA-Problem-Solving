#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,a,b,h,i,c1,c2;
    cin>>n;
    while(n>0)
    {
        h=0;
        c1=0;
        c2=0;
        cin>>m;
        a=m;
        while(a!=0)
        {
            if(a%2==1)
                c1++;
            a=a/2;
        }

        i=0;
        while(m!=0)
        {
            b=m%10;
            h=h+b*pow(16,i);
            m=m/10;
            i++;
        }
        while(h!=0)
        {
            if(h%2==1)
                c2++;
            h=h/2;
        }
        cout<<c1<<" "<<c2<<endl;

        n--;
    }

    return 0;
}
