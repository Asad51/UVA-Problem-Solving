#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int i,j,m = INT_MAX,n = 0;
    vector<string>vs;
    while(getline(cin,s))
    {
        vs.push_back(s);
        n=max(n,(int)s.size());
    }
    for(i=0; i<vs.size(); i++)
    {
        for(j=vs[i].size(); j<n; j++)
            vs[i] += " ";
    }

    for(i=0; i<n; i++)
    {
        for(j=vs.size()-1; j>=0; j--)
        {
            cout<<vs[j][i];
        }
        cout<<endl;
    }

    return 0;
}
