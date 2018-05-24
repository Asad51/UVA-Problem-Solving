#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); 
	//freopen("out.txt", "w", stdout);
	int l;
	while(cin>>l && l){
		getchar();
		char road[l];
		gets(road);
		int mn = 2000001, dist = 0;
		int prev = 0;
		for(int i=0; i<l; i++){
			if(road[i]=='Z'){
				mn = 0;
				break;
			}
			else if(road[i]=='.'){
				dist++;
			}
			else if(road[prev]!=road[i] && road[prev]!='.'){
				dist++;
				mn = min(mn, dist);
				dist = 0;
				prev = i;
			}
			else{
				dist = 0;
				prev = i;
			}
		}
		cout<<mn<<"\n";
	}
	return 0;
}
