#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); 
	//freopen("out.txt", "w", stdout);
	int n, l = 0, h = 11;
	while(cin>>n && n){
		string s1, s2;
		cin>>s1>>s2;
		string comment = s1+" "+s2;
		if(comment=="right on"){
			if(l>=n || h<=n)
				cout<<"Stan is dishonest\n";
			else
				cout<<"Stan may be honest\n";
			l = 0;
			h = 11;
		}
		else if(comment=="too high"){
			h = min(h, n);
		}
		else{
			l = max(l, n);
		}
	}
	return 0;
}