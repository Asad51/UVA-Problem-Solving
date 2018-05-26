#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string t){
	int l = 0;
	int h = t.size()-1;
	while(l<h){
		if(t[l++] != t[h--])
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	string s;
	while(getline(cin, s)){
		for(int i=0; i<s.size(); i++)
		{
			if(s[i]>='a' && s[i]<='z')
				s[i] = s[i]-32;
		}
		if(s=="DONE")
			break;
		string t = "";
		for(int i=0; i<s.size(); i++){
			if(s[i]>='A' && s[i]<='Z')
				t += s[i];
		}
		if(isPalindrome(t))
			cout<<"You won't be eaten!\n";
		else
			cout<<"Uh oh..\n";
	}
	return 0;
}
