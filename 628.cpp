#include "bits/stdc++.h"
using namespace std;

class passwords
{
	int n, m;
	vector<string>allpass;
public:
	passwords(int nn, int mm){
		n = nn;
		m = mm;
		allpass.clear();
	}

	void printPasswords(){
		for(int i=0; i<allpass.size(); i++){
			cout<<allpass[i]<<"\n";
		}
		allpass.clear();
	}
	
	void generatePasswords(vector<string> words, string rule, int pos, string s){
		if(pos>=rule.size()){
			allpass.push_back(s);
			return;
		}

		if(rule[pos]=='#'){
			for(int i=0; i<n; i++)
				generatePasswords(words, rule, pos+1, s + words[i]);
		}
		else{
			for(int i=0; i<=9; i++){
				generatePasswords(words, rule, pos+1, s + char(i+48));
			}
		}
	}
	
};

int main(int argc, char const *argv[])
{
	int n,m;
	vector<string>words, rules;
	int i=0;
	string s;
	while(scanf("%d", &n)!=EOF){
		for(int j=0; j<n; j++){
			cin>>s;
			words.push_back(s);
		}

		cin>>m;
		for(int j=0; j<m; j++){
			cin>>s;
			rules.push_back(s);
		}

		passwords p(n, m);
		cout<<"--\n";
		for(int j = 0; j<m; j++){
			p.generatePasswords(words, rules[j], 0, "");
			p.printPasswords();
		}
		words.clear();
		rules.clear();
	}
	return 0;
}
