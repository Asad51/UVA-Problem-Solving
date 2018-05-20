#include <bits/stdc++.h>
using namespace std;

bool isInvalid(long long a[]){
	if(a[2] >= a[0]+a[1])
		return true;
	return false;
}

bool isEquilateral(long long a[]){
	if(a[0]==a[1] && a[1]==a[2])
		return true;
	return false;
}

bool isIsosceles(long long a[]){
	if(a[0]==a[1] || a[1]==a[2])
		return true;
	return false;
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	for(int i=1; i<=t; i++){
		long long a[3];
		cin>>a[0]>>a[1]>>a[2];
		sort(a, a+3);
		if(isInvalid(a))
			cout<<"Case "<<i<<": Invalid\n";
		else if(isEquilateral(a))
			cout<<"Case "<<i<<": Equilateral\n";
		else if(isIsosceles(a))
			cout<<"Case "<<i<<": Isosceles\n";
		else
			cout<<"Case "<<i<<": Scalene\n";
	}
	return 0;
}
