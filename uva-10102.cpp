#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int m;
	while(cin>>m){
		char grid[m][m];
		vector<pair<int, int> > ones, threes;
		for(int i=0; i<m; i++){
			for(int j=0; j<m; j++){
				cin>>grid[i][j];
				if(grid[i][j]=='1')
					ones.push_back(make_pair(i, j));
				if(grid[i][j]=='3')
					threes.push_back(make_pair(i, j));
			}
		}

		int mx = -1, mn;
		for(int i=0; i<ones.size(); i++){
			mn = INT_MAX;
			for(int j=0; j<threes.size(); j++){
				mn = min(mn, abs(ones[i].first - threes[j].first) + abs(ones[i].second - threes[j].second));
				//cout<<ones[i].first << " "<<ones[i].second <<"  "<<threes[j].first <<" "<<threes[j].second<<endl;
			}
			mx = max(mx, mn);
		}
		cout<<mx<<"\n";
	}
	return 0;
}
