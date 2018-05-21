#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int a, b;
	while(cin>>a>>b){
		if(!a && !b)
			break;
		int c = 0;
		for(int i=a; i<=b; i++){
			double sq = sqrt(i);
			if(sq == (int)sq)
				c++;
		}
		cout<<c<<"\n";
	}
	return 0;
}
