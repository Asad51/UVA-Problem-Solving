#include "bits/stdc++.h"
using namespace std;

class SettlersOfCatan{
	int mark[26][26];
	int n, m;
	int longestPath;
public:
	SettlersOfCatan(int nn, int mm){
		n = nn;
		m = mm;
		longestPath = 0;
	}

	void resetMark(){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				mark[i][j] = 0;
			}
		}
	}

	void printSolution(){
		cout<<longestPath<<"\n";
	}

	void findLongestPath(vector< vector<int> > adj, int node, int path){
		longestPath = max(longestPath, path);
		for(int i=0; i<adj[node].size(); i++){
			int tmp = adj[node][i];
			if(mark[node][tmp]==0){
				mark[node][tmp] = 1;
				mark[tmp][node] = 1;
				findLongestPath(adj, tmp, path + 1);
				mark[node][tmp] = 0;
				mark[tmp][node] = 0;
			}
		}
	}
};

int main(int argc, char const *argv[])
{
	int n, m;
	vector< vector<int> > adj;
	while(true){
		int u, v;
		cin>>n>>m;
		if(n==0 && m==0)
			break;
		adj.resize(n);
		for(int i=0; i<m; i++){
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		SettlersOfCatan sc(n, m);
		for(int i=0; i<n; i++){
			sc.resetMark();
			sc.findLongestPath(adj, i, 0);
		}
		sc.printSolution();
		adj.clear();
	}	
	return 0;
}
