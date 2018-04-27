#include "bits/stdc++.h"
using namespace std;

class knapsack
{
public:
	int max(int a, int b){
		return (a > b) ? a : b;
	}

	void selectCD(int n, int w, int weight[]){
		int i, j;
		int x[n+1][w+1];
		for(i=0; i<=n; ++i){
			for(j=0; j<=w; ++j){
				if(i==0 || j==0)
					x[i][j] = 0;
				else if(weight[i-1]<=j)
					x[i][j] = max(weight[i-1] + x[i-1][j - weight[i-1]], x[i-1][j]);
				else
					x[i][j] = x[i-1][j];
			}
		}
		int k = n, l = w;
		vector<int> v;
		/*for(i=0; i<=n; i++){
			for(j = 0; j<=w; j++ ){
				cout<<x[i][j]<<" ";
			}
			cout<<endl;
		}*/
		for( ; k>0; k--){
			if(x[k][l]!=x[k-1][l]){
				v.push_back(weight[k-1]);
				l = l - weight[k-1];
				//cout<<weight[k]<<" ";
			}
		}
		int sum = 0;
		for(i = v.size()-1; i>=0; i--){
			cout<<v[i]<<" ";
			sum += v[i];
		}
		cout<<"sum:"<<sum<<"\n";
	}

};

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
    cin.tie(NULL);
    int N, numOfTrack;

    while(scanf("%d", &N) != EOF){
        scanf("%d",&numOfTrack);
    	int track[numOfTrack];
    	for(int i=0; i<numOfTrack; i++){
    		scanf("%d", &track[i]);
    	}
    	knapsack c;
    	c.selectCD(numOfTrack, N, track);
    }
    return 0;
}
