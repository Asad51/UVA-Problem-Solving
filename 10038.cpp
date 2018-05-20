#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int n;
	while(cin>>n){
		if(!n)
			break;
		int arr[n], ab[n-1];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		for(int i=0; i<n-1; i++){
			ab[i] = abs(arr[i]-arr[i+1]);
		}
		int p = n-1;
		sort(ab, ab + p);
		bool isJolly = true;
		for(int i=0; i<n-1; i++){
			if(ab[i] != i+1)
			{
				isJolly = false;
				break;
			}
		}
		if(isJolly)
			cout<<"Jolly\n";
		else
			cout<<"Not jolly\n";
	}
	return 0;
}
