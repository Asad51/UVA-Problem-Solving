#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n && n){
		int top = 1, down = 6, east = 4, west = 3, north=2, south=5;
		string command;
		for(int i=0; i<n; i++){
			cin>>command;
			int tmp;
			if(command=="north"){
				tmp = top;
				top = south;
				south = down;
				down = north;
				north = tmp;
			}
			else if(command=="south"){
				tmp = top;
				top = north;
				north = down;
				down = south;
				south = tmp;
			}
			else if(command=="west"){
				tmp = top;
				top = east;
				east = down;
				down = west;
				west = tmp;
			}
			else{
				tmp = top;
				top = west;
				west = down;
				down = east;
				east = tmp;
			}
		}
		cout<<top<<"\n";
	}
	return 0;
}
