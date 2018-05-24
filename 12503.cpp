#include <bits/stdc++.h>
using namespace std;

int execute(string s, int p){
	if(s=="LEFT")
		p--;
	else
		p++;
	return p;
}

int split(string s){
	string a = "";
	for(int i=0; i<s.size(); i++){
		if(s[i] == ' ')
			a = "";
		else
			a += s[i];
	}
	int n = 0;
	for(int i = a.size()-1, j=1; i>=0; i--, j*=10){
		int t = a[i]-48;
		n += t*j;
	}
	return n;
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out1.txt", "w", stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string ins[n], s;
		int pos[n] = {0};
		int p = 0;
		getchar();
		for(int i=0; i<n; i++){
			getline(cin, ins[i]);
			if(ins[i]=="LEFT"){
				p--;
				pos[i] = i;
			}
			else if(ins[i]=="RIGHT"){
				p++;
				pos[i] = i;
			}
			else{
				int tmp = pos[split(ins[i])-1];
				p = execute(ins[tmp], p);
				pos[i] = tmp;
			}
		}
		cout<<p<<"\n";
	}
	return 0;
}
	