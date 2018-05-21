#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	int n, k, p;
	for(int i=1; i<=t; i++){
		cin>>n>>k>>p;
		int q = (k+p)%n;
		if(!q)
			cout<<"Case "<<i<<": "<<n<<"\n";
		else
			cout<<"Case "<<i<<": "<<q<<"\n";
	}
	return 0;
}
