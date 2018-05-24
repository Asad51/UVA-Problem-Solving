#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); 
	//freopen("out.txt", "w", stdout);
	int n, cs = 0;
	while(scanf("%d", &n) != EOF){
		if(cs != 0)
			cout<<"\n";
		string names[n];
		map<string, int>gift;
		for(int i=0; i<n; i++){
			cin>>names[i];
			gift.insert(make_pair(names[i], 0));
		}
		for(int i=0; i<n; i++){
			string s;
			int sp, m;
			cin>>s;
			scanf("%d %d", &sp, &m );
			//cout<<s<<sp<<m;
			int tmp = 0;
			if(m==0 || sp==0)
				tmp = 0;
			else
				tmp = sp/m;
			gift[s] -= tmp*m;
			for(int j=0; j<m; j++){
				string f;
				cin>>f;
				gift[f] += tmp;
			}
		}
		for(int i=0; i<n; i++){
			cout<<names[i]<<" "<<gift[names[i]]<<"\n";
		}
		cs++;
		gift.clear();
	}
	return 0;
}
