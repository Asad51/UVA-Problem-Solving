#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    string str;
    list<char> text;
    list<char>::iterator it;
    while(getline(cin,str))
    {
        text.clear();
        it = text.begin();
        for(int i = 0; i<str.size(); ++i)
        {
            if(str[i] == '[')
                it = text.begin();
            if(str[i] == ']')
                it = text.end();
            if(str[i] != '[' && str[i] != ']')
                text.insert(it,str[i]);
        }
        for(it = text.begin(); it != text.end(); it++)
            printf("%c",*it);
        printf("\n");
    }
    return 0;
}