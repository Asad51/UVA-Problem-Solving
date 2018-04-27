#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s[1000],ss[100];
    int i,j,c;
    vector < string > vs;
    while(gets(s))
    {
        j = 0;
        for(i=0; s[i]; i++)
        {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
            {
                ss[j] = s[i];
                j++;
            }
            else
            {
                if(j==0)
                    continue;
                ss[j] = '\0';
                vs.push_back(ss);
                j=0;
            }
        }
        cout<<vs.size()<<endl;
        vs.clear();
    }
    return 0;
}
