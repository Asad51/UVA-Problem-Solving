#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,j;

    while(cin>>n)
    {
        getchar();
        string str[n];
        string s[n];
        stack<char> myStack;

        for(j=0; j<n; j++)
        {
            getline(cin,str[j]);
            for(i=0; i<str[j].size(); i++)
            {
                if(!myStack.empty() && ((myStack.top()=='(' && str[j][i]==')') || ((myStack.top()=='[' && str[j][i]==']'))))
                    myStack.pop();
                else
                    myStack.push(str[j][i]);
            }

            if(myStack.empty())
                s[j] = "Yes";
            else
                s[j] = "No";

            while(!myStack.empty())
                myStack.pop();

        }
        for(i=0; i<n; i++)
        cout<<s[i]<<endl;
    }
    return 0;
}

