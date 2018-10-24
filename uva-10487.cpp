#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	lli n, q, qv, cs = 0;
	while(cin>>n && n){
		lli m = n*(n-1)/2;
		lli a[n], sum[m];
		for(lli i=0; i<n; i++){
			cin>>a[i];
		}

		lli k = 0;
		for(lli i=0; i<n; i++){
			for(lli j=i+1; j<n; j++){
				sum[k++] = a[i]+a[j];
			}
		}
		sort(sum, sum + m);
		cin>>q;
		cout<<"Case "<<++cs<<":\n";
		for(lli i=0; i<q; i++){
			cin>>qv;
			lli mnSum = INT_MAX;
			for(lli j=0; j<m; j++){
				if(abs(qv-sum[j]) < abs(qv-mnSum))
					mnSum = sum[j];
			}
			cout<<"Closest sum to "<<qv<<" is "<<mnSum<<".\n";
		}
	}
	return 0;
}