#include<bits/stdc++.h>
using namespace std;

char toUpper(char ch){
    if(ch>='a' && ch<='z')
        return ch-32;
    return ch;
}

int main()
{
    string s;
    int n,i,j;
    int arr[26] = {0};
    cin>>n;
    getchar();
    for(i=0; i<n; i++)
    {
        getline(cin,s);
        for(j=0; j<s.size(); j++)
        {
            if(s[j]>='A' && s[j]<='Z')
                arr[s[j]-65]++;
            else if(s[j]>='a' && s[j]<='z'){
                char ch = toUpper(s[j]);
                arr[ch-65]++;
            }
        }
    }

    int mark[26] = {0};
    for(i=0; i<26; i++){
        int index = -1;
        int mx = 0;
        for(j=0; j<26; j++){
            if(arr[j]>mx && !mark[j]){
                mx = arr[j];
                index = j;
            }
        }
        if(mx){
            printf("%c %d\n", 'A'+index, mx );
            mark[index] = 1;
        }
    }
    return 0;
}
