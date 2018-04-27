#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,sum,c;
    while(cin>>n)
    {
        sum = 0;
        if(n==0)
        {
            break;
        }
        int a[n];
        int maxi = 0;
        string s[n];
        getchar();
        for(int i = 0; i<n; i++)
        {
            getline(cin, s[i]);
            a[i] = count(s[i].begin(),s[i].end(),'X');
            maxi = max(maxi,a[i]);
        }
        for(int i = 0; i<n; i++)
        {
            sum = sum + maxi-a[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
