#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    long long int i,j,a;

    stack < char > st;
    while(getline(cin, s))
    {
        if(s.empty())
        {
            cout<<endl;
            continue;
        }

        for(i=s.size()-1; i>=0; i--)
        {
            st.push(s[i]);
        }

        a = 0;
        while(!st.empty())
        {
            if(isdigit(st.top())==true)
            {
                a = a + (st.top()-48);
                st.pop();
                //cout<<a<<endl;
            }
            else if(st.top()=='b')
            {
                for(j=1; j<=a; j++)
                    cout<<" ";
                st.pop();
                a = 0;
            }
            else if(st.top()=='!'){
                cout<<endl;
                st.pop();
                a = 0;
            }
            else
            {
                for(j=1; j<=a; j++)
                    cout<<st.top();
                st.pop();
                a = 0;
            }
            //st.pop();
        }
        cout<<endl;
    }
    return 0;
}
