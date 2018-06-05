#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t, cs=0;
	scanf("%d", &t);
	while(t--){
		int c, d;
		cin>>c>>d;
		float f, nc;
		f = (9.0/5.0)*c + 32.0;
		f += (float)d;
		nc = (f-32)*(5.0/9.0);
		printf("Case %d: %.2f\n", ++cs, nc);
	}
	return 0;
}
