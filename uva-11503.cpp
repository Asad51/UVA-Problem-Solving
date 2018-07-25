#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	freopen("in.txt", "r", stdin); 
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		set<string> persons;
		string p1, p2;
		while(n--){
			cin>>p1>>p2;
			persons.insert(p1);
			persons.insert(p2);
			cout<<persons.size()<<"\n";
		}
		persons.clear();
	}
	return 0;
}
