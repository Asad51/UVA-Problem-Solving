#include "bits/stdc++.h"
using namespace std;

class knapsack
{
	int total;
public:
	knapsack(){
		total = 0;
	}
	int minDiff(int n, int coins[]){
		int i, j, mind = INT_MAX;
		for(i=0; i<n; i++)
			total += coins[i];

		int x[n+1][total+1];
		for(i=0; i<=n; ++i){
			for(j=0; j<=total; ++j){
				if(i==0 || j==0)
					x[i][j] = 0;
				else if(coins[i-1]<=j)
					x[i][j] = max(coins[i-1] + x[i-1][j - coins[i-1]], x[i-1][j]);
				else
					x[i][j] = x[i-1][j];
			}
		}
		int l = total/2;
		mind = abs(x[n][total] - 2*x[n][l]);
		return mind;
	}
};

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
    cin.tie(NULL);
    int T;
    cin>>T;

    while(T--){
    	int n;
    	cin>>n;
    	int coins[n];
    	for(int i=0; i<n; i++){
    		cin>>coins[i];
    	}
    	knapsack c;
    	cout<<c.minDiff(n, coins)<<"\n";
    }
    return 0;
}
