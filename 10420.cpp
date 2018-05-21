#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);

    int n;
    cin>>n;
    map<string, int>desh;
    map<string, int>::iterator it;
    while(n--){
    	string s1, s2;
    	cin>>s1;
    	getline(cin, s2);
    	desh[s1]++;
    }
    for(it = desh.begin(); it != desh.end(); it++)
    	cout<< it->first <<" "<< it->second <<"\n";
	return 0;
}