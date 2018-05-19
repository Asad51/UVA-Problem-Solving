#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF){
		int sum = n;
		while(n>=k){
			sum += n/k;
			n = n%k + n/k;
		}
		cout<<sum<<"\n";
	}
	return 0;
}
