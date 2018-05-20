#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int n, m;
	int f = 0;
	while(cin>>n>>m){
		if(!n && !m)
			break;
		char field[n][m];
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++)
				cin>>field[i][j];
		}
		for(int i=0; i<n; i++){
			int c = 0;
			for(int j=0; j<m; j++){
				if(field[i][j]=='*')
					continue;
				if(i>0){
					if(j>0 && field[i-1][j-1]=='*')
						c++;
					if(field[i-1][j]=='*')
						c++;
					if(j<m-1 && field[i-1][j+1]=='*')
						c++;
				}
				if(i<n-1){
					if(j>0 && field[i+1][j-1]=='*')
						c++;
					if(field[i+1][j]=='*')
						c++;
					if(j<m-1 && field[i+1][j+1]=='*')
						c++;
				}
				if(j>0 && field[i][j-1]=='*')
					c++;
				if(j<m-1 && field[i][j+1]=='*')
					c++;
				field[i][j] = c+48;
				c = 0;
			}
		}
		if(f!=0)
			cout<<"\n";
		cout<<"Field #"<<++f<<":\n";
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++)
				cout<<field[i][j];
			cout<<"\n";
		}
	}
	return 0;
}
