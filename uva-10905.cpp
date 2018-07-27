#include <bits/stdc++.h>
using namespace std;

bool comp(string a, string b){
	string x, y;
	x = a + b;
	y = b + a;
	int mx = x.size();
	for(int i=0; i<mx; i++){
		if(x[i]!=y[i])
			return x[i] < y[i];
	}
	return true;
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int n;
	while(cin>>n && n>0){
		string s, st[n];
		for(int i=0; i<n; i++){
			cin>>st[i];
		}

		//cout<<comp("123", "123121");

		sort(st, st + n, comp);
		for(int i = n-1; i>=0; i--)
			cout<<st[i];
		cout<<"\n";
	}
	return 0;
}
