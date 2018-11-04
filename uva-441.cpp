#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

class lotto
{
	lli s[13], ans[6], n;
public:
	lotto(lli n, lli s[]){
		this->n = n;
		for(lli i=0; i<n; i++){
			this->s[i] = s[i];
		}
	}
	
	void solve(lli m, lli i){
		if(m == 6) {
			printf("%d", ans[0]);
        	for(i = 1; i < 6; i++)
            	printf(" %d", ans[i]);
        	printf("\n");
        	return;
    	}
    	for(; i < n; i++)
        	ans[m] = s[i], solve(m+1, i+1);
	}
};

int main(int argc, char const *argv[])
{
	lli n, cs=0;
	while(cin>>n && n) {
		lli s[n];
	    if(cs)
	    	printf("\n");
	    for(lli i=0; i<n; i++)
	    	cin>>s[i];
	    lotto lt(n, s);
	    lt.solve(0, 0);
	    cs++;
	}
	return 0;
}