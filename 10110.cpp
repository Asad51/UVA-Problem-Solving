#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	///freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);

	unsigned int n, x;
	while(cin>>n && n){
		x = sqrt(n);
		if(x*x == n)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	return 0;
}
	