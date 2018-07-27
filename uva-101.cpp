#include <bits/stdc++.h>
using namespace std;

int block[25];

stack<int> s[25], tmp;

void moveOnto(int a, int b)
{
    while(s[block[a]].top() != a)
    {
        int t = s[block[a]].top();
        s[t].push(t);
        block[t] = t;
        s[block[a]].pop();
    }

    while(s[block[b]].top() != b)
    {
        int t = s[block[b]].top();
        s[t].push(t);
        block[t] = t;
        s[block[b]].pop();
    }

    s[block[b]].pop();
    block[b] = b;
    s[b].push(b);

    s[b].push(s[block[a]].top());
    s[block[a]].pop();
    block[a] = b;
}

void moveOver(int a, int b)
{
    while(s[block[a]].top() != a)
    {
        int t = s[block[a]].top();
        s[t].push(t);
        block[t] = t;
        s[block[a]].pop();
    }

    s[block[b]].push(s[block[a]].top());
    s[block[a]].pop();
    block[a] = block[b];
}

void pileOnto(int a, int b)
{
    while(s[block[b]].top() != b)
    {
        int t = s[block[b]].top();
        s[t].push(t);
        block[t] = t;
        s[block[b]].pop();
    }

    s[block[b]].pop();
    block[b] = b;
    s[b].push(b);

    while(s[block[a]].top() != a)
    {
        tmp.push(s[block[a]].top());
        s[block[a]].pop();
    }

    tmp.push(s[block[a]].top());
    s[block[a]].pop();

    while(!tmp.empty())
    {
        s[block[b]].push(tmp.top());
        block[tmp.top()] = block[b];
        tmp.pop();
    }
}

void pileOver(int a, int b)
{
    while(s[block[a]].top() != a)
    {
        tmp.push(s[block[a]].top());
        s[block[a]].pop();
    }

    tmp.push(s[block[a]].top());
    s[block[a]].pop();

    while(!tmp.empty())
    {
        s[block[b]].push(tmp.top());
        block[tmp.top()] = block[b];
        tmp.pop();
    }
}

int main(int argc, char const *argv[])
{
    int n, a, b;
    char cmd1[10], cmd2[10];

    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
        {
            s[i].push(i);
            block[i] = i;
        }

        while(cin >> cmd1)
        {
            if(cmd1[0] == 'q')
                break;
            cin >> a >> cmd2 >> b;

            if(a != b && block[a] != block[b])
            {
                if(cmd1[0] == 'm')
                {
                    if(cmd2[1] == 'n')
                        moveOnto(a,b);
                    else
                        moveOver(a,b);
                }
                else
                {
                    if(cmd2[1] == 'n')
                        pileOnto(a,b);
                    else
                        pileOver(a,b);
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            cout << i << ":";
            if(s[i].empty())
                cout << endl;
            else
            {
                while(!s[i].empty())
                {
                    tmp.push(s[i].top());
                    s[i].pop();
                }

                while(!tmp.empty())
                {
                    cout << " " << tmp.top();
                    tmp.pop();
                }
                cout << endl;
            }
        }
    }
    return 0;
}

