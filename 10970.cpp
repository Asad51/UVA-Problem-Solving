#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int m, n;
	while(scanf("%d %d", &m, &n) != EOF){
		cout<<(n-1) + n*(m-1)<<endl;
	}
	return 0;
}