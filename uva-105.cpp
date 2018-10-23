#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int l, h, r, mx = -1, mn = 10005;
	int a[10002] = {0};
	while(cin>>l>>h>>r){
		for(int i=l; i<r; i++){
			a[i] = max(a[i], h);
			mx = max(mx, r);
			mn = min(mn, l);
		}
	}
	for(int j=mn; j<=mx; j++){
		if(a[j]!=a[j-1]){
			cout<<j<<" "<<a[j];
			if(j!=mx)
				cout<<" ";
		}
	}
	cout<<"\n";
	
	return 0;
}