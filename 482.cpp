/**
while(t--)
{
    getchar();
    int idx[5000], n = 1, i = 1;
    string x[5000];
    getline(cin, line);
    stringstream sin;
    sin << line;
    while(sin >> idx[n])
        n++;
    getline(cin, line);
    sin.clear();
    sin << line;
    while(sin >> x[idx[i]])
        i++;
    for(i = 1; i < n; i++)
        cout << x[i] << endl;
    if(t)
        puts("");
}
*/


#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        getchar();
        vector<int>index;
        vector<string>nums;
        map<int, string>mp;
        map<int, string>::iterator it;
        int idx;
        string s, s1;
        int i = 0;
        
        getline(cin, s);
        //getchar();
        getline(cin, s1);

        int num = 0;
        for(i = 0; i<s.size(); i++){
            if(s[i]!=' '){
                num += num*10 + s[i]-48;
            }
            if(s[i]==' ' || i==s.size()-1){
                index.push_back(num);
                //cout<<num<<endl;
                num = 0;
            }
        }

        string tm = "";
        //cout<<s1<<endl;
        for(int j=0; j<s1.size(); j++){
            if(s1[j]!=' '){
                tm += s1[j];
            }
            if(s1[j]==' ' || j==s1.size()-1){
                nums.push_back(tm);
                //cout<<tm<<endl;
                tm = "";
            }
        }

        for(int j=0; j<nums.size(); j++){
            mp.insert(make_pair(index[j], nums[j]));
        }

        for(it=mp.begin(); it!=mp.end(); ++it){
            cout<< it->second <<endl;
        }

        mp.clear();
        index.clear();
        nums.clear();

        if(t!=0)
            cout<<"\n";
    }
    return 0;
}
