#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main(int argc, char const *argv[])
{
	int n, m;
	while(cin>>n){
		m = pow(10, n/2);
		for(int i=0; i<m; i++){
			for(int j=0; j<m; j++){
				if(pow(i+j, 2) == m*i+j)
					cout<<setfill('0')<<setw(n)<<m*i+j<<"\n";
			}
		}
	}
	return 0;
}
