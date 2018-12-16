#include <bits/stdc++.h>
using namespace std;

char board[4][4];

bool canPlace(int i, int j, int n){
	if(board[i][j] == 'X' || board[i][j]=='Y')
		return false;
	for(int k = i+1; k<n && board[k][j] != 'X'; k++){
		if(board[k][j] == 'Y')
			return false;
	}

	for(int k = i-1; k>=0 && board[k][j] != 'X'; k--){
		if(board[k][j] == 'Y')
			return false;
	}

	for(int k = j+1; k<n && board[i][k]!='X'; k++){
		if(board[i][k] == 'Y')
			return false;
	}

	for(int k = j-1; k>=0 && board[i][k]!='X'; k--){
		if(board[i][k] == 'Y')
			return false;
	}
	return true;
}

int findMaxRooks(int n){
	int mx = 0;
	for(int i = 0; i<n; i++){
		for(int j=0; j<n; j++){
			if(canPlace(i, j, n)){
				board[i][j] = 'Y';
				int m = 1 + findMaxRooks(n);
				mx = max(mx, m);
				board[i][j] = '.';
			}
		}
	}
	return mx;
}

int main(int argc, char const *argv[])
{
	int n, m;
	while(cin>>n && n){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>board[i][j];
			}
		}
		
		m = findMaxRooks(n);
		
		cout<<m<<endl;
	}
	return 0;
}
