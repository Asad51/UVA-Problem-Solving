#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main(int argc, char const *argv[])
{
	///freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int n;
	lli sum, mx;
	int cs = 0;
	while(scanf("%d", &n)!=EOF) {
		mx = 0;
	    lli s[n];
	    for(int i=0; i<n; i++)
	    	cin>>s[i];
	    for(int i=0; i<n; i++){
	    	sum = 1;
	    	for(int j=i; j<n; j++){
	    		sum *= s[j];
	    		mx = max(mx, sum);
	    	}
	    }
	    cout<< "Case #" << ++cs <<": The maximum product is "<<mx<<".\n\n";
	}
	return 0;
}
