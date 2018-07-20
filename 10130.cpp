#include "bits/stdc++.h"
using namespace std;

class knapsack{
public:
    int max(int a, int b){
		    return (a>b)? a: b;
	  }
	  int findMaxValue(int n, int w, int p[], int wt[]){
		    int i, j;
		    int x[n+1][w+1] = {{0}};
		    for(i = 0; i<=n; i++){
			      for(j = 0; j<=w; j++){
				        if(i==0 || j==0)
					          x[i][j] = 0;
				        else if(wt[i-1]<=j)
					         x[i][j] = max(p[i-1] + x[i-1][j-wt[i-1]], x[i-1][j]);
				        else
					         x[i][j] = x[i-1][j];
			      }
		    }
		    return x[n][w];
	  }
};

int main(int argc, char const *argv[])
{
	  ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    knapsack sack;
  	int T;
  	cin>>T;
  	while(T--){
  		  int N;
  		  cin>>N;
  		  int P[N], W[N];
  		  for(int i=0; i<N; ++i){
  			    cin>>P[i]>>W[i];
  		  }

  		  int G;
  		  cin>>G;
  		  int w;
  		  int total = 0;
  		  for(int i=0; i<G; i++){
  			    cin>>w;
  			    total += sack.findMaxValue(N, w, P, W);
  		  }
  		  cout<<total<<"\n";
  	}
	  return 0;
}