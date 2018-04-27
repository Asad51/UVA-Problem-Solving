
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,r,i,j,d,sum,h,mini;
    vector<int>v;
    cin>>t;
    while(t--)
    {
        mini = INT_MAX;
        cin>>r;
        for(i=0; i<r; i++)
        {
            cin>>d;
            v.push_back(d);
        }
        for(i=0; i<r; i++)
        {
            sum = 0;
            h = v[i];
            for(j=0; j<r; j++)
            {
                sum = sum + abs(h-v[j]);
            }
            if(sum<mini)
                mini = sum;
        }
        cout<<mini<<endl;
        v.clear();
    }
    return 0;
}
