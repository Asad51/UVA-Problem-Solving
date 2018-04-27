#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    long long int i,j;
    while(cin>>s)
    {
        for(j=0; j<s.size(); j++)
        {
            s[j] = s[j] - 7;
        }

        cout<<s<<endl;
    }

    return 0;
}
