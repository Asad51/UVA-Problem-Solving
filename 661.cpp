#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); 
	///freopen("out.txt", "w", stdout);
	int n, m, c, cs = 0;
	while(cin>>n>>m>>c){
		if(!n && !m && !c)
			break;
		int isOn[n] = {0};
		int capacity[n];
		for(int i=0; i<n; i++){
			cin>>capacity[i];
		}
		int mx = 0, power = 0;
		bool isBlown = false;
		cout<<"Sequence "<<cs+1<<"\n";
		//cout<<"check\n";
		for(int i=0; i<m; i++){
			int d;
			cin>>d;
			if(isOn[d-1]){
				power -= capacity[d-1];
				isOn[d-1] = 0;
			}
			else{
				power += capacity[d-1];
				isOn[d-1] = 1;
			}
			mx = max(mx, power);
			if(mx>c){
				//cout<<"Fuse was blown.\n";
				isBlown = true;
				//break;
			}
		}
		if(isBlown)
			cout<<"Fuse was blown.\n";
		else{
			cout<<"Fuse was not blown.\n";
			cout<<"Maximal power consumption was "<<mx<<" amperes.\n";
		}
		cout<<"\n";
		cs++;
	}
	return 0;
}
