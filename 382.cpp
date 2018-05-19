#include <bits/stdc++.h>
using namespace std;

int sum(int n){
	int sum = 0;
	for(int i=1; i<=n/2; i++){
		if(n%i==0)
			sum += i;
	}
	return sum;
}

int main(int argc, char const *argv[])
{
 	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	cout<<"PERFECTION OUTPUT\n";
	while(cin>>n){
		if(!n)
			break;
		int s = sum(n);
		if(n==s)
			cout<<setw(5)<<n<<"  PERFECT\n";
		else if(s<n)
			cout<<setw(5)<<n<<"  DEFICIENT\n";
		else
			cout<<setw(5)<<n<<"  ABUNDANT\n";
	}
	cout<<"END OF OUTPUT\n";
	return 0;
}
