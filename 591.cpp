#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int n;
	int s = 0;
	while(cin>>n){
		if(!n)
			break;
		int st[n];
		int avg = 0;
		for(int i=0; i<n; i++){
			cin>>st[i];
			avg += st[i];
		}
		avg /= n;
		int moves = 0;
		for(int i=0; i<n; i++){
			moves += abs(st[i]-avg);
		}
		cout<<"Set #"<<++s<<"\n";
		cout<<"The minimum number of moves is "<<moves/2<<".\n";
		cout<<"\n";
	}
	return 0;
}
