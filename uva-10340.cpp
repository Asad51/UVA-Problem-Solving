#include <bits/stdc++.h>
using namespace std;

bool checkSequence(string t, string s){
	for(int i=0, j=0; i<t.size() && j<s.size(); i++){
		if(t[i]==s[j])
			j++;
		if(j==s.size())
			return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	string s, t;
	while(cin>>s>>t){
		if(checkSequence(t, s))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
