#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string v[26] = {"", "1", "2", "3", "", "1", "2", "", "", "2", "2", "4", "5", "5", "", "1", "2", "6", "2", "3", "", "1", "", "2", "", "2"};
	string s;
	while(cin>>s){
		cout<<v[s[0]-'A'];
		for(int i=1; i<s.size(); i++){
			string s1 = v[s[i]-'A'];
			string s2 = v[s[i-1]-'A'];
			if(s1==s2)
				continue;
			cout<<s1;
		}
		cout<<"\n";
	}
	return 0;
}	