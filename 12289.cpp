#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	string s;
	cin>>t;
	while (t--) {
		cin>>s;
		if (s.size() > 3)
			cout<<"3\n";
		else if((s[0]=='o' && s[1]=='n')|| 
			(s[0]=='o' && s[1]=='e')||
          	(s[1]=='n' && s[2]=='e')||
          	(s[0]=='o' && s[2]=='e')||
          	(s[0]=='o' && s[2]=='n'))
          	cout<<"1\n";
        else
         	cout<<"2\n";
	}

	return 0;
}