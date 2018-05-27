#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	while(n--){
		char str[11];
		scanf("%s", str);
		int sz = strlen(str);
		sort(str, str+sz);
		do{
			printf("%s\n", str );
		} while(next_permutation(str, str+sz));
		printf("\n");
	}
	return 0;
}
