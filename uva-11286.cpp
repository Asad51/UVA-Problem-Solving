#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, c;
	map<int, vector<int>>frosh;
	map<vector<int>, int>popularity;
	vector<int>cr;
	map<vector<int>, int>:: iterator it;
	while(cin>>n && n){
		int mx = 0;
		for(int i=0; i<n; i++)
		{
			cr.clear();
			for(int j=0; j<5; j++){
				cin>>c;
				cr.push_back(c);
			}
			sort(cr.begin(), cr.end());
			frosh.insert(make_pair(i, cr));
			popularity[cr]++;
			mx = max(mx, popularity[cr]);
		}
		
		int cnt = 0;
		for(int i=0; i<n; i++){
			if(popularity[frosh[i]] == mx)
				cnt++;
			//cout<<popularity[frosh[i]]<<endl;
		}
		cout<<cnt<<"\n";
		popularity.clear();
		frosh.clear();
	}
	return 0;
}
