#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	for(int i=1; i<=t; i++){
		int n;
		cin>>n;
		int h = 0, l = 0;
		int a[n];
		for(int j=0; j<n; j++)
			cin>>a[j];
		for(int j=0; j<n-1; j++){
			if(a[j+1]>a[j])
				h++;
			if(a[j+1]<a[j])
				l++;
		}
		cout<<"Case "<<i<<": "<<h<<" "<<l<<"\n";
	}
	return 0;
}
