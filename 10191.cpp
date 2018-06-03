#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int n, cs=0;
	while(scanf("%d", &n)!=EOF){
		char ch;
		int h1, m1, h2, m2, start, end;
		int arr[1081];
		for(int i=0; i<=1080; i++){
			arr[i] = 0;
		}
		for(int i=0; i<n; i++){
			scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
			do{
				scanf("%c", &ch);
			}while(ch != '\n');
			start = h1*60 + m1;
			end = h2*60 + m2;
			for(int j = start; j<end; j++){
				arr[j] = 1;
			}
		}
		int longest = 0, s, index=600, nap = 0;
		for(int i=600; i<1080; i++){
			if(arr[i]==0)
				nap++;
			else{
				if(nap>longest){
					longest = nap;
					s = index;
				}
				index = i+1;
				nap = 0;
			}
		}
		if(nap>longest){
			longest = nap;
			s = index;
		}
		
		if(longest<60)
			printf("Day #%d: the longest nap starts at %02d:%02d and will last for %d minutes.\n", ++cs, s/60, s%60, longest);
		else{
			printf("Day #%d: the longest nap starts at %02d:%02d and will last for %d hours and %d minutes.\n", ++cs, s/60, s%60, longest/60, longest%60);
		}
	}
	return 0;
}
