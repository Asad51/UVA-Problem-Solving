#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); 
	//freopen("out.txt", "w", stdout);
	int press[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
	int t;
	scanf("%d", &t);
	getchar();
	for(int i=1; i<=t; i++){
		char ch[102];
		int pressed = 0;
		gets(ch);
		for(int j=0; j<strlen(ch); j++){
			if(ch[j]==' ')
				pressed++;
			if(ch[j]>='a' && ch[j]<='z')
				pressed += press[ch[j]-'a'];
		}
		printf("Case #%d: %d\n", i, pressed);
	}
	return 0;
}
