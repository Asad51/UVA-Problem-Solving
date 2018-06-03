#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    int r,i,j,stroke;
    char ch;
    string s;
    string g;
    while(cin>>r)
    {
        stroke = 0;
        if(r==-1)
            break;
        cin>>s>>g;
        string guess = "";
        for(int i=0; i<g.size(); i++){
            if(guess.find(g[i]) != string::npos)
                continue;
            guess += g[i];
        }
        //cout<<guess<<endl;
        for(int i = 0; i<guess.size(); ++i){
            if(s.find(guess[i]) != string::npos){
                s.erase(remove(s.begin(), s.end(), guess[i]), s.end());
            }
            else{
                stroke++;
            }
            if(s=="" || stroke==7){
                break;
            }
        }
        if(stroke==7)
            cout<<"Round "<<r<<"\nYou lose.\n";
        else if(s=="")
            cout<<"Round "<<r<<"\nYou win.\n";
        else
            cout<<"Round "<<r<<"\nYou chickened out.\n";
    }
    return 0;
}
