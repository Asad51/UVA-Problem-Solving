#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	while(t--){
		lli s, d;
		cin>>s>>d; 
		if (s>=d && (s+d)%2 == 0)
        {
            cout<<(s+d)/2<<" "<<(s-d)/2<<"\n";
        }
        else
        	cout<<"impossible\n";
	}
	return 0;
}