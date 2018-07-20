#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	long long int n, arr[10001], i=0;
	while(scanf("%Ld", &n) != EOF){
		int j=i-1;
		for(; j>=0; j--){
			if(arr[j]>n){
				arr[j+1] = arr[j];
			}
			else
				break;
		}
		arr[j+1] = n;
		int index;
		if((i+1)%2==1){
			index = (i+1)/2;
			printf("%Ld\n", arr[index]);
		}
		else{
			index = i/2;
			printf("%Ld\n", (arr[index]+arr[index+1])/2);
		}
		i++;
	}
	return 0;
}
