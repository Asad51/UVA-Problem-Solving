#include <bits/stdc++.h>
using namespace std;

string toLower(string s){
	for(int i=0; i<s.size(); i++){
		if(s[i]>='A' && s[i]<='Z')
			s[i] = s[i] + 32;
	}
	return s;
}

int main(int argc, char const *argv[])
{
	set<string>dict;
	set<string>::iterator it;
	string s = "";
	char ch;
	while(cin>>noskipws>>ch){
		if(isalpha(ch)){
			s += ch;
		}
		else{
			if(s.size()>0)
				dict.insert(toLower(s));
			s = "";
		}
	}
	if(s.size()>0)
		dict.insert(toLower(s));

	for(it=dict.begin(); it!=dict.end(); ++it){
		cout<<*it<<"\n";
	}
	return 0;
}
