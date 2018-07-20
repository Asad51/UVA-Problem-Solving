#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
	int g;
	while(cin>>g && g){
		string s, t="";
		cin>>s;
		int n = ceil(s.size()/(float)g);
		for (int i = 0, j = 1; i < s.size(); ++i, j++)
		{
			t += s[i];
			if(j==n){
				reverse(t.begin(), t.end());
				cout<<t;
				t = "";
				j = 0;
			}
		}
 		reverse(t.begin(), t.end());
		cout<<t<<"\n";
	}
	return 0;
}
