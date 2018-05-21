#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	long long int sum, x;
	while(scanf("%lld", &x) != EOF){
		sum = (x*x*(x+1)*(x+1))/4;
		printf("%lld\n", sum );
	}
	return 0;
}
	