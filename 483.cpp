#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s){
	string st = "";
	vector<string>res;
	int sz = s.size();
	for(int i=sz-1; i>=0; i--){
		if(s[i]!=' '){
			st += s[i];
		}
		if(s[i]==' '){
			res.push_back(st);
			res.push_back(" ");
			st = "";
		}
		if(!i){
			res.push_back(st);
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	string s;
	vector<string>res;
	while(getline(cin, s)){
		res = split(s);
		for(int i=res.size()-1; i>=0; i--){
			cout<<res[i];
			//if(i!=0)
				//cout<<" ";
		}
		cout<<"\n";
		res.clear();
	}
	return 0;
}
	