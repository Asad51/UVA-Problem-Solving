#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	for(int i = 1; i<=t; i++){
		int numOfCalls, mile = 0, juice = 0;
		cin>>numOfCalls;
		for(int j=0; j<numOfCalls; j++){
			int c;
			cin>>c;
			mile += (c/30 + 1)*10;
			juice += (c/60 + 1)*15;
		}
		cout<<"Case "<<i<<": ";
		if(mile==juice)
			cout<<"Mile Juice "<<mile<<"\n";
		else if(mile<juice)
			cout<<"Mile "<<mile<<"\n";
		else
			cout<<"Juice "<<juice<<"\n";
	}
	return 0;
}
