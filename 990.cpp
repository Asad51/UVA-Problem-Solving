#include <bits/stdc++.h>
using namespace std;
#define MX 31;

class knapsack
{
	int maxCost, n, w;
	vector<pair<int, int> >res;
public:
	knapsack(int cost, int nn, int ww){
		maxCost = cost;
		n = nn;
		w = ww;
	}

	void findMaxGold(int cost[], int coins[]){
		int arr[n+1][maxCost+1] = {{0}};
		for(int i=0; i<=n; i++){
			for(int j=0; j<=maxCost; j++){
				if(!i || !j)
					arr[i][j] = 0;
				else if(cost[i-1]<=j){
					arr[i][j] = max(arr[i-1][j], coins[i-1] + arr[i-1][j-cost[i-1]]);
				}
				else
					arr[i][j] = arr[i-1][j];
			}
		}

		int i = n, j = maxCost;
		while(i>0){
			//cout<<i<<":"<<j<<endl;
			if(arr[i][j] == arr[i-1][j])
				i--;
			else{
				res.push_back(make_pair(cost[i-1], coins[i-1]));
				j -= cost[i-1];
				i--;
			}
		}
		cout<<arr[n][maxCost]<<"\n";
		cout<<res.size()<<"\n";
		for(i = res.size()-1; i>=0; i--)
			cout<< res[i].first/(3*w) <<" "<< res[i].second<<"\n";
		//cout<<"\n";
		res.clear();
	}
	
};

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int t, w, c=0;
	while(scanf("%d %d", &t, &w) != EOF){
		if(c!=0)
			cout<<"\n";
		int n;
		scanf("%d", &n);
		int cost[n]={0}, coins[n]={0};
		int d, v;
		for(int i=0; i<n; i++){
			cin>>d>>v;
			cost[i] = 3*w*d;
			coins[i] = v;
		}
		knapsack sack(t, n, w);
		sack.findMaxGold(cost, coins);
		c++;
	}
	return 0;
}
	