#include <bits/stdc++.h>
using namespace std;

bool compare(char a, char b){
	int diff = abs(a-b);
	if(diff==32)
		return a<b;
	return tolower(a)<tolower(b);
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	while(n--){
		char str[1000];
		scanf("%s", str);
		int sz = strlen(str);
		sort(str, str+sz, compare);
		//cout<<str<<endl;
		do{
			printf("%s\n", str );
		} while(next_permutation(str, str+sz, compare));
		//printf("\n");
	}
	return 0;
}
