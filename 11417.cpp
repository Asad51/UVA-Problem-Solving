#include <bits/stdc++.h>
using namespace std;

int findGCD(int n, int m){
	while(m%n != 0){
		int tmp = n;
		n = m%n;
		m = tmp;
	}
	return n;
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); 
	//freopen("out.txt", "w", stdout);
	int gcd[501]={0}, dp[501][501]={{0}};
	gcd[0] = 0;
	for(int k=1; k<501; k++){
		int sum = 0;
		for(int i=1; i<k; i++){
			for(int j=i+1; j<=k; j++){
				sum += findGCD(i, j);
			}
		}
		gcd[k] = sum;
	}

	int n;
	while(cin>>n && n){
		cout<<gcd[n]<<"\n";
	}
	return 0;
}
	