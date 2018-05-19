#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	string s;
	while(getline(cin, s)){
		if(s[0]=='_')
			continue;
		int c = 0;
		for(int i=s.size()-2, j=0; i>1; i--){
			if(s[i]=='o')
				c += pow(2,j);
			if(s[i]!='.')
				j++;
		}
		printf("%c",c);
	}
	return 0;
}
