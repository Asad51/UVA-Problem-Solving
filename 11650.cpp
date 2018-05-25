#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); 
	///freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--){
		int h, m;
		scanf("%d:%d", &h, &m);
		if(h==12)
			h = 0;
		int tim = 720 - (h*60 + m);
		int h1 = tim/60;
		int m1 = tim%60;
		if(!h1)
			h1 = 12;
		printf("%02d:%02d\n", h1, m1);
	}
	return 0;
}
