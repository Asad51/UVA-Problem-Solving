#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	//freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	while(t--){
		int n, s;
		cin>>n;
		map<int, int>snow;
		int mx = 0, cnt = 0, dup = 0;
		for(int i=1; i<=n; i++){
			cin>>s;
			if(snow[s])
			{
				dup = max(dup, snow[s]);
			}
			mx = max(mx, i - dup);
			snow[s] = i;
			//cout<<mx<<endl;
		}
		cout<<mx<<"\n";
	}
	return 0;
}
