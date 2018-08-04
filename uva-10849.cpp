#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(int argc, char const *argv[])
{
	lli n, m, c;
	while(cin>>n>>m && n && m){
		map<lli, lli>cds;
		map<lli, lli>::iterator it;
		for(lli i=0; i<n; i++){
			cin>>c;
			cds[c]++;
		}
		for(lli i=0; i<m; i++){
			cin>>c;
			cds[c]++;
		}
		lli cnt = 0;
		for(it=cds.begin(); it!=cds.end(); ++it){
			if(it->second == 2)
				cnt++;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
