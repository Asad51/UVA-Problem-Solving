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
	set<string>palindrome;
	while(getline(cin, s)){
		for(int i=0; i<s.size(); i++){
			string t = "";
			for(int j=i; j<s.size(); j++){
				t += s[j];
				if(isPalindrome(t))
					palindrome.insert(t);
			}
		}
		cout<<"The string '"<<s<<"' contains "<<palindrome.size()<<" palindromes.\n";
		palindrome.clear();
	}
	return 0;
}
