#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main(int argc, char const *argv[])
{
	map<string, lli> dict;
	map<string, lli>:: iterator it;
	lli n, m, d;
	string s, st;
	cin>>n>>m;
	for(lli i=0; i<n; i++){
		cin>>s>>d;
		dict.insert(make_pair(s, d));
	}

	for(int i=0; i<m; i++){
		lli total = 0;
		while(cin>>st){
			if(st==".")
				break;
			total += dict[st];
		}
		cout<<total<<"\n";
	}
	return 0;
}
	