#include <iostream>
#include <set>
#include <cmath>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	int u, d, w;
	set<int>s;
	while(t--){
		cin>>w;
		while(w--){
			cin>>u>>d;
			s.insert(abs(u-d));
		}
		if(s.size()==1)
			cout<<"yes\n";
		else
			cout<<"no\n";
		if(t)
			cout<<"\n";
		s.clear();
	}
	return 0;
}
