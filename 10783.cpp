#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	///freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int t;
	cin>>t;
	int c = 0;
	while(t--){
		int a, b;
		cin>>a>>b;
		int sum = 0;
		for(int i = a; i<=b; i++){
			if(i%2==1)
				sum += i;
		}
		cout<<"Case "<<++c<<": "<<sum<<"\n";
	}
	return 0;
}
	