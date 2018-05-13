#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t, d;
	cin>>t;
	string s;
	long long sum = 0;
	while(t--){
		cin>>s;
		if(s=="donate"){
			cin>>d;
			sum += d;
		}
		else
			cout<<sum<<"\n";
	}
	return 0;
}
