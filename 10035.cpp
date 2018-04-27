#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long int m,n,a,b,c,Cin,Cout;
    while(cin>>m>>n)
    {
        Cin = 0;
        c = 0;
        if(m==0 && n==0)
        {
            return 0;
        }
        while(m!=0 || n!=0)
        {
            a = m%10;
            b = n%10;
            if(a+b+Cin>9)
            {
                c++;
                Cout = 1;
            }
            else
                Cout = 0;

            m=m/10;
            n=n/10;
            Cin = Cout;
        }
        if(c==0)
            cout<<"No carry operation."<<endl;
        else if(c==1)
            cout<<c<<" carry operation."<<endl;
        else
            cout<<c<<" carry operations."<<endl;
    }
    return 0;
}
