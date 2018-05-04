#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

bool isPrime(lli n){
    if(n==2)
        return true;
    if(n%2==0 || n==1)
        return false;
    for(lli i=3; i<=sqrt(n); i += 2){
        if(n%i==0)
            return false;
    }
    return true;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    lli n, p, q, i;
    cin>>n;
    while(n--)
    {
        cin>>p;
        q = pow(2,p) - 1;
        if(isPrime(p) && isPrime(q))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
