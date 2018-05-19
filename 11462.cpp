#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	while(scanf("%d", &n)){
		if(!n)
			break;
		int arr[n];
		for(int i=0; i<n; i++){
			scanf("%d", &arr[i]);
		}
		sort(arr, arr+n);
		for(int i=0; i<n; i++){
			if(i!=0)
				printf(" ");
			printf("%d",arr[i] );
		}
		printf("\n");
	}
	return 0;
}
