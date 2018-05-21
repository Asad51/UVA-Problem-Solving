#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int c;
	cin>>c;
	while(c--){
		int n;
		cin>>n;
		int st[n];
		int total = 0;
		for(int i=0; i<n; i++){
			cin>>st[i];
			total += st[i];
		}
		double avg = (double)total / (double)n;
		int cnt = 0;
		for(int i=0; i<n; i++){
			if(st[i]>avg)
				cnt++;
		}
		double percent = (double)cnt / (double)n;
		cout<<setprecision(3)<<fixed<<percent*100.0<<'%'<<"\n";
	}
	return 0;
}
