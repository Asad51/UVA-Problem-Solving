#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	///freopen("in.txt", "r", stdin); 
	//freopen("out.txt", "w", stdout);
	int n, p, cs = 0;
	while(cin>>n>>p){
		if(!n && !p)
			break;
		string requirements[n];
		map< string, double >compliance, price;
		map<string, double>:: iterator it;
		vector< pair<double, string> >res;
		double mx = 0.0;
		getchar();
		for(int i=0; i<n; i++){
			getline(cin, requirements[i]);
		}
		for(int i=0; i<p; i++){
			string name;
			getline(cin, name);
			int r;
			double d;
			cin>>d>>r;
			getchar();
			for(int j=0; j<r; j++){
				string s;
				getline(cin, s);
			}
			double cmp = (double)r/(double)n;
			compliance.insert(make_pair(name, cmp));
			price.insert(make_pair(name, d));
			mx = max(cmp, mx);
		}
		int cnt = 0;
		for(it = compliance.begin(); it!=compliance.end(); ++it)
		{
			if(it->second == mx){
				res.push_back(make_pair(price[it->first], it->first));
				cnt++;
			}
		}
		if(cs!=0)
			cout<<"\n";
		cout<<"RFP #"<<++cs<<"\n";
		sort(res.begin(), res.end());
		cout<<res[0].second<<"\n";

		compliance.clear();
		price.clear();
		res.clear();
	}
	return 0;
}
