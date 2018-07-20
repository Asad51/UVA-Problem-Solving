#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int n;
	while(scanf("%d", &n) && n){
		int arr[n][n], checkRow[n] = {0}, checkCol[n]={0};
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				scanf("%d", &arr[i][j]);
				if(arr[i][j]){
					checkRow[i]++;
					checkCol[j]++;
				}
			}
		}
		int errRow = 0, errCol = 0, errRowIndex, errColIndex;
		for(int i=0; i<n; i++){
			if(checkRow[i]%2==1){
				errRowIndex = i;
				errRow++;
			}
			if(checkCol[i]%2==1){
				errColIndex = i;
				errCol++;
			}
		}

		if(!errRow && !errCol)
			printf("OK\n");
		else if(errRow==1 && errCol==1)
			printf("Change bit (%d,%d)\n", errRowIndex+1, errColIndex+1);
		else
			printf("Corrupt\n");
	}
	return 0;
}
