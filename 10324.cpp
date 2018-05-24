#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); 
	//freopen("out.txt", "w", stdout);
	char s[1000001];
	int cs = 0;
	while(gets(s)){
		int q;
		scanf("%d", &q);
		int mx, mn;
		cout<<"Case "<<++cs<<":\n";
		for(int i=0; i<q; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			mx = max(a, b);
			mn = min(a, b);
			bool isSame = true;
			char prev = s[mn];
			for(int j=mn; j<=mx; j++){
				if(prev != s[j]){
					isSame = false;
					break;
				}
				prev = s[j];
			}
			if(isSame)
				printf("Yes\n");
			else
				printf("No\n");
			getchar();
		}
	}
	return 0;
}
