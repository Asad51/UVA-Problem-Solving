#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int n, m;
	while(scanf("%d %d", &n, &m) !=EOF){
		int q = n^m;
		cout<<q<<"\n";
	}
	return 0;
}
