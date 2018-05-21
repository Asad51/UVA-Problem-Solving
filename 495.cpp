#include <bits/stdc++.h>
using namespace std;

long long int fb[5001][500];

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	for(int i=0; i<5001; i++){
		for(int j=0; j<500; j++)
			fb[i][j] = 0;
	}
	fb[0][0] = 0;
	fb[1][0] = 1;
	//printf("check\n");
	for(int i = 2; i<5001; i++){
		for(int j=0; j<500; j++){
			fb[i][j] += fb[i-1][j] + fb[i-2][j];
			if(fb[i][j]>=1000)
			{
				fb[i][j] %= 1000;
				fb[i][j+1]++;
			}
		}
	}
	//printf("check\n");
	int n;
	while(scanf("%d", &n) != EOF){
		cout<<"The Fibonacci number for "<<n<<" is ";
		if(!n){
			printf("0\n");
			continue;
		}
		int i=500;
        while (fb[n][--i]==0);
        printf("%lld",fb[n][i--] );
        while(i>=0)
        	printf("%.3lld",fb[n][i--] );
        printf("\n");
	}

	return 0;
}