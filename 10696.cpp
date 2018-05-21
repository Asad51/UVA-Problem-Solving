#include <bits/stdc++.h>
using namespace std;

int f91(int n){
	if(n<=100)
		return f91(f91(n+11));
	return n - 10;
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int n;
	while(cin>>n && n){
		cout<<"f91("<<n<<") = "<<f91(n)<<"\n";
	}
	return 0;
}
