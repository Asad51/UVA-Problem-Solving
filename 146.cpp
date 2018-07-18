#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	while(cin>>s && s!="#"){
		string t = s;
		sort(t.begin(), t.end());
		next_permutation(s.begin(), s.end());
		if(t==s)
			cout<<"No Successor\n";
		else
			cout<<s<<"\n";
	}
	return 0;
}
