#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	///freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	string s;
	map<char, int>lets;
	map<char, int>::iterator it;
	while(getline(cin, s)){
		int mx = 0;
		for(int i=0; i<s.size(); i++){
			if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
				lets[s[i]]++;
				mx = max(mx, lets[s[i]]);
			}
		}
		for(it=lets.begin(); it!=lets.end(); it++){
			if(it->second == mx)
				printf("%c", it->first);
		}
		printf(" %d\n",mx );
		lets.clear();
	}

	return 0;
}