#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	///freopen("in.txt", "r", stdin); 
	///freopen("out.txt", "w", stdout);
    int t;
    cin>>t;
    vector< pair<string, int> > urls;
    for(int i=1; i<=t; i++){
    	string s;
    	int n, mx = 0;
    	for(int j=0; j<10; j++){
    		cin>>s>>n;
    		urls.push_back(make_pair(s, n));
    		mx = max(mx, n);
    	}
    	cout<<"Case #"<<i<<":\n";
    	for(int j=0; j<10; j++){
    		if(urls[j].second == mx)
    			cout<<urls[j].first<<"\n";
    	}
    	urls.clear();
    }
	return 0;
}